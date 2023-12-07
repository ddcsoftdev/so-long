/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_int_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:19:10 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/15 15:59:54 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_int_zero(int *n, int n_len, int len, t_format *data)
{
	n_len = 0;
	data->pad_0 = 0;
	len += ft_write_format_n(data, n_len, n) + n_len;
	return (len);
}

void	ft_int_util(int n_len, int *len, t_format *data)
{
	if (!data->buffer_justify && data->arg_perc_on
		&& n_len > data->argument_prec)
		*len += ft_altbufferhandle(data, n_len);
	else if (!data->buffer_justify && data->arg_perc_on
		&& n_len < data->argument_prec)
		*len += ft_altbufferhandle(data, data->argument_prec);
}

void	ft_int_ut2(int n, int *len, t_format *data)
{
	ft_printnbr_fd(n, data, 1);
	if (data->buffer_justify && data->arg_perc_on)
		*len += ft_altbufferhandle(data, *len);
}

void	ft_int_ut3(int n, int n_len, t_format *data, int *len)
{
	ft_printnbr_fd(n, data, 1);
	*len += n_len;
}
