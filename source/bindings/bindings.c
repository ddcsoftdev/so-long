/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bindings.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:53:38 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 16:12:08 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	window_draw(int win)
{
	render_map();
	if (g_gamedata.tick.is_gameover == 1)
		mlx_string_put(g_gamedata.mlx.mlx, g_gamedata.mlx.mlx_win, 28, 50,
			0xfffafa, "YOU LOSE! PRESS K");
	if (g_gamedata.tick.is_gameover == 2)
		mlx_string_put(g_gamedata.mlx.mlx, g_gamedata.mlx.mlx_win, 28, 50,
			0xfffafa, "YOU WIN! PRESS K");
	return (win);
}

int	enemy_wrapper(void)
{
	g_gamedata.tick.framecount++;
	if (g_gamedata.tick.is_gameover && !g_gamedata.tick.is_paused)
	{
		if (g_gamedata.tick.is_gameover == 1)
			mlx_string_put(g_gamedata.mlx.mlx, g_gamedata.mlx.mlx_win, 28, 50,
				0xfffafa, "YOU LOSE! PRESS K");
		if (g_gamedata.tick.is_gameover == 2)
			mlx_string_put(g_gamedata.mlx.mlx, g_gamedata.mlx.mlx_win, 28, 50,
				0xfffafa, "YOU WIN! PRESS K");
		g_gamedata.tick.is_paused = 1;
	}
	if (g_gamedata.tick.is_paused)
		return (0);
	if (g_gamedata.tick.framecount >= FRAME_RATE)
	{
		move_enemies();
		render_map();
		g_gamedata.tick.framecount = 0;
	}
	return (0);
}

void	set_bindings(t_mlx *mlx)
{
	mlx_hook(mlx->mlx_win, 2, 1L << 0, keydown, 0);
	mlx_hook(mlx->mlx_win, 17, 0, close_mlx, 0);
	mlx_expose_hook(g_gamedata.mlx.mlx_win, window_draw,
		g_gamedata.mlx.mlx_win);
	mlx_loop_hook(mlx->mlx, enemy_wrapper, 0);
}

int	keydown(int keycode)
{
	if (keycode == 53)
		close_mlx();
	if (keycode == 35)
		toogle_pause_game();
	if (keycode == 40)
		finish_game();
	if (keycode == 13 || keycode == 126)
		move_player(MOVE_UP);
	else if (keycode == 1 || keycode == 125)
		move_player(MOVE_DOWN);
	else if (keycode == 2 || keycode == 124)
		move_player(MOVE_RIGHT);
	else if (keycode == 0 || keycode == 123)
		move_player(MOVE_LEFT);
	return (0);
}
