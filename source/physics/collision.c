/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:47:16 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 17:58:28 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	set_collision_loop(t_vector2d vector, int offset_y, int offset_x,
		char collision)
{
	int		backup_y;
	int		backup_x;

	backup_y = offset_y;
	backup_x = offset_x;
	while (offset_y >= -backup_y)
	{
		offset_x = backup_x;
		while (offset_x >= -backup_x)
		{
			if (offset_y == 0 && offset_x == 0)
				offset_x--;
			else
			{
				if ((vector.y + offset_y) < g_gamedata.map.height
					&& (vector.y + offset_y) >= 0
					&& (vector.x + offset_x) < g_gamedata.map.width
					&& (vector.x + offset_x) >= 0)
					g_gamedata.map.map[vector.y + offset_y][vector.x + offset_x]
						= collision;
				offset_x--;
			}
		}
		offset_y--;
	}
}

void	set_collision(t_vector2d vector, t_sprites_data sprite, char collision)
{
	int		offset_y;
	int		offset_x;

	offset_y = sprite.height / 2 - 1;
	offset_x = sprite.width / 2 - 1;
	set_collision_loop(vector, offset_y, offset_x, collision);
}

int	get_collision_result(t_vector2d vector, int offset_y, int offset_x)
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
		return (4);
	return (0);
}

int	check_collision_loop(t_vector2d vector, int offset_y, int offset_x)
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
			collision = get_collision_result(vector, offset_y, offset_x);
			if (collision)
				return (collision);
			offset_x--;
		}
		offset_y--;
	}
	return (0);
}

int	is_item_colliding(t_vector2d vector, char item, char ignore)
{
	t_sprites_data	sprite;
	int				offset_y;
	int				offset_x;	

	sprite = get_sprite_data(item);
	offset_y = (sprite.height / 2) - 1;
	offset_x = (sprite.width / 2) - 1;
	if (ignore == ENEMY)
		ignore = COLLISION_ENEMY;
	return (check_collision_loop(vector, offset_y, offset_x));
}
