/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_tools.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:53:38 by ddemarco          #+#    #+#             */
/*   Updated: 2023/03/15 18:44:42 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

char	get_map_pixel(char **map, t_vector2d vector)
{
	if (map[vector.y][vector.x])
		return (map[vector.y][vector.x]);
	return ('\0');
}

void	set_map_pixel(t_sprites_data sprite, t_vector2d vector, char item)
{
	if (g_gamedata.map.map[vector.y][vector.x])
		g_gamedata.map.map[vector.y][vector.x] = item;
	if (item == WALL)
		set_collision(vector, sprite, COLLISION_WALL);
	else if (item == COLLECTABLE)
		set_collision(vector, sprite, COLLISION_COLLECT);
	else if (item == FINALDOOR)
		set_collision(vector, sprite, COLLISION_DOOR);
	else if (item == ENEMY)
		set_collision(vector, sprite, COLLISION_ENEMY);
}

void	place_item(t_vector2d vector, char item)
{
	t_sprites_data	sprite;

	sprite = get_sprite_data(item);
	if (!is_item_colliding(vector, item, item))
	{
		set_map_pixel(sprite, vector, item);
	}
}

void	froce_place_item(t_vector2d vector, char item)
{
	t_sprites_data	sprite;

	sprite = get_sprite_data(item);
	if (is_safe(vector.y, vector.x))
		set_map_pixel(sprite, vector, item);
}
