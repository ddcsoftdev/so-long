/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_generator.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:48:46 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 16:50:01 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	*init_row(int size)
{
	char	*row;
	int		i;

	row = malloc(size + 1);
	if (!row)
		return (row);
	i = -1;
	while (++i < size)
		row[i] = EMPTY;
	row[i] = '\0';
	return (row);
}

void	free_map(void)
{
	int	i;

	i = 0;
	while (i < g_gamedata.map.height)
	{
		if (g_gamedata.map.map[i])
			free(g_gamedata.map.map[i]);
		i++;
	}
	if (g_gamedata.map.map)
		free(g_gamedata.map.map);
	g_gamedata.map.created = 0;
}

void	generate_map(void)
{
	int		i;
	int		width;
	int		height;

	g_gamedata.map.width *= g_gamedata.sprites.wall.width;
	g_gamedata.map.width += (WIN_W_OFFSET * 2);
	g_gamedata.map.height *= g_gamedata.sprites.wall.height;
	g_gamedata.map.height += (WIN_H_OFFSET * 2);
	width = g_gamedata.map.width;
	height = g_gamedata.map.height;
	g_gamedata.map.created = 0;
	g_gamedata.map.map = malloc(sizeof(g_gamedata.map.map) * height);
	if (!g_gamedata.map.map)
		return ;
	i = -1;
	while (++i < height)
	{
		g_gamedata.map.map[i] = init_row(width);
		if (!g_gamedata.map.map[i])
			free_map();
	}
	g_gamedata.map.created = 1;
}
