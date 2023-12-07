/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/17 18:50:03 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 19:11:40 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	main(int argc, char **argv)
{
	if (argc < 2)
		prompt_error("Input an argument");
	if (!argv[1] || !ft_strnstr(argv[1], ".ber", ft_strlen(argv[1])))
		prompt_error("Argument invalid");
	g_gamedata.mlx.mlx = mlx_init();
	g_gamedata.sprites = generate_item_graphics(g_gamedata.mlx);
	if (read_map(argv[1]) == -1)
		prompt_error("Map invalid");
	init_tickdata();
	g_gamedata.mlx.mlx_win = mlx_new_window(g_gamedata.mlx.mlx,
			g_gamedata.map.width, g_gamedata.map.height, GAME_TITLE);
	set_bindings(&g_gamedata.mlx);
	mlx_loop(g_gamedata.mlx.mlx);
	return (0);
}
