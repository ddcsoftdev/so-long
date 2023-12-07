# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/12/17 18:47:25 by ddemarco          #+#    #+#              #
#    Updated: 2023/04/01 18:13:06 by ddemarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = includes/so_long.a

EXE = so_long

LIBS = libraries/ft_libft/libft.a libraries/mlx/libmlx.a

CC = gcc

FLAGS =  -Wall -Wextra -Werror -lmlx -framework OpenGL -framework AppKit

FLAGS_LEAKS = -g -fsanitize=address -g3

INCLUDES = includes/so_long.h libraries/ft_libft/libft.a libraries/mlx/libmlx.a

SRCS = 		source/so_long.c\
			source/graphics/images.c\
			source/graphics/sprites.c\
			source/render/render_sprites.c\
			source/render/render_map.c\
			source/utils/vector.c\
			source/utils/math.c\
			source/generators/map_generator.c\
			source/generators/item_generator.c\
			source/map/map_tools.c\
			source/map/map_read.c\
			source/map/map_validation.c\
			source/map/map_validpath.c\
			source/physics/collision.c\
			source/physics/enemy_collision.c\
			source/physics/collision_detection.c\
			source/physics/collision_scan.c\
			source/bindings/bindings.c\
			source/gameplay/player.c\
			source/gameplay/collectable.c\
			source/gameplay/door.c\
			source/gameplay/enemy.c\
			source/gameplay/enemy_utils.c\
			source/gameplay/object_tools.c\
			source/gameplay/tick.c\
			source/debug/debug.c\
			source/error/error.c\
			source/ui/ui.c\

OBJS = ${SRCS:.c=.o}

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
		ar -rcs $(NAME) $(OBJS)
		rm -rf a.out

$(LEAKS): $(NAME) $(LIBS)
		$(CC) $(FLAGS) $(FLAGS_LEAKS) -o so_long $(NAME) $(LIBS)

$(EXE): $(NAME)
		$(CC) $(FLAGS) -o so_long $(NAME) $(LIBS)

$(LIBS):
		make all -C libraries/ft_libft
		make all -C libraries/mlx

all: mandatory

mandatory: $(LIBS) $(NAME) $(EXE)

bonus: $(LIBS) $(NAME) $(EXE)

leaks: $(LIBS) $(LEAKS) $(EXE)

clean : 
		rm -rf $(OBJS)
		rm -rf includes/so_long.h.gch	
fclean : clean
		rm -rf $(NAME) $(EXE)	
		rm -rf ./bin

lbs:	$(LIBS)

fcleanlbs:
		make fclean -C libraries/ft_libft/
		make clean -C libraries/mlx/

re : fclean all

.PHONY : all mandatory bonus clean fclean re lbs fcleanlbs