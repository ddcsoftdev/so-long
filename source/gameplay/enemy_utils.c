/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 20:36:47 by ddemarco          #+#    #+#             */
/*   Updated: 2023/03/15 16:49:31 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	enemy_animation(char movement)
{
	if (movement == MOVE_DOWN)
		g_gamedata.sprites.enemy
			= generate_sprite(g_gamedata.mlx, "./art/enemy50x50down.xpm");
	else if (movement == MOVE_UP)
		g_gamedata.sprites.enemy
			= generate_sprite(g_gamedata.mlx, "./art/enemy50x50up.xpm");
	else if (movement == MOVE_RIGHT)
		g_gamedata.sprites.enemy
			= generate_sprite(g_gamedata.mlx, "./art/enemy50x50right.xpm");
	else if (movement == MOVE_LEFT)
		g_gamedata.sprites.enemy
			= generate_sprite(g_gamedata.mlx, "./art/enemy50x50left.xpm");
}

int	find_enemies(void)
{
	int			i;
	int			j;
	int			count;

	i = WIN_H_OFFSET - 1;
	count = 0;
	while (++i < g_gamedata.map.height)
	{
		j = WIN_W_OFFSET - 1;
		while (++j < g_gamedata.map.width)
		{
			if (g_gamedata.map.map[i][j] == ENEMY)
			{
				g_gamedata.map.map[i][j] = TEMP_ENEMY;
				count++;
			}
		}
	}
	return (count);
}
