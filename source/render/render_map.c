/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_map.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 18:13:40 by ddemarco          #+#    #+#             */
/*   Updated: 2023/03/22 20:27:25 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	render_item(t_mlx mlx, t_sprites_data sprite, int i, int j)
{
	if (!sprite.sprite)
		return ;
	render_sprite(mlx.mlx, sprite.sprite, create_vector2d(i, j));
}

void	render_map(void)
{
	t_game_sprites	sprites;
	int				i;
	int				j;

	sprites = g_gamedata.sprites;
	i = -1;
	mlx_clear_window(g_gamedata.mlx.mlx, g_gamedata.mlx.mlx_win);
	while (++i < g_gamedata.map.height)
	{
		j = -1;
		while (g_gamedata.map.map[i][++j])
		{
			if (g_gamedata.map.map[i][j] == WALL)
				render_item(g_gamedata.mlx, sprites.wall, i, j);
			else if (g_gamedata.map.map[i][j] == COLLECTABLE)
				render_item(g_gamedata.mlx, sprites.collectable, i, j);
			else if (g_gamedata.map.map[i][j] == FINALDOOR)
				render_item(g_gamedata.mlx, sprites.finaldoor, i, j);
			else if (g_gamedata.map.map[i][j] == PLAYER)
				render_item(g_gamedata.mlx, sprites.player, i, j);
			else if (g_gamedata.map.map[i][j] == ENEMY)
				render_item(g_gamedata.mlx, sprites.enemy, i, j);
		}
	}
	update_movement();
}

void	render_menu(void)
{
	mlx_clear_window(g_gamedata.mlx.mlx, g_gamedata.mlx.mlx_win);
}
