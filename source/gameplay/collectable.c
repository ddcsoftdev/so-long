/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collectable.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:53:38 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 17:32:01 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	collect_object(t_vector2d start_loc, t_vector2d direction, char item)
{
	char	collision;

	collision = COLLISION_WALL;
	if (item == COLLECTABLE)
		collision = COLLISION_COLLECT;
	else if (item == FINALDOOR)
		collision = COLLISION_DOOR;
	else if (item == ENEMY)
		collision = COLLISION_ENEMY;
	delete_object_coll(start_loc, direction, collision, item);
}

int	collectables_left(void)
{
	int			i;
	int			j;
	int			counter;

	i = WIN_H_OFFSET - 1;
	counter = 0;
	while (++i < g_gamedata.map.height)
	{
		j = WIN_W_OFFSET - 1;
		while (++j < g_gamedata.map.width)
		{
			if (g_gamedata.map.map[i][j] == COLLECTABLE)
			{
				counter++;
			}
		}
	}
	return (counter);
}
