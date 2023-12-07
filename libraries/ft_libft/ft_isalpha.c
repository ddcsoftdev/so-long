/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 12:27:43 by ddemarco          #+#    #+#             */
/*   Updated: 2022/04/04 11:50:40 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isalpha(int num)
{
	int		result;

	if (num >= 65 && num <= 90)
		result = 1;
	else if (num >= 97 && num <= 122)
		result = 1;
	else
		result = 0;
	return (result);
}
