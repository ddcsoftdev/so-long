/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_flag_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 18:31:36 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/15 15:01:23 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printstr_fd(char *str, t_format *data, int *strlen, int fd)
{
	int		len_mod;
	int		arg_precision;

	len_mod = 0;
	arg_precision = data->argument_prec;
	if (data->active_format && data->arg_perc_on
		&& *strlen > arg_precision)
	{	
		len_mod = *strlen - arg_precision;
		*strlen = arg_precision;
		while (str && arg_precision > 0)
		{
			ft_putchar_fd(*str, fd);
			str++;
			arg_precision--;
		}
	}
	else
		ft_putstr_fd(str, fd);
	return (len_mod);
}

int	ft_sharp_flag(unsigned int n, t_format *data, const char format)
{
	int		len;

	len = 0;
	if (data->sharp && n != 0)
	{
		if (format == 'x')
			ft_putstr_fd("0x", 1);
		else if (format == 'X')
			ft_putstr_fd("0X", 1);
		len += 2;
	}
	return (len);
}

int	ft_altbufferhandle(t_format *data, int len)
{
	int		i;

	i = 0;
	while (len < data->buffer2)
	{
		ft_putchar_fd(' ', 1);
		i++;
		data->buffer2--;
	}
	return (i);
}
