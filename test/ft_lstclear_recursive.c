/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhidalgo <fhidalgo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:01:15 by fhidalgo          #+#    #+#             */
/*   Updated: 2026/10/16 16:39:12 by fhidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*ref;

	if (!lst || !del)
		return ;
	while (*lst)
	{
		ref = (*lst)->next;
		del((*lst)->content);
		free(*lst);
		ft_lstdelone(*lst, del)
	}
	*lst = NULL
}

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	if ((!lst || !*lst) || !del)
		return ;
	ft_lstclear(&((*lst)->next), del);
	ft_lstdelone(*lst, del);
	*lst = NULL
}