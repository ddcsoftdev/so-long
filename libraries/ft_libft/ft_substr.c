/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 13:43:31 by ddemarco          #+#    #+#             */
/*   Updated: 2022/04/01 19:26:35 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char		*str;
	size_t		s_len;
	size_t		end;

	if (!s)
		return (0);
	s_len = ft_strlen(s);
	end = 0;
	if (start < s_len)
		end = s_len - start;
	if (end > len)
		end = len;
	str = (char *)malloc(sizeof(char) * (end + 1));
	if (!str)
		return (0);
	ft_strlcpy(str, s + start, end + 1);
	return (str);
}
