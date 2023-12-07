/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hex_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:19:10 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/15 15:34:48 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_hex_zero(unsigned int *n, int n_len, int len, t_format *data)
{
	n_len = 0;
	data->pad_0 = 0;
	len += ft_write_format_un(data, n_len, n) + n_len;
	return (len);
}

void	ft_hex_util(int n_len, int *len, t_format *data)
{
	if (!data->buffer_justify
		&& data->arg_perc_on && n_len > data->argument_prec)
		*len += ft_altbufferhandle(data, n_len);
	else if (!data->buffer_justify
		&& data->arg_perc_on && n_len < data->argument_prec)
		*len += ft_altbufferhandle(data, data->argument_prec);
}

void	ft_hex_ut2(unsigned int n, const char format, int *len, t_format *data)
{
	ft_write_hexa(n, format);
	if (data->buffer_justify && data->arg_perc_on)
		*len += ft_altbufferhandle(data, *len);
}

void	ft_hex_ut3(unsigned int n, int n_len, const char format, int *len)
{
	ft_write_hexa(n, format);
	*len += n_len;
}
