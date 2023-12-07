/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_uint_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:19:10 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/15 16:14:36 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_uint_zero(unsigned int *n, int n_len, int len, t_format *data)
{
	n_len = 0;
	data->pad_0 = 0;
	len += ft_write_format_un(data, n_len, n) + n_len;
	return (len);
}

void	ft_uint_util(int n_len, int *len, t_format *data)
{
	if (!data->buffer_justify && data->arg_perc_on
		&& (int)n_len > data->argument_prec)
		*len += ft_altbufferhandle(data, n_len);
	else if (!data->buffer_justify && data->arg_perc_on
		&& (int)n_len < data->argument_prec)
		*len += ft_altbufferhandle(data, data->argument_prec);
}

void	ft_uint_ut2(unsigned int n, int *len, t_format *data)
{
	ft_putnbr_unsig_fd(n, 1);
	if (data->buffer_justify && data->arg_perc_on)
		*len += ft_altbufferhandle(data, *len);
}

void	ft_uint_ut3(unsigned int n, int n_len, int *len)
{
	ft_putnbr_unsig_fd(n, 1);
	*len += n_len;
}
