/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:08:05 by ddemarco          #+#    #+#             */
/*   Updated: 2022/04/04 12:00:14 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *str1, const void *str2, size_t n)
{
	unsigned char	*st1;
	unsigned char	*st2;
	size_t			index;

	st1 = (unsigned char *)str1;
	st2 = (unsigned char *)str2;
	if (st1 == st2 || n == 0)
		return (0);
	index = 0;
	while (index < n)
	{
		if (st1[index] != st2[index])
			return (st1[index] - st2[index]);
		index++;
	}
	return (0);
}
