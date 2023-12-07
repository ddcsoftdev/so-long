/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/04 18:14:59 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/14 15:02:37 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

int	ft_printf(const char *format, ...)
{
	va_list			args;
	t_format		data;
	int				print_len;

	va_start(args, format);
	ft_init_struct(&data);
	print_len = ft_process_arg(format, &args, &data);
	va_end(args);
	return (print_len);
}

int	ft_process_arg(const char *format, va_list *args, t_format *data)
{
	int		print_len;

	print_len = 0;
	while (*format)
	{
		ft_init_struct(data);
		if (*format == '%')
		{
			format++;
			format = ft_check_format(format, data);
			print_len += ft_proc_arg_utl(format, args, data);
		}
		else
		{
			ft_putchar_fd(*format, 1);
			print_len++;
		}
		format++;
	}
	return (print_len);
}

int	ft_proc_arg_utl(const char *format, va_list *args, t_format *data)
{
	int		print_len;

	print_len = 0;
	if (*format == '%')
	{
		ft_putchar_fd(*format, 1);
		print_len++;
	}
	else
		print_len += ft_read_arg(format, args, data);
	return (print_len);
}

int	ft_read_arg(const char *format, va_list *args, t_format *data)
{
	int		len;

	len = 0;
	if (*format == 'c')
		len = ft_print_char(va_arg(*args, TYPE_CHAR), data);
	else if (*format == 'i' || *format == 'd')
		len = ft_print_int(va_arg(*args, TYPE_INT), data);
	else if (*format == 's')
		len = ft_print_str(va_arg(*args, TYPE_STR), data);
	else if (*format == 'p')
		len = ft_print_pointer(va_arg(*args, TYPE_PTR), data);
	else if (*format == 'u')
		len = ft_print_unsigned(va_arg(*args, TYPE_UNSIGNED), data);
	else if (*format == 'x')
		len = ft_print_hexa(va_arg(*args, TYPE_HEXA), *format, data);
	else if (*format == 'X')
		len = ft_print_hexa(va_arg(*args, TYPE_HEXA), *format, data);
	return (len);
}
