/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhidalgo <fhidalgo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 11:16:14 by fhidalgo          #+#    #+#             */
/*   Updated: 2026/10/10 18:58:13 by fhidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*s_a;

	s_a = (const unsigned char *)s;
	while (n > 0)
	{
		if (*s_a == (unsigned char)c)
			return ((void *)s_a);
		s_a++;
		n--;
	}
	return (NULL);
}
