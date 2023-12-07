/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/28 17:01:34 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 17:51:13 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../libraries/mlx/mlx.h"
# include "../libraries/ft_libft/libft.h"

# define GAME_TITLE "GAME"
# define WIN_W_OFFSET 100
# define WIN_H_OFFSET 100

# define EMPTY '0'
# define WALL '1'
# define COLLECTABLE 'C'
# define FINALDOOR 'E'
# define PLAYER 'P'
# define ENEMY 'M'
# define TEMP_ENEMY 'J'
# define TEMP_COLLECT 'Y'
# define TEMP_DOOR 'F'
# define TEMP_EMPTY 'I'
# define PATH_CHECK 'G'

# define COLLISION_WALL '@'
# define COLLISION_COLLECT '&'
# define COLLISION_DOOR '#'
# define COLLISION_ENEMY '!'

# define MOVE_UP 'U'
# define MOVE_DOWN 'D'
# define MOVE_LEFT 'L'
# define MOVE_RIGHT 'R'

# define ENEMY_RECH 50
# define ENEMY_UP 7
# define ENEMY_DOWN 5
# define ENEMY_LEFT 3
# define ENEMY_RIGHT 1

# define FRAME_RATE 1500

typedef struct s_mlx {
	void	*mlx;
	void	*mlx_win;
}				t_mlx;

typedef struct s_map_data {
	char	**map;
	int		width;
	int		height;
	int		created;
}				t_map_data;

typedef struct s_vector2d {
	int		y;
	int		x;
}				t_vector2d;

typedef struct s_sprites_data {
	void	*sprite;
	char	*path;
	int		width;
	int		height;
}				t_sprites_data;

typedef struct s_game_sprites {
	t_sprites_data	wall;
	t_sprites_data	collectable;
	t_sprites_data	finaldoor;
	t_sprites_data	player;
	t_sprites_data	enemy;
	t_sprites_data	empty;
}				t_game_sprites;

typedef struct s_tick_data {
	int	movements;
	int	framecount;
	int	update_movement;
	int	is_paused;
	int	is_gameover;
}				t_tick_data;

typedef struct s_game_data {
	t_mlx			mlx;
	t_map_data		map;
	t_game_sprites	sprites;
	t_tick_data		tick;
}				t_game_data;

t_game_data	g_gamedata;

void			*generate_image(t_mlx *mlx);
t_sprites_data	generate_sprite(t_mlx mlx, char *path);

t_vector2d		create_vector2d(int y, int x);
t_vector2d		substract_vector(t_vector2d v1, t_vector2d v2);
t_vector2d		add_vector(t_vector2d v1, t_vector2d v2);
int				is_equal_vector(t_vector2d v1, t_vector2d v2);

void			generate_map(void);
t_game_sprites	generate_item_graphics(t_mlx mlx);
t_sprites_data	get_sprite_data(char item);

int				render_sprite(t_mlx *mlx, void *sprite, t_vector2d vector);
void			render_map(void);
void			render_menu(void);

unsigned int	rand_num(void);
int				ft_abs(int num);

char			get_map_pixel(char **map, t_vector2d vector);
t_vector2d		get_player_location(void);
void			place_item(t_vector2d vector, char item);
void			froce_place_item(t_vector2d vector, char item);

int				is_item_colliding(t_vector2d vector, char item, char ignore);
void			set_collision(t_vector2d vector, t_sprites_data sprite,
					char collision);
int				is_enemy_colliding(t_vector2d vector, char item,
					char direct);

t_vector2d		get_collision_cell(t_vector2d vector, char item,
					char collision);

void			set_bindings(t_mlx *mlx);
int				keydown(int keycode);

void			move_player(char movement);

void			collect_object(t_vector2d start_loc, t_vector2d direct,
					char item);
int				collectables_left(void);

void			enter_door(void);
t_vector2d		get_door_location(void);

int				is_safe(int y, int x);

void			kill_player(void);
void			move_enemies(void);
int				find_enemies(void);
void			enemy_animation(char movement);

int				compare_vector(t_vector2d v1, t_vector2d v2);

t_vector2d		scan_obj_center(char collision, t_vector2d loc,
					t_vector2d direct);

void			delete_object_coll(t_vector2d start_loc, t_vector2d direction,
					char collision, char item);
void			delete_object(t_vector2d center, char item);

void			debug_print_map(void);

int				read_map(char *pathfile);
int				is_valid_map(char *pathfile);
int				validate_minobjects(void);
int				validate_pathway(void);

void			free_map(void);

void			prompt_error(char *str);
int				close_mlx(void);

void			update_movement(void);
void			init_tickdata(void);
void			toogle_pause_game(void);
void			finish_game(void);

void			free_util(char *str);

void			leaks(void);
#endif