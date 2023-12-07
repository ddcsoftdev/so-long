/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:47:16 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 17:33:19 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	get_direction(t_vector2d direct)
{
	char	direction;

	direction = MOVE_DOWN;
	if (direct.y > 0)
		direction = MOVE_UP;
	if (direct.x < 0)
		direction = MOVE_RIGHT;
	if (direct.x > 0)
		direction = MOVE_LEFT;
	return (direction);
}

void	delete_object_coll(t_vector2d start_loc, t_vector2d direct,
		char collision, char item)
{
	t_vector2d	loc;

	start_loc = get_collision_cell(start_loc, item, collision);
	loc = scan_obj_center(collision, start_loc, direct);
	if (g_gamedata.map.map[loc.y][loc.x] == item)
	{
		set_collision(loc, get_sprite_data(item), EMPTY);
		g_gamedata.map.map[loc.y][loc.x] = EMPTY;
	}
}

void	delete_object(t_vector2d center, char item)
{
	if (g_gamedata.map.map[center.y][center.x] == item)
	{
		if (item == TEMP_ENEMY)
			item = ENEMY;
		set_collision(center, get_sprite_data(item), EMPTY);
		g_gamedata.map.map[center.y][center.x] = EMPTY;
	}
}
