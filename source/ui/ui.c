/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/04 14:56:50 by ddemarco          #+#    #+#             */
/*   Updated: 2023/03/22 20:35:05 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

int	create_trgb(int t, int r, int g, int b)
{
	return (t << 24 | r << 16 | g << 8 | b);
}

void	update_movement(void)
{
	char		*str;
	char		*str2;

	str2 = ft_itoa(g_gamedata.tick.movements);
	str = ft_strjoin("Movements ", str2);
	if (!str || !str2)
	{
		free_util(str);
		free_util(str2);
		return ;
	}
	mlx_string_put(g_gamedata.mlx.mlx, g_gamedata.mlx.mlx_win, 25, 25,
		0xfffafa, str);
	if (g_gamedata.tick.update_movement)
	{
		ft_printf(str);
		ft_printf("\n");
		g_gamedata.tick.update_movement = 0;
	}
	free_util(str);
	free_util(str2);
}

void	init_tickdata(void)
{
	g_gamedata.tick.movements = 0;
	g_gamedata.tick.framecount = 0;
	g_gamedata.tick.update_movement = 0;
	g_gamedata.tick.is_paused = 0;
	g_gamedata.tick.is_gameover = 0;
}
