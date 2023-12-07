/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_read.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 15:29:31 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 18:20:34 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	init_map(char *pathfile)
{
	char	*str;
	int		fd;

	fd = open(pathfile, O_RDONLY);
	if (fd <= -1)
		prompt_error("Map not found");
	g_gamedata.map.width = 0;
	g_gamedata.map.height = 0;
	str = get_next_line(fd);
	if (!str)
		prompt_error("Map empty");
	while (str[g_gamedata.map.width] && str[g_gamedata.map.width] != '\n')
		g_gamedata.map.width++;
	while (str != '\0')
	{
		free_util(str);
		str = get_next_line(fd);
		g_gamedata.map.height++;
	}
	free_util(str);
	close(fd);
	if (!is_valid_map(pathfile))
		return (-1);
	generate_map();
	return (fd);
}

char	*apply_offset_w(char *str)
{
	char	*map_line;
	int		i;
	int		j;
	int		offset;

	offset = g_gamedata.sprites.wall.width;
	map_line = calloc(g_gamedata.map.width, sizeof(map_line));
	if (!map_line)
		return (map_line);
	ft_memset(map_line, '0', g_gamedata.map.width - 1);
	i = WIN_W_OFFSET;
	j = 0;
	while (i < g_gamedata.map.width - WIN_W_OFFSET)
	{
		if (i % offset == 0 && i > WIN_W_OFFSET)
		{
			map_line[i - (offset / 2)] = str[j];
			j++;
		}
		map_line[i] = '0';
		i++;
	}
	map_line[i - (offset / 2)] = str[j];
	return (map_line);
}

void	place_items(void)
{
	int	i;
	int	j;

	i = 0;
	while (i < g_gamedata.map.height)
	{
		j = 0;
		while (j < g_gamedata.map.width)
		{
			if (g_gamedata.map.map[i][j] == WALL
				|| g_gamedata.map.map[i][j] == COLLECTABLE
				|| g_gamedata.map.map[i][j] == FINALDOOR
				|| g_gamedata.map.map[i][j] == PLAYER
				|| g_gamedata.map.map[i][j] == ENEMY)
			{
				place_item(create_vector2d(i, j), g_gamedata.map.map[i][j]);
			}			
			j++;
		}
		i++;
	}
}

int	validate_fd(char *pathfile)
{
	int	fd;

	if (init_map(pathfile) == -1)
		return (-1);
	fd = open(pathfile, O_RDONLY);
	return (fd);
}

int	read_map(char *pathfile)
{
	char	*str;
	int		fd;
	int		h_index;
	int		offset;

	fd = validate_fd(pathfile);
	if (fd <= -1)
		return (fd);
	str = get_next_line(fd);
	offset = g_gamedata.sprites.wall.height;
	h_index = WIN_H_OFFSET;
	while (str != '\0')
	{
		if (g_gamedata.map.map[h_index - (offset / 2)])
			free(g_gamedata.map.map[h_index - (offset / 2)]);
		g_gamedata.map.map[h_index - (offset / 2)] = apply_offset_w(str);
		free_util(str);
		str = get_next_line(fd);
		h_index += g_gamedata.sprites.wall.height;
	}
	free_util(str);
	place_items();
	if (!validate_minobjects() || !validate_pathway())
		return (-1);
	return (fd);
}
