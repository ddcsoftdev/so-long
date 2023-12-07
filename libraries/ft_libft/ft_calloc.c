/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 12:19:19 by ddemarco          #+#    #+#             */
/*   Updated: 2022/04/04 11:59:23 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t slots, size_t size)
{
	void	*memory;

	memory = (void *)malloc(slots * size);
	if (!memory)
		return (NULL);
	ft_memset(memory, 0, slots * size);
	return (memory);
}
