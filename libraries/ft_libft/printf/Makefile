# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/04/30 13:44:28 by ddemarco          #+#    #+#              #
#    Updated: 2022/06/05 17:00:45 by ddemarco         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libftprintf.a

LIBFT = ../libft.a

CC = gcc

FLAGS = -c -Wall -Wextra -Werror

INCLUDES = include/ft_printf.h ../libft.h

SRCS = 		src/ft_printf.c \
			src/ft_flag_utils.c \
			src/ft_hex_tools.c \
			src/ft_hex_utils.c  \
			src/ft_int_utils.c  \
			src/ft_uint_utils.c  \
			src/ft_math_utils.c \
			src/ft_ptr_tools.c \
			src/ft_read_format.c \
			src/ft_struct_utils.c \
			src/ft_utils.c \
			src/ft_write_format.c \
			../ft_atoi.c\
			../ft_bzero.c\
			../ft_calloc.c\
			../ft_isalnum.c\
			../ft_isalpha.c\
			../ft_isascii.c\
			../ft_isdigit.c\
			../ft_toupper.c\
			../ft_tolower.c\
			../ft_isprint.c\
			../ft_memchr.c\
			../ft_memcmp.c\
			../ft_memcpy.c\
			../ft_memmove.c\
			../ft_memset.c\
			../ft_strchr.c\
			../ft_strdup.c\
			../ft_strncmp.c\
			../ft_strnstr.c\
			../ft_strrchr.c\
			../ft_strlen.c\
			../ft_strlcpy.c\
			../ft_strlcat.c\
			../ft_substr.c\
			../ft_split.c\
			../ft_strjoin.c\
			../ft_strtrim.c\
			../ft_itoa.c\
			../ft_strmapi.c\
			../ft_striteri.c\
			../ft_putchar_fd.c\
			../ft_putstr_fd.c\
			../ft_putendl_fd.c\
			../ft_putnbr_fd.c
		
OBJS = ${SRCS:.c=.o}

OBJS_R =	ft_printf.o \
			ft_flag_utils.o \
			ft_hex_utils.o \
			ft_int_utils.o  \
			ft_uint_utils.o  \
			ft_hex_tools.o \
			ft_math_utils.o \
			ft_ptr_tools.o \
			ft_read_format.o \
			ft_struct_utils.o \
			ft_utils.o \
			ft_write_format.o \
			ft_atoi.o\
			ft_bzero.o\
			ft_calloc.o\
			ft_isalnum.o\
			ft_isalpha.o\
			ft_isascii.o\
			ft_isdigit.o\
			ft_toupper.o\
			ft_tolower.o\
			ft_isprint.o\
			ft_memchr.o\
			ft_memcmp.o\
			ft_memcpy.o\
			ft_memmove.o\
			ft_memset.o\
			ft_strchr.o\
			ft_strdup.o\
			ft_strncmp.o\
			ft_strnstr.o\
			ft_strrchr.o\
			ft_strlen.o\
			ft_strlcpy.o\
			ft_strlcat.o\
			ft_substr.o\
			ft_split.o\
			ft_strjoin.o\
			ft_strtrim.o\
			ft_itoa.o\
			ft_strmapi.o\
			ft_striteri.o\
			ft_putchar_fd.o\
			ft_putstr_fd.o\
			ft_putendl_fd.o\
			ft_putnbr_fd.o

$(NAME): $(OBJS)
		$(CC) $(FLAGS) $(INCLUDES) $(SRCS)
		ar -rcs $(NAME) $(OBJS)

all : $(NAME)

bonus : $(NAME)

clean : 
		rm -rf $(OBJS)
		rm -rf $(OBJS_R)
fclean : clean
		rm -rf $(NAME)

re : fclean all

.PHONY : all bonus clean fclean re