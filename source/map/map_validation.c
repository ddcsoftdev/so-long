/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validation.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:52:37 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 15:54:10 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	validate_minobjects(void)
{
	t_vector2d	player;
	t_vector2d	door;

	player = get_player_location();
	door = get_door_location();
	if (is_equal_vector(player, create_vector2d(-1, -1))
		|| is_equal_vector(door, create_vector2d(-1, -1))
		|| collectables_left() <= 0)
		return (0);
	return (1);
}

int	is_valid_shape(char *str, int *width)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (*width == 0)
		*width = i;
	else
	{
		if (*width != i)
			return (0);
		if (i == g_gamedata.map.height)
			return (0);
	}
	return (1);
}

int	validate_char(char c, int i)
{
	if (c == WALL || c == EMPTY || c == PLAYER
		|| c == COLLECTABLE || c == ENEMY
		|| c == FINALDOOR)
	{
		if ((i == 0 || i == g_gamedata.map.width - 1) && c != WALL)
			return (0);
		else
			return (1);
	}
	else
		return (0);
}

int	is_valid_char(char *str, int height)
{
	int	i;

	i = 0;
	if (height == 0 || height == g_gamedata.map.height - 1)
	{
		while (str[i] && str[i] != '\n')
		{
			if (str[i] != WALL)
				return (0);
			i++;
		}
	}
	else
	{
		while (str[i] && str[i] != '\n')
		{
			if (!validate_char(str[i], i))
				return (0);
			i++;
		}
	}
	return (1);
}

int	is_valid_map(char *pathfile)
{
	int		fd;
	char	*str;
	int		i;
	int		w_buffer;

	fd = open(pathfile, O_RDONLY);
	if (fd <= -1)
		return (fd);
	i = 0;
	w_buffer = 0;
	str = get_next_line(fd);
	while (str != '\0')
	{
		if (!is_valid_char(str, i) || !is_valid_shape(str, &w_buffer))
		{
			free_util(str);
			return (0);
		}
		free_util(str);
		str = get_next_line(fd);
		i++;
	}
	close(fd);
	free_util(str);
	return (1);
}
