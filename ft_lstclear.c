/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhidalgo <fhidalgo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:01:15 by fhidalgo          #+#    #+#             */
/*   Updated: 2026/10/17 21:18:26 by fhidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void*))
{
	t_list	*n_next;

	if ((!lst || !*lst) || !del)
		return ;
	while (*lst)
	{
		n_next = (*lst)->next;
		ft_lstdelone(*lst, del);
		*lst = n_next;
	}
	*lst = NULL;
}
