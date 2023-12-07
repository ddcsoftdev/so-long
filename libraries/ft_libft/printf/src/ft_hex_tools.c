/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hexa_tools.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/22 20:19:10 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/15 15:46:56 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_hexa_len(unsigned int n, int *len)
{
	if (n >= 16)
	{
		ft_hexa_len(n / 16, len);
		ft_hexa_len(n % 16, len);
	}
	else
		*len = *len + 1;
}

void	ft_put_hexa(unsigned int n, const char format)
{
	if (n >= 16)
	{
		ft_put_hexa(n / 16, format);
		ft_put_hexa(n % 16, format);
	}
	else
	{
		if (n <= 9)
			ft_putchar_fd(n + 48, 1);
		else
		{
			if (format == 'x')
				ft_putchar_fd((n - 10) + 'a', 1);
			else if (format == 'X')
				ft_putchar_fd((n - 10) + 'A', 1);
		}
	}
}

void	ft_write_hexa(unsigned int n, const char format)
{
	if (n == 0)
		ft_putchar_fd(n + 48, 1);
	else
		ft_put_hexa(n, format);
}

int	ft_print_hexa(unsigned int n, const char format, t_format *data)
{
	int		len;
	int		n_len;

	len = 0;
	n_len = 0;
	ft_hexa_len(n, &n_len);
	if (data->arg_perc_on && n == 0)
		return (ft_hex_zero(&n, n_len, len, data));
	if (data->active_format && !data->justify_left)
	{
		ft_hex_util(n_len, &len, data);
		len += ft_write_format_un(data, n_len, &n) + n_len;
		len += ft_sharp_flag(n, data, format);
		ft_hex_ut2(n, format, &len, data);
	}
	else if (data->active_format && data->justify_left)
	{
		len += ft_sharp_flag(n, data, format);
		ft_write_hexa(n, format);
		len += ft_write_format_un(data, n_len, &n) + n_len;
	}
	else if (!data->active_format)
		ft_hex_ut3(n, n_len, format, &len);
	return (len);
}
