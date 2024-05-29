/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/19 12:06:11 by eturiot           #+#    #+#             */
/*   Updated: 2022/11/14 15:49:46 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t			i;
	char			*string_dest;
	const char		*string_src;

	string_dest = dest;
	string_src = src;
	i = 0;
	if (dest && src && n != 0)
	{
		while (i < n)
		{
			string_dest[i] = string_src[i];
			i++;
		}
	}
	return (string_dest);
}
