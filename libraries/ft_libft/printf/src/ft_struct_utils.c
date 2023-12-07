/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_struct_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 22:11:51 by ddemarco          #+#    #+#             */
/*   Updated: 2022/05/14 15:03:16 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/ft_printf.h"

void	ft_init_struct(t_format *format_data)
{
	format_data->active_format = 0;
	format_data->buffer = 0;
	format_data->buffer2 = 0;
	format_data->justify_left = 0;
	format_data->buffer_justify = 0;
	format_data->pad_0 = 0;
	format_data->arg_perc_on = 0;
	format_data->argument_prec = 0;
	format_data->print_sign = 0;
	format_data->space_bf_value = 0;
	format_data->preceed_val = 0;
	format_data->sharp = 0;
}
