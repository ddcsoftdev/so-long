/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:04:39 by ddemarco          #+#    #+#             */
/*   Updated: 2022/03/28 12:13:09 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *src, char const *set)
{
	size_t		size;
	char		*str;

	if (!src || !set)
		return (NULL);
	while (*src && ft_strchr(set, *src))
		src++;
	size = ft_strlen(src);
	while (size && ft_strchr(set, src[size]))
		size--;
	str = ft_substr((char *)src, 0, size + 1);
	return (str);
}
