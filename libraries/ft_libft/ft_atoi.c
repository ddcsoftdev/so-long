/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:50:35 by ddemarco          #+#    #+#             */
/*   Updated: 2022/10/29 18:27:23 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_atoi(const char *str)
{
	int			i;
	int			sign;
	size_t		number;

	i = 0;
	sign = 1;
	number = 0;
	while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\f'
			|| str[i] == '\r' || str[i] == '\n' || str[i] == '\v'))
		i++;
	if (str[i] == '-')
		sign *= -1;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (number >= 9223372036854775807 && sign == 1)
		return (0);
	else if (number > 9223372036854775807 && sign == -1)
		return (-1);
	while (str[i] >= '0' && str[i] <= '9')
	{
		number = (number * 10) + str[i] - '0';
		i++;
	}
	return (number * sign);
}
