/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhidalgo <fhidalgo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 12:24:50 by fhidalgo          #+#    #+#             */
/*   Updated: 2026/10/10 15:22:10 by fhidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t				i;
	const unsigned char	*s_a;
	const unsigned char	*s_b;

	s_a = (const unsigned char *)s1;
	s_b = (const unsigned char *)s2;
	i = 0;
	if (n == 0)
		return (0);
	while (i < n)
	{
		if (s_a[i] != s_b[i])
			return ((unsigned char)s_a[i] - (unsigned char)s_b[i]);
		i++;
	}
	return (0);
}
