/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ddemarco <ddemarco@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/23 15:45:13 by ddemarco          #+#    #+#             */
/*   Updated: 2022/04/04 11:55:50 by ddemarco         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*item;

	if (!del)
		return ;
	while (*lst)
	{
		item = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = item;
	}
	lst = NULL;
}
