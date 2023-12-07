/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:52:31 by ddemarco          #+#    #+#             */
/*   Updated: 2022/04/04 11:50:32 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalnum(int num)
{
	int		result;

	if (num >= 48 && num <= 57)
		result = 1;
	else if (num >= 65 && num <= 90)
		result = 1;
	else if (num >= 97 && num <= 122)
		result = 1;
	else
		result = 0;
	return (result);
}
