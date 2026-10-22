/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fhidalgo <fhidalgo@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/10/16 16:50:05 by fhidalgo          #+#    #+#             */
/*   Updated: 2026/10/22 16:39:33 by fhidalgo         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static long	power(long n, int pow)
{
	long	res;

	if (pow < 0)
		return (0);
	res = 1;
	while (pow--)
		res = res * n;
	return (res);
}

static void	num_adder(char *dest, int start, long n, size_t len)
{
	long	div;

	div = power(10, len - 1);
	while (len--)
	{
		dest[start] = n / div + '0';
		start++;
		n = n % div;
		div = div / 10;
	}
	dest[start] = '\0';
}

static int	num_len(long n)
{
	int	res;

	res = 0;
	while (n >= 10)
	{
		res++;
		n = n / 10;
	}
	res++;
	return (res);
}

char	*ft_itoa(int n)
{
	char	*nums;
	long	nb;
	int		i;

	nb = n;
	i = 0;
	if (nb < 0)
	{
		nb = -nb;
		nums = malloc(sizeof(char) * (num_len(nb) + 2));
		if (!nums)
			return (NULL);
		nums[i] = '-';
		i++;
	}
	else
	{
		nums = malloc(sizeof(char) * (num_len(nb) + 1));
		if (!nums)
			return (NULL);
	}
	num_adder(nums, i, nb, num_len(nb));
	return (nums);
}

// int main(void)
// {
// 	#include <stdio.h>
// 	int yeah = -34823345;
// 	printf("%s", ft_itoa(yeah));
// 	free(ft_itoa(yeah));
// 	return (0);
// }