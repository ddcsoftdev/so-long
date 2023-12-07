/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_validpath.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/26 19:52:37 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 16:27:02 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	is_safe(int y, int x)
{
	if (y < g_gamedata.map.height
		&& y >= WIN_H_OFFSET / 2
		&& x < g_gamedata.map.width
		&& x >= WIN_W_OFFSET / 2
		&& g_gamedata.map.map[y][x] != TEMP_EMPTY
		&& g_gamedata.map.map[y][x] != TEMP_COLLECT
		&& g_gamedata.map.map[y][x] != TEMP_ENEMY
		&& g_gamedata.map.map[y][x] != TEMP_DOOR)
		return (1);
	return (0);
}

int	verify_cell(t_vector2d new_loc)
{
	if (is_safe(new_loc.y, new_loc.x))
	{
		if (g_gamedata.map.map[new_loc.y][new_loc.x] == WALL)
			return (0);
		if (g_gamedata.map.map[new_loc.y][new_loc.x] == TEMP_EMPTY)
			return (0);
		if (g_gamedata.map.map[new_loc.y][new_loc.x] == TEMP_DOOR)
			return (0);
		if (g_gamedata.map.map[new_loc.y][new_loc.x] == COLLECTABLE)
			g_gamedata.map.map[new_loc.y][new_loc.x] = TEMP_COLLECT;
		if (g_gamedata.map.map[new_loc.y][new_loc.x] == ENEMY)
			g_gamedata.map.map[new_loc.y][new_loc.x] = TEMP_ENEMY;
		if (g_gamedata.map.map[new_loc.y][new_loc.x] == FINALDOOR)
			g_gamedata.map.map[new_loc.y][new_loc.x] = TEMP_DOOR;
		if (g_gamedata.map.map[new_loc.y][new_loc.x] == EMPTY)
			g_gamedata.map.map[new_loc.y][new_loc.x] = TEMP_EMPTY;
		return (1);
	}
	return (0);
}

int	recursive_line_search(t_vector2d loc, int increment)
{
	t_vector2d	new_loc;
	t_vector2d	add;
	int			i;

	i = 0;
	add = create_vector2d(increment, 0);
	while (i <= 3)
	{
		if (i == 1)
			add = create_vector2d(-increment, 0);
		if (i == 2)
			add = create_vector2d(0, increment);
		if (i == 3)
			add = create_vector2d(0, -increment);
		new_loc = add_vector(loc, add);
		if (verify_cell(new_loc))
			recursive_line_search(new_loc, increment);
		i++;
	}
	return (0);
}

void	reset_objs(int *collectable, int *door)
{
	int	i;
	int	j;

	i = WIN_H_OFFSET - 1;
	while (++i < g_gamedata.map.height)
	{
		j = WIN_W_OFFSET - 1;
		while (++j < g_gamedata.map.width)
		{
			if (g_gamedata.map.map[i][j] == TEMP_COLLECT)
			{
				*collectable += 1;
				g_gamedata.map.map[i][j] = COLLECTABLE;
			}
			if (g_gamedata.map.map[i][j] == TEMP_ENEMY)
				g_gamedata.map.map[i][j] = ENEMY;
			if (g_gamedata.map.map[i][j] == TEMP_DOOR)
			{
				g_gamedata.map.map[i][j] = FINALDOOR;
				*door += 1;
			}
			if (g_gamedata.map.map[i][j] == TEMP_EMPTY)
				g_gamedata.map.map[i][j] = EMPTY;
		}
	}
}

int	validate_pathway(void)
{
	int	door;
	int	collectable;
	int	total_collect;
	int	increment;

	door = 0;
	collectable = 0;
	total_collect = collectables_left();
	increment = g_gamedata.sprites.player.height;
	recursive_line_search(get_player_location(), increment);
	reset_objs(&collectable, &door);
	if (collectable != collectables_left() || door != 1)
		return (0);
	return (1);
}
