/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 13:40:38 by ddemarco          #+#    #+#             */
/*   Updated: 2022/04/01 14:22:49 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

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
