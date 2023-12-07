/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 15:01:44 by ddemarco          #+#    #+#             */
/*   Updated: 2022/03/28 10:56:32 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t n)
{
	size_t	i;
	char	*dest;
	char	*source;

	dest = (char *)dst;
	source = (char *)src;
	if (dest > source)
	{
		while (n--)
			dest[n] = source[n];
	}
	else if (dest < source)
	{
		i = -1;
		while (++i < n)
			dest[i] = source[i];
	}
	return (dest);
}
