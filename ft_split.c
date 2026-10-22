/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhidalgo <fhidalgo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/10 21:41:51 by fhidalgo          #+#    #+#             */
/*   Updated: 2026/10/17 18:21:40 by fhidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	**str_null_complete(char **grid, int index)
{
	grid[index] = NULL;
	return (grid);
}

static void	*free_all(char **grid, int index)
{
	index--;
	while (index >= 0)
		free(grid[index--]);
	free(grid);
	return (NULL);
}

static int	count_words(char const *s, char c)
{
	int	i;
	int	words;

	words = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			words++;
			while (s[i] && s[i] != c)
				i++;
		}
	}
	return (words);
}

static int	count_letters(char const *s, char c)
{
	int	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char	**ft_split(char const *s, char c)
{
	char	**grid;
	int		i;
	int		j;

	if (!s)
		return (NULL);
	grid = malloc(sizeof(char *) * (count_words(s, c) + 1));
	if (!grid)
		return (NULL);
	i = 0;
	j = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i])
		{
			grid[j] = ft_substr(s, i, count_letters(&s[i], c));
			if (!grid[j])
				return (free_all(grid, j));
			i = i + count_letters(&s[i], c);
			j++;
		}
	}
	return (str_null_complete(grid, j));
}
