/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_detection.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:47:16 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 17:57:44 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	get_obj_data(t_vector2d direct, t_sprites_data *sprite,
	char item)
{
	char	direction;

	*sprite = get_sprite_data(item);
	direction = MOVE_DOWN;
	if (direct.y > 0)
		direction = MOVE_UP;
	if (direct.x < 0)
		direction = MOVE_RIGHT;
	if (direct.x > 0)
		direction = MOVE_LEFT;
	return (direction);
}

int	get_start_point(char direction, t_vector2d loc, char col,
	t_sprites_data sprite)
{
	int	offset;
	int	cell;

	offset = 0;
	cell = loc.x;
	if (direction == MOVE_UP || direction == MOVE_DOWN)
	{
		while (g_gamedata.map.map[loc.y][cell] == col &&
			cell < g_gamedata.map.width)
				cell = loc.x + (++offset);
		cell = cell - (sprite.width / 2);
	}
	else if (direction == MOVE_LEFT || direction == MOVE_RIGHT)
	{
		cell = loc.y;
		while (g_gamedata.map.map[cell][loc.x] == col
			&& cell < g_gamedata.map.height)
		{
			offset++;
			cell = loc.y + offset;
		}
		cell = cell - (sprite.height / 2);
	}
	return (cell);
}

t_vector2d	get_obj_loc_v(int center, t_vector2d loc, char item, char direct)
{
	int	offset;
	int	cell;

	offset = 0;
	cell = loc.y;
	while (g_gamedata.map.map[cell][center] != item)
	{
		if (g_gamedata.map.map[cell][center + 1] == item)
			return (create_vector2d(cell, center + 1));
		if (g_gamedata.map.map[cell][center - 1] == item)
			return (create_vector2d(cell, center - 1));
		if (direct == MOVE_UP)
			offset--;
		else if (direct == MOVE_DOWN)
			offset++;
		cell = loc.y + offset;
		if (cell < 0 || cell >= g_gamedata.map.height)
		{
			cell = loc.y;
			break ;
		}
	}
	return (create_vector2d(cell, center));
}

t_vector2d	get_obj_loc_h(int center, t_vector2d loc, char item, char direct)
{
	int	offset;
	int	cell;

	offset = 0;
	cell = loc.x;
	while (g_gamedata.map.map[center][cell] != item)
	{
		if (g_gamedata.map.map[center + 1][cell] == item)
			return (create_vector2d(center + 1, cell));
		if (g_gamedata.map.map[center - 1][cell] == item)
			return (create_vector2d(center - 1, cell));
		if (direct == MOVE_LEFT)
			offset--;
		else if (direct == MOVE_RIGHT)
			offset++;
		cell = loc.x + offset;
		if (cell < 0 || cell >= g_gamedata.map.width)
		{
			cell = loc.x;
			break ;
		}
	}
	return (create_vector2d(center, cell));
}

t_vector2d	scan_obj_center(char collision, t_vector2d loc,
	t_vector2d direct)
{
	t_sprites_data	sprite;
	char			direction;
	char			item;
	int				center;

	item = WALL;
	if (collision == COLLISION_COLLECT)
		item = COLLECTABLE;
	else if (collision == COLLISION_DOOR)
		item = FINALDOOR;
	else if (collision == COLLISION_ENEMY)
		item = ENEMY;
	direction = get_obj_data(direct, &sprite, item);
	center = get_start_point(direction, loc, collision, sprite);
	if (direction == MOVE_UP || direction == MOVE_DOWN)
		return (get_obj_loc_v(center, loc, item, direction));
	if (direction == MOVE_LEFT || direction == MOVE_RIGHT)
		return (get_obj_loc_h(center, loc, item, direction));
	return (loc);
}
