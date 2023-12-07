/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:53:38 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/05 16:23:16 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

void	kill_player(void)
{
	g_gamedata.tick.is_gameover = 1;
}

char	get_enemy_direction(int old_direction)
{
	int	direction;
	int	seed;

	seed = rand_num() % 10;
	if (seed > ENEMY_UP && old_direction != ENEMY_UP)
		direction = MOVE_UP;
	else if (seed > ENEMY_DOWN && old_direction != ENEMY_DOWN)
		direction = MOVE_DOWN;
	else if (seed > ENEMY_LEFT && old_direction != ENEMY_LEFT)
		direction = MOVE_LEFT;
	else
		direction = MOVE_RIGHT;
	return (direction);
}

t_vector2d	get_new_location(t_vector2d start, char direction)
{
	t_vector2d	newloc;
	int			amount;

	newloc = start;
	amount = g_gamedata.sprites.enemy.height / 2;
	if (direction == MOVE_UP)
		newloc.y -= amount;
	else if (direction == MOVE_DOWN)
		newloc.y += amount;
	else if (direction == MOVE_LEFT)
		newloc.x -= amount;
	else if (direction == MOVE_RIGHT)
		newloc.x += amount;
	return (newloc);
}

t_vector2d	generate_movement(t_vector2d location)
{
	char		movement;
	int			collision;
	t_vector2d	new_loc;
	int			i;

	i = 0;
	movement = get_enemy_direction('0');
	enemy_animation(movement);
	new_loc = get_new_location(location, movement);
	collision = is_enemy_colliding(new_loc, ENEMY, movement);
	while (collision)
	{
		movement = get_enemy_direction(movement);
		new_loc = get_new_location(location, movement);
		collision = is_enemy_colliding(new_loc, ENEMY, movement);
		if (i >= 3)
			return (location);
		i++;
	}
	return (new_loc);
}

void	move_enemies(void)
{
	int			i;
	int			j;
	t_vector2d	location;

	find_enemies();
	i = WIN_H_OFFSET - 1;
	while (++i < g_gamedata.map.height)
	{
		j = WIN_W_OFFSET - 1;
		while (++j < g_gamedata.map.width)
		{
			if (g_gamedata.map.map[i][j] == TEMP_ENEMY)
			{
				location = generate_movement(create_vector2d(i, j));
				delete_object(create_vector2d(i, j), TEMP_ENEMY);
				place_item(location, ENEMY);
			}
		}
	}
	if (is_equal_vector(get_player_location(), create_vector2d(-1, -1)))
		kill_player();
}
