/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/21 18:20:24 by ddemarco          #+#    #+#             */
/*   Updated: 2023/03/18 17:06:05 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t		i;
	size_t		j;

	i = 0;
	if (needle[i] == '\0')
		return ((char *)haystack);
	while (haystack[i] && i < n)
	{
		j = 0;
		if (haystack[i] == needle[j])
		{
			while ((i + j < n) && (haystack[i + j] == needle[j]))
			{
				j++;
				if (!needle[j])
					return ((char *)&haystack[i]);
			}
		}
		i++;
	}
	return (0);
}
