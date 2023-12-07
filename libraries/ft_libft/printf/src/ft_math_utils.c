/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_math_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 21:14:59 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/15 15:00:53 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_pow(int base, int exponent)
{
	int		result;

	result = 1;
	while (exponent > 0)
	{
		result = result * base;
		exponent--;
	}
	return (result);
}

void	ft_putnbr_unsig_fd(unsigned int n, int fd)
{
	if (n > 9)
	{
		ft_putnbr_unsig_fd(n / 10, fd);
	}
	ft_putchar_fd((n % 10) + '0', fd);
}

unsigned int	ft_unsig_num_len(unsigned int num)
{
	unsigned int	len;

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

int	ft_getnum_len(int num, t_format *data)
{
	int		len;

	len = 0;
	if (num <= 0)
	{
		len++;
		if (num < 0 && data->argument_prec > 0)
			data->argument_prec++;
	}
	while (num != 0)
	{
		num = num / 10;
		len++;
	}
	return (len);
}

void	ft_printnbr_fd(int n, t_format *data, int fd)
{
	if (n == -2147483648)
	{
		if ((data->arg_perc_on && data->argument_prec > ft_getnum_len(n, data))
			|| (data->buffer2 > ft_getnum_len(n, data)
				&& !data->buffer_justify && data->pad_0))
			ft_putstr_fd("2147483648", fd);
		else
			ft_putstr_fd("-2147483648", fd);
	}
	else
	{
		if (n < 0)
		{
			ft_putchar_fd('-', fd);
			n = n * -1;
		}
		if (n > 9)
		{
			ft_putnbr_fd(n / 10, fd);
		}
		ft_putchar_fd((n % 10) + '0', fd);
	}
}
