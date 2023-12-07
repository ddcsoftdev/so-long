/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tick.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/22 15:58:00 by ddemarco          #+#    #+#             */
/*   Updated: 2023/03/22 16:16:06 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	finish_game(void)
{
	if (!g_gamedata.tick.is_gameover)
		return ;
	close_mlx();
}

void	toogle_pause_game(void)
{
	if (g_gamedata.tick.is_gameover)
		return ;
	if (g_gamedata.tick.is_paused)
		g_gamedata.tick.is_paused = 0;
	else if (!g_gamedata.tick.is_paused)
		g_gamedata.tick.is_paused = 1;
	if (g_gamedata.tick.is_paused)
	{
		mlx_string_put(g_gamedata.mlx.mlx, g_gamedata.mlx.mlx_win, 50, 50,
			0xfffafa, "PAUSED");
	}
}
