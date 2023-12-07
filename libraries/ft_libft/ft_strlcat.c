/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:46:42 by ddemarco          #+#    #+#             */
/*   Updated: 2022/04/04 12:01:44 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t destsize)
{
	size_t				src_size;
	size_t				dest_size;
	size_t				i;

	src_size = ft_strlen(src);
	dest_size = 0;
	if (destsize == 0)
		return (src_size);
	while (dest[dest_size] && dest_size < destsize)
		dest_size++;
	if (destsize <= dest_size)
		return (destsize + src_size);
	i = 0;
	while (src[i] && --destsize > 0 && (destsize - dest_size > 0))
	{
		dest[dest_size + i] = src[i];
		i++;
	}
	dest[dest_size + i] = '\0';
	return (src_size + dest_size);
}
