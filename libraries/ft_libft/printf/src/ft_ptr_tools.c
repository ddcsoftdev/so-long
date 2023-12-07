/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_ptr_tools.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 11:31:12 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/14 15:32:54 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_ptr_len(unsigned long long ptr, int *len)
{
	if (ptr >= 16)
	{
		ft_ptr_len(ptr / 16, len);
		ft_ptr_len(ptr % 16, len);
	}
	else
		*len = *len + 1;
}

void	ft_put_longhex(unsigned long long ptr)
{
	if (ptr >= 16)
	{
		ft_put_longhex(ptr / 16);
		ft_put_longhex(ptr % 16);
	}
	else
	{
		if (ptr <= 9)
			ft_putchar_fd(ptr + 48, 1);
		else
			ft_putchar_fd((ptr - 10) + 'a', 1);
	}
}

void	ft_write_ptr(unsigned long long ptr)
{
	ft_putstr_fd("0x", 1);
	if (ptr == 0)
		ft_putnbr_fd(0, 1);
	else
		ft_put_longhex(ptr);
}

int	ft_print_pointer(unsigned long long ptr, t_format *data)
{
	int		len;
	int		n_len;

	len = 0;
	n_len = 2;
	ft_ptr_len(ptr, &n_len);
	if (data->active_format && !data->justify_left)
	{
		len += ft_write_format(data, n_len) + n_len;
		ft_write_ptr(ptr);
	}
	else if (data->active_format && data->justify_left)
	{
		ft_write_ptr(ptr);
		len += ft_write_format(data, n_len) + n_len;
	}
	else if (!data->active_format)
	{
		ft_write_ptr(ptr);
		len += n_len;
	}
	return (len);
}
