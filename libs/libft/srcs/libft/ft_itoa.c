/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/25 16:12:52 by eturiot           #+#    #+#             */
/*   Updated: 2022/11/23 15:02:45 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static unsigned int	number_size(long n)
{
	unsigned int	size;

	size = 1;
	while (n > 9)
	{
		n /= 10;
		size++;
	}
	return (size);
}

static char	*ft_strnbr(char *str, int sign, long n, int size)
{
	int	index;

	index = size + sign - 1;
	while (index >= sign)
	{
		str[index] = n % 10 + '0';
		n /= 10;
		index--;
	}
	str[size + sign] = '\0';
	return (str);
}

char	*ft_itoa(int n)
{
	int		size;
	int		sign;
	long	long_n;
	char	*res;

	sign = 0;
	long_n = n;
	if (n < 0)
	{
		long_n = -long_n;
		sign = 1;
	}
	size = number_size(long_n);
	res = malloc(sizeof(char) * (size + sign + 1));
	if (!res)
		return (NULL);
	if (sign == 1)
		res[0] = '-';
	res = ft_strnbr(res, sign, long_n, size);
	return (res);
}
