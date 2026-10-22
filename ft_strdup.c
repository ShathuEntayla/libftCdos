/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhidalgo <fhidalgo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/09/24 10:11:19 by fhidalgo          #+#    #+#             */
/*   Updated: 2026/10/10 17:03:47 by fhidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	int		i;
	char	*copia;

	copia = (char *) malloc ((ft_strlen(src) + 1) * sizeof(char));
	if (copia == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		copia[i] = src[i];
		i++;
	}
	copia[i] = '\0';
	return (copia);
}
