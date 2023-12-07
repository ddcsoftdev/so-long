/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 20:47:16 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 17:31:10 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

t_vector2d	get_player_location(void)
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
			if (g_gamedata.map.map[i][j] == PLAYER)
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

t_vector2d	add_movement(char movement)
{
	t_vector2d	location;
	int			offset;

	location = get_player_location();
	if (movement == MOVE_UP || movement == MOVE_DOWN)
		offset = (g_gamedata.sprites.player.height / 2);
	else
		offset = (g_gamedata.sprites.player.width / 2);
	if (movement == MOVE_UP)
		location.y -= offset;
	else if (movement == MOVE_DOWN)
		location.y += offset;
	else if (movement == MOVE_LEFT)
		location.x -= offset;
	else if (movement == MOVE_RIGHT)
		location.x += offset;
	return (location);
}

void	handle_collision(int collision, t_vector2d newloc, t_vector2d playerloc)
{
	if (collision != 1)
	{
		if (collision == 2)
			collect_object(newloc, substract_vector(playerloc, newloc),
				COLLECTABLE);
		else if (collision == 4)
		{
			kill_player();
		}
		else if (collision == 3)
		{
			if (collectables_left() == 0)
				enter_door();
			else
				return ;
		}
		g_gamedata.map.map[playerloc.y][playerloc.x] = EMPTY;
		g_gamedata.tick.movements += 1;
		g_gamedata.tick.update_movement = 1;
		froce_place_item(newloc, PLAYER);
	}	
}

void	player_animation(char movement)
{
	if (movement == MOVE_DOWN)
		g_gamedata.sprites.player
			= generate_sprite(g_gamedata.mlx, "./art/player50x50down.xpm");
	else if (movement == MOVE_UP)
		g_gamedata.sprites.player
			= generate_sprite(g_gamedata.mlx, "./art/player50x50up.xpm");
	else if (movement == MOVE_RIGHT)
		g_gamedata.sprites.player
			= generate_sprite(g_gamedata.mlx, "./art/player50x50right.xpm");
	else if (movement == MOVE_LEFT)
		g_gamedata.sprites.player
			= generate_sprite(g_gamedata.mlx, "./art/player50x50left.xpm");
}

void	move_player(char movement)
{
	t_vector2d		playerloc;
	t_vector2d		newloc;
	t_sprites_data	sprite;
	int				collision;

	if (g_gamedata.tick.is_paused)
		return ;
	playerloc = get_player_location();
	newloc = add_movement(movement);
	player_animation(movement);
	sprite = get_sprite_data(PLAYER);
	collision = is_item_colliding(newloc, PLAYER, 0);
	handle_collision(collision, newloc, playerloc);
	render_map();
}
