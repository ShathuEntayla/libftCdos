/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhidalgo <fhidalgo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/06 18:11:42 by fhidalgo          #+#    #+#             */
/*   Updated: 2026/10/06 21:20:56 by fhidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	s_src;
	size_t	s_dst;

	s_src = ft_strlen(src);
	s_dst = 0;
	i = 0;
	while (dst[s_dst] && s_dst < size)
		s_dst++;
	if (s_dst == size)
		return (s_src + size);
	while (src[i] && i + s_dst + 1 < size)
	{
		dst[i + s_dst] = src[i];
		i++;
	}
	dst[i + s_dst] = '\0';
	return (s_src + s_dst);
}
