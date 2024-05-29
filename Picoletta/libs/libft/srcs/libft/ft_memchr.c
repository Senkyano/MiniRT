/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 18:10:41 by eturiot           #+#    #+#             */
/*   Updated: 2022/11/28 15:06:08 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char	*ptr_s;
	unsigned char		char_c;
	size_t				i;

	if (s && n > 0)
	{
		ptr_s = s;
		char_c = c;
		i = 0;
		while (i < (n - 1) && ptr_s[i] != char_c)
			i++;
		if (ptr_s[i] == char_c)
			return ((void *)s + i);
	}
	return (NULL);
}
