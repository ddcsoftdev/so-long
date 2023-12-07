/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/22 14:35:55 by ddemarco          #+#    #+#             */
/*   Updated: 2022/04/04 13:28:29 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_nb_words(char const *s, char c)
{
	size_t		i;
	int			size_arr;

	i = 0;
	size_arr = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		while (s[i] != c && s[i])
			i++;
		if (s[i - 1] != c)
			size_arr++;
	}
	return (size_arr);
}

static int	populate_tab(char const *s, char c, char **str, int str_len)
{
	int		start;
	int		j;
	int		i;

	start = 0;
	j = -1;
	i = 0;
	while (++j < str_len)
	{
		while (s[i] == c)
			i++;
		start = i;
		while (s[i] != c && s[i])
			i++;
		str[j] = ft_substr(s, start, i - start);
		if (!str[j])
		{
			while (--j >= 0)
				free(str[j]);
			return (-1);
		}
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	int			str_len;
	char		**str;
	int			i;

	if (!s)
		return (NULL);
	str_len = get_nb_words(s, c);
	str = malloc(sizeof(str) * (str_len + 1));
	if (!str)
		return (NULL);
	i = populate_tab(s, c, str, str_len);
	if (i == -1)
	{
		free(str);
		return (NULL);
	}
	str[i] = 0;
	return (str);
}
