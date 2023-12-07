/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_write_format.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:19:53 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/15 14:59:21 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_write_sign(t_format *data, int *n, int *len)
{
	int		isnegative;

	isnegative = 0;
	if (data->print_sign)
	{
		if (*n >= 0)
		{
			ft_putchar_fd('+', 1);
			*len = *len + 1;
		}
		else
		{
			if (*n != -2147483648)
				ft_putchar_fd('-', 1);
			isnegative = 1;
			*n = *n * -1;
		}
	}
	return (isnegative);
}

int	ft_write_format(t_format *data, int leng)
{
	int		len;

	len = 0;
	if (data->arg_perc_on && data->argument_prec < leng)
		leng = data->argument_prec;
	data->buffer -= leng;
	if (data->buffer > 0)
	{
		while (--data->buffer >= 0)
		{
			if (data->pad_0)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			len++;
		}	
	}
	return (len);
}

int	ft_write_format_n(t_format *data, int leng, int *n)
{
	int		len;

	len = 0;
	if (data->argument_prec > 0)
		data->buffer = data->argument_prec;
	if (data->argument_prec > 0)
		data->pad_0 = 1;
	data->buffer -= leng;
	if (data->buffer > 0)
	{
		if (*n < 0 && data->pad_0)
		{
			ft_putchar_fd('-', 1);
			*n = *n * -1;
		}
		while (--data->buffer >= 0)
		{
			if (data->pad_0)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			len++;
		}	
	}
	return (len);
}

int	ft_write_format_un(t_format *data, int leng, unsigned int *n)
{
	int		len;

	len = 0;
	if (data->argument_prec > 0)
		data->buffer = data->argument_prec;
	if (data->argument_prec > 0)
		data->pad_0 = 1;
	data->buffer -= leng;
	if (data->buffer > 0)
	{
		if (*n < 0 && data->pad_0)
		{
			ft_putchar_fd('-', 1);
			*n = *n * -1;
		}
		while (--data->buffer >= 0)
		{
			if (data->pad_0)
				ft_putchar_fd('0', 1);
			else
				ft_putchar_fd(' ', 1);
			len++;
		}	
	}
	return (len);
}
