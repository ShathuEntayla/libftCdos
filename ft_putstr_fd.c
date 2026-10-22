/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhidalgo <fhidalgo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 11:30:05 by fhidalgo          #+#    #+#             */
/*   Updated: 2026/10/16 12:06:14 by fhidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putstr_fd(char *c, int fd)
{
	unsigned int	i;
	unsigned int	s_len;

	i = 0;
	s_len = ft_strlen(c);
	if (!c)
		return ;
	while (c[i] && i < s_len)
	{
		ft_putchar_fd(c[i], fd);
		i++;
	}
}
