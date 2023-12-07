/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 19:53:38 by ddemarco          #+#    #+#             */
/*   Updated: 2023/04/01 18:25:13 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/so_long.h"

unsigned int	rand_num(void)
{
	unsigned int	seed;
	unsigned int	bit;
	void			*address;

	address = malloc(15);
	if (!address)
		return (0);
	seed = (unsigned int)address;
	if (address)
		free(address);
	bit = ((seed >> 0) ^ (seed >> 2) ^ (seed >> 3) ^ (seed >> 5)) & 1;
	return (seed = (seed >> 1) | (bit << 15));
}

void	free_util(char *str)
{
	if (str)
		free(str);
}

int	ft_abs(int num)
{
	if (num < 0)
		num *= -1;
	return (num);
}
