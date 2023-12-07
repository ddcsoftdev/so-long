/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/21 16:36:16 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/15 16:14:10 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_print_char(char c, t_format *data)
{
	int		len;

	len = 0;
	if (data->active_format && !data->justify_left)
	{
		len += ft_write_format(data, 1) + 1;
		ft_putchar_fd(c, 1);
	}
	else if (data->active_format && data->justify_left)
	{
		ft_putchar_fd(c, 1);
		len += ft_write_format(data, 1) + 1;
	}
	else if (!data->active_format)
	{
		ft_putchar_fd(c, 1);
		len += 1;
	}
	return (len);
}

int	ft_print_int(int n, t_format *data)
{
	int		len;
	int		n_len;

	len = 0;
	n_len = ft_getnum_len(n, data);
	if (data->arg_perc_on && n == 0)
		return (ft_int_zero(&n, n_len, len, data));
	if (data->buffer <= 0 && data->space_bf_value && n >= 0 && ++len)
		ft_putchar_fd(' ', 1);
	if (data->active_format && !data->justify_left)
	{
		ft_int_util(n_len, &len, data);
		ft_write_sign(data, &n, &len);
		len += ft_write_format_n(data, n_len, &n) + n_len;
		ft_int_ut2(n, &len, data);
	}
	else if (data->active_format && data->justify_left)
	{
		ft_write_sign(data, &n, &len);
		ft_printnbr_fd(n, data, 1);
		len += ft_write_format_n(data, n_len, &n) + n_len;
	}
	else if (!data->active_format)
		ft_int_ut3(n, n_len, data, &len);
	return (len);
}

int	ft_print_str(char *str, t_format *data)
{
	int		len;
	int		strlen;

	len = 0;
	if (!str)
		str = "(null)";
	strlen = ft_strlen(str);
	if (data->active_format && !data->buffer_justify)
	{
		len += ft_write_format(data, strlen) + strlen;
		len -= ft_printstr_fd(str, data, &strlen, 1);
	}
	else if (data->active_format && data->buffer_justify)
	{	
		ft_printstr_fd(str, data, &strlen, 1);
		len += ft_write_format(data, strlen) + strlen;
	}
	else if (!data->active_format)
	{
		ft_putstr_fd(str, 1);
		len += strlen;
	}
	return (len);
}

int	ft_print_unsigned(unsigned int n, t_format *data)
{
	int				len;
	unsigned int	n_len;

	len = 0;
	n_len = ft_unsig_num_len(n);
	if (data->arg_perc_on && n == 0)
		return (ft_uint_zero(&n, n_len, len, data));
	if (data->active_format && !data->justify_left)
	{
		ft_uint_util(n_len, &len, data);
		len += ft_write_format_un(data, n_len, &n) + n_len;
		ft_uint_ut2(n, &len, data);
	}
	else if (data->active_format && data->justify_left)
	{
		ft_putnbr_unsig_fd(n, 1);
		len += ft_write_format_un(data, n_len, &n) + n_len;
	}
	else if (!data->active_format)
		ft_uint_ut3(n, n_len, &len);
	return (len);
}
