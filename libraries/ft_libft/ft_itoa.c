/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 16:37:02 by ddemarco          #+#    #+#             */
/*   Updated: 2022/04/04 11:52:37 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	num_len(int num)
{
	int		len;

	len = 0;
	if (num <= 0)
		len++;
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

char	*ft_itoa(int n)
{
	unsigned int	num;
	int				len;
	int				sign;
	char			*str;

	len = num_len(n);
	sign = 1;
	if (n < 0)
		sign = -1;
	num = n * sign;
	str = (char *)malloc(sizeof(char) * len + 1);
	if (!str)
		return (0);
	str[len--] = '\0';
	while (len >= 0)
	{
		str[len] = (num % 10) + '0';
		num = num / 10;
		len--;
	}
	if (sign < 0)
		str[0] = '-';
	return (str);
}	
