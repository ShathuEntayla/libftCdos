/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhidalgo <fhidalgo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/17 18:54:59 by fhidalgo          #+#    #+#             */
/*   Updated: 2026/10/17 21:20:21 by fhidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*change;

	if (!s || !f)
		return (NULL);
	change = malloc(sizeof(char) * (ft_strlen(s) + 1));
	if (!change)
		return (NULL);
	i = 0;
	while (s[i])
	{
		change[i] = f(i, s[i]);
		i++;
	}
	change[i] = '\0';
	return (change);
}
