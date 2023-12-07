/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision_scan.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:47:16 by ddemarco          #+#    #+#             */
/*   Updated: 2023/03/01 16:30:42 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	get_coll_result(t_vector2d vector, int offset_y, int offset_x)
{
	if ((vector.y + offset_y) >= g_gamedata.map.height
		|| (vector.y + offset_y) < 0
		|| (vector.x + offset_x) >= g_gamedata.map.width
		|| (vector.x + offset_x) < 0
		|| g_gamedata.map.map[vector.y + offset_y][vector.x + offset_x]
			== COLLISION_WALL)
		return (COLLISION_WALL);
	if (g_gamedata.map.map[vector.y + offset_y][vector.x + offset_x]
			== COLLISION_COLLECT)
		return (COLLISION_COLLECT);
	if (g_gamedata.map.map[vector.y + offset_y][vector.x + offset_x]
			== COLLISION_DOOR)
		return (COLLISION_DOOR);
	if (g_gamedata.map.map[vector.y + offset_y][vector.x + offset_x]
			== COLLISION_ENEMY)
		return (COLLISION_ENEMY);
	return (0);
}

t_vector2d	collision_loop(t_vector2d vector, int offset_y, int offset_x,
				char collision)
{
	int		backup_y;
	int		backup_x;
	int		result;

	backup_y = offset_y;
	backup_x = offset_x;
	while (offset_y >= -backup_y)
	{
		offset_x = backup_x;
		while (offset_x >= -backup_x)
		{
			result = get_coll_result(vector, offset_y, offset_x);
			if (result == collision)
				return (create_vector2d(vector.y + offset_y, vector.x
						+ offset_x));
			offset_x--;
		}
		offset_y--;
	}
	return (vector);
}

t_vector2d	get_collision_cell(t_vector2d vector, char item, char collision)
{
	t_sprites_data	sprite;
	int				offset_y;
	int				offset_x;	

	sprite = get_sprite_data(item);
	offset_y = sprite.height / 2;
	offset_x = sprite.width / 2;
	return (collision_loop(vector, offset_y, offset_x, collision));
}
