/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/21 11:42:00 by ddemarco          #+#    #+#             */
/*   Updated: 2022/06/05 17:10:56 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *str)
{
	size_t		result;

	result = 0;
	while (str[result])
		result++;
	return (result);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	j;

	if (!s1 || !s2)
		return (0);
	str = (char *)malloc(sizeof(*str) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!str)
		return (0);
	i = 0;
	j = 0;
	while (s1[i] != 0)
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j] != 0)
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i])
		i++;
	while (i >= 0)
	{
		if (str[i] == (char)c)
			return ((char *)(str + i));
		i--;
	}
	return (NULL);
}

void	*ft_memset(void *ptr, int c, size_t n)
{
	unsigned char	*str;

	str = (unsigned char *)ptr;
	while (n > 0)
	{
		*str = (unsigned char)c;
		str++;
		n--;
	}
	return (ptr);
}

void	*ft_calloc(size_t slots, size_t size)
{
	void	*memory;

	memory = (void *)malloc(slots * size);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, slots * size);
	return (memory);
}
