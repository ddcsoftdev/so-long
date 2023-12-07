/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 14:12:53 by ddemarco          #+#    #+#             */
/*   Updated: 2023/03/04 14:41:13 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;

	if (!lst)
		return (0);
	i = 0;
	while (lst)
	{
		lst = lst->next;
		i++;
	}
	return (i);
}
