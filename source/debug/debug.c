/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   debug.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:47:16 by ddemarco          #+#    #+#             */
/*   Updated: 2023/03/01 20:50:36 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"	

void	debug_print_map(void)
{
	int	i;
	int	j;

	i = -1;
	while (++i < g_gamedata.map.height)
	{
		j = -1;
		while (++j < g_gamedata.map.width)
		{
			ft_printf("%c", g_gamedata.map.map[i][j]);
		}
		ft_printf("\n");
	}
}
