/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 10:37:15 by ddemarco          #+#    #+#             */
/*   Updated: 2022/06/05 16:31:47 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5000
# endif

# ifndef MAX_FD_NUM
#  define MAX_FD_NUM 4096
# endif

char		*get_next_line(int fd);
size_t		ft_strlen(const char *str);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strrchr(const char *str, int c);
void		*ft_calloc(size_t slots, size_t size);
void		*ft_memset(void *ptr, int c, size_t n);

#endif