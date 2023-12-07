/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_collision.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 19:45:15 by ddemarco          #+#    #+#             */
/*   Updated: 2023/03/15 18:57:27 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	check_bounds(char direction, int *offset_y, int *offset_x, int bounds)
{
	if (direction == MOVE_DOWN && *offset_y != bounds)
		return (0);
	if (direction == MOVE_UP && *offset_y != -bounds)
		return (0);
	if (direction == MOVE_RIGHT && *offset_x != bounds)
		return (0);
	if (direction == MOVE_LEFT && *offset_x != -bounds)
		return (0);
	if (direction == MOVE_DOWN || direction == MOVE_UP)
	{
		if (*offset_y == bounds)
			*offset_y += 2;
		else
			*offset_y -= 2;
	}
	else if (direction == MOVE_RIGHT || direction == MOVE_LEFT)
	{
		if (*offset_x == bounds)
			*offset_x += 2;
		else
			*offset_x -= 2;
	}
	return (1);
}

int	get_enemy_interaction(t_vector2d vector, int offset_y, int offset_x,
		char direction)
{
	int		bounds;

	bounds = (g_gamedata.sprites.enemy.height / 2) - 1;
	if ((offset_y == bounds || offset_y == -bounds)
		|| (offset_x == bounds || offset_x == -bounds))
	{
		if (!check_bounds(direction, &offset_y, &offset_x, bounds))
			return (0);
		if (g_gamedata.map.map[vector.y + offset_y][vector.x + offset_x]
			== COLLISION_ENEMY)
		{
			if (direction == MOVE_UP)
				return (5);
			if (direction == MOVE_DOWN)
				return (6);
			if (direction == MOVE_LEFT)
				return (7);
			if (direction == MOVE_RIGHT)
				return (8);
		}		
	}
	return (0);
}

int	get_en_collision_result(t_vector2d vector, int offset_y, int offset_x,
		char direc)
{
	if ((vector.y + offset_y) >= g_gamedata.map.height
		|| (vector.y + offset_y) < 0
		|| (vector.x + offset_x) >= g_gamedata.map.width
		|| (vector.x + offset_x) < 0
		|| g_gamedata.map.map[vector.y + offset_y][vector.x + offset_x]
			== COLLISION_WALL)
		return (1);
	if (g_gamedata.map.map[vector.y + offset_y][vector.x + offset_x]
			== COLLISION_COLLECT)
		return (2);
	if (g_gamedata.map.map[vector.y + offset_y][vector.x + offset_x]
			== COLLISION_DOOR)
		return (3);
	if (g_gamedata.map.map[vector.y + offset_y][vector.x + offset_x]
			== COLLISION_ENEMY)
		return (get_enemy_interaction(vector, offset_x, offset_y, direc));
	return (0);
}

int	check_en_collision_loop(t_vector2d vector, int offset_y, int offset_x,
		char direc)
{
	int		backup_y;
	int		backup_x;
	int		collision;

	backup_y = offset_y;
	backup_x = offset_x;
	while (offset_y >= -backup_y)
	{
		offset_x = backup_x;
		while (offset_x >= -backup_x)
		{
			collision = get_en_collision_result(vector, offset_y, offset_x,
					direc);
			if (collision)
				return (collision);
			offset_x--;
		}
		offset_y--;
	}
	return (0);
}

int	is_enemy_colliding(t_vector2d vector, char item, char direc)
{
	t_sprites_data	sprite;
	int				offset_y;
	int				offset_x;	

	sprite = get_sprite_data(item);
	offset_y = (sprite.height / 2) - 1;
	offset_x = (sprite.width / 2) - 1;
	return (check_en_collision_loop(vector, offset_y, offset_x, direc));
}
