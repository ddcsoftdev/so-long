/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/01 20:13:57 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 16:42:06 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	leaks(void)
{
	system("leaks -q so_long");
}

int	close_mlx(void)
{
	if (g_gamedata.map.created)
		free_map();
	if (g_gamedata.mlx.mlx_win)
		mlx_destroy_window(g_gamedata.mlx.mlx, g_gamedata.mlx.mlx_win);
	if (g_gamedata.mlx.mlx)
		free(g_gamedata.mlx.mlx);
	leaks();
	exit(0);
	return (0);
}

void	prompt_error(char *str)
{
	ft_putstr_fd("Error\n", 2);
	ft_putendl_fd(str, 2);
	close_mlx();
}
