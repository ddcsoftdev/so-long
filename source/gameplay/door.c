/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   door.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:53:38 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 13:28:08 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_vector2d	get_door_location(void)
{
	t_vector2d	vector;
	int			i;
	int			j;
	int			counter;

	i = WIN_H_OFFSET - 1;
	vector.x = -1;
	vector.y = -1;
	counter = 0;
	while (++i < g_gamedata.map.height)
	{
		j = WIN_W_OFFSET - 1;
		while (++j < g_gamedata.map.width)
		{
			if (g_gamedata.map.map[i][j] == FINALDOOR)
			{
				vector.x = j;
				vector.y = i;
				counter++;
			}
		}
	}
	if (counter > 1)
		return (create_vector2d(-1, -1));
	return (vector);
}

void	enter_door(void)
{
	g_gamedata.tick.is_gameover = 2;
}
