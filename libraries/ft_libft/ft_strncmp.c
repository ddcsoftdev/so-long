/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 17:31:13 by ddemarco          #+#    #+#             */
/*   Updated: 2022/03/24 19:25:02 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *str1, const char *str2, size_t n)
{
	unsigned int	i;
	unsigned char	*st1;
	unsigned char	*st2;

	st1 = (unsigned char *)str1;
	st2 = (unsigned char *)str2;
	i = 0;
	while (st1[i] && st2[i] && i < n)
	{
		if (st1[i] != st2[i])
			return (st1[i] - st2[i]);
		i++;
	}
	if (i != n)
		return (st1[i] - st2[i]);
	return (0);
}
