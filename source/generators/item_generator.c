/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   item_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:03:55 by ddemarco          #+#    #+#             */
/*   Updated: 2023/03/18 17:55:14 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_game_sprites	generate_item_graphics(t_mlx mlx)
{
	t_game_sprites	sprites;

	sprites.wall = generate_sprite(mlx, "./art/wall50x50.xpm");
	sprites.collectable = generate_sprite(mlx, "./art/collectable50x50.xpm");
	sprites.finaldoor = generate_sprite(mlx, "./art/door50x50.xpm");
	sprites.player = generate_sprite(mlx, "./art/player50x50down.xpm");
	sprites.enemy = generate_sprite(mlx, "./art/enemy50x50down.xpm");
	return (sprites);
}
