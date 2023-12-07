# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/03/03 13:21:43 by ddemarco          #+#    #+#              #
#    Updated: 2023/03/22 17:08:45 by ddemarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

S_NAME = .simple

B_NAME = .bonus

GCH = libft.h.gch printf/include/ft_printf.h.gch

CC = gcc

CFLAGS = -Wall -Wextra -Werror

AR = ar rcs

RM = rm -f

SRCS = ft_atoi.c\
 ft_bzero.c\
 ft_calloc.c\
 ft_isalnum.c\
 ft_isalpha.c\
 ft_isascii.c\
 ft_isdigit.c\
 ft_toupper.c\
 ft_tolower.c\
 ft_isprint.c\
 ft_memchr.c\
 ft_memcmp.c\
 ft_memcpy.c\
 ft_memmove.c\
 ft_memset.c\
 ft_strchr.c\
 ft_strdup.c\
 ft_strncmp.c\
 ft_strnstr.c\
 ft_strrchr.c\
 ft_strlen.c\
 ft_strlcpy.c\
 ft_strlcat.c\
 ft_substr.c\
 ft_split.c\
 ft_strjoin.c\
 ft_strtrim.c\
 ft_itoa.c\
 ft_strmapi.c\
 ft_striteri.c\
 ft_putchar_fd.c\
 ft_putstr_fd.c\
 ft_putendl_fd.c\
 ft_putnbr_fd.c\
 get_next_line/get_next_line.c\
 get_next_line/get_next_line_utils.c\
 printf/src/ft_printf.c \
 printf/src/ft_flag_utils.c \
 printf/src/ft_hex_tools.c \
 printf/src/ft_hex_utils.c  \
 printf/src/ft_int_utils.c  \
 printf/src/ft_uint_utils.c  \
 printf/src/ft_math_utils.c \
 printf/src/ft_ptr_tools.c \
 printf/src/ft_read_format.c \
 printf/src/ft_struct_utils.c \
 printf/src/ft_utils.c \
 printf/src/ft_write_format.c \

INCLUDE = libft.h printf/include/ft_printf.h


SRCS_B = ft_lstnew.c\
 ft_lstadd_front.c\
 ft_lstsize.c\
 ft_lstlast.c\
 ft_lstadd_back.c\
 ft_lstdelone.c\
 ft_lstclear.c\
 ft_lstiter.c\
 ft_lstmap.c\

OBJS = ${SRCS:.c=.o}
OBJS_B = ${SRCS_B:.c=.o}


all: $(NAME)

$(NAME): $(S_NAME)

$(S_NAME): $(OBJS) $(OBJS_B) $(INCLUDE)
	$(AR) $(NAME) $(OBJS) $(OBJS_B)
#	@make -C printf/

clean:
	$(RM) $(OBJS) $(OBJS_B)
#	@make clean -C printf/

fclean: clean
	$(RM) ${NAME} ${B_NAME} ${S_NAME} $(OBJS) $(OBJS_B) $(GCH)
#	@make fclean -C printf/

re: clean all bonus

.PHONY: bonus all clean fclean re