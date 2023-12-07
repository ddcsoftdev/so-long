/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_read_format.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 18:50:04 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/15 14:58:52 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

const char	*ft_check_padding(const char *format, t_format *data)
{
	while (*format == '-' || *format == '+' || *format == '0'
		|| *format == ' ' || *format == '.' || *format == '#')
	{
		if (!data->active_format)
			data->active_format = 1;
		if (*format == '.' && !data->arg_perc_on)
		{
			data->arg_perc_on = 1;
			format = ft_read_dot(format, data);
			if (data->justify_left)
			{
				data->justify_left = 0;
				data->buffer_justify = 1;
			}
		}
		ft_check_padding_util(format, data);
		format++;
	}
	return (format);
}

void	ft_check_padding_util(const char *format, t_format *data)
{
	if (*format == '-')
	{
		data->justify_left = 1;
		data->pad_0 = 0;
		data->buffer_justify = 1;
	}
	if (*format == '+')
	{
		data->print_sign = 1;
		data->space_bf_value = 0;
	}
	if (*format == '0' && !data->justify_left)
		data->pad_0 = 1;
	if (*format == ' ' && !data->print_sign)
		data->space_bf_value = 1;
	if (*format == '#' && !data->sharp)
		data->sharp = 1;
}

const char	*ft_check_buffer(const char *format, t_format *format_data)
{
	int				buffer;
	int				len;
	char			*dummy;

	len = 0;
	dummy = (char *)format;
	while (*dummy >= '0' && *dummy <= '9')
	{
		dummy++;
		len++;
	}
	buffer = 0;
	while (len > 0)
	{
		buffer += ft_pow(10, len - 1) * ((int)*format - 48);
		format++;
		len--;
	}
	if (buffer > 0)
	{
		if (!format_data->active_format)
			format_data->active_format = 1;
		format_data->buffer = buffer;
	}
	return (format);
}

const char	*ft_check_format(const char *format, t_format *data)
{
	format = ft_check_padding(format, data);
	format = ft_check_buffer(format, data);
	data->buffer2 = data->buffer;
	format = ft_check_padding(format, data);
	return (format);
}

const char	*ft_read_dot(const char *format, t_format *data)
{
	int		len;
	int		decimals;

	len = 0;
	decimals = 0;
	format++;
	while (*format >= '0' && *format <= '9')
	{
		if (decimals == 0)
			len = ((int)*format - 48);
		else
			len = (len * ft_pow(10, decimals)) + ((int)*format - 48);
		format++;
		decimals++;
	}
	data->argument_prec = len;
	format--;
	return (format);
}
