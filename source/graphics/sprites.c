/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprites.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:06:33 by ddemarco          #+#    #+#             */
/*   Updated: 2023/01/22 17:55:57 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_sprites_data	generate_sprite(t_mlx mlx, char *path)
{
	t_sprites_data	sprite;

	sprite.sprite = mlx_xpm_file_to_image(mlx.mlx, path,
			&sprite.width, &sprite.height);
	return (sprite);
}

t_sprites_data	get_sprite_data(char item)
{
	t_sprites_data	sprite;

	if (item == WALL)
		sprite = g_gamedata.sprites.wall;
	else if (item == COLLECTABLE)
		sprite = g_gamedata.sprites.collectable;
	else if (item == FINALDOOR)
		sprite = g_gamedata.sprites.finaldoor;
	else if (item == PLAYER)
		sprite = g_gamedata.sprites.player;
	else if (item == ENEMY)
		sprite = g_gamedata.sprites.enemy;
	else
		sprite = g_gamedata.sprites.empty;
	return (sprite);
}
