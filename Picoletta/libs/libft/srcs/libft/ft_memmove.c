/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 17:23:28 by eturiot           #+#    #+#             */
/*   Updated: 2023/09/21 11:15:32 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include	"libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t				index;
	const unsigned char	*ptr_src;
	unsigned char		*ptr_dest;

	ptr_src = src;
	ptr_dest = dest;
	index = 0;
	if (ptr_src && ptr_dest && n != 0 && src < dest)
	{
		index = n;
		while (--index)
			ptr_dest[index] = ptr_src[index];
		ptr_dest[0] = ptr_src[0];
	}
	else if (ptr_src && ptr_dest && n != 0)
	{
		while (index < n)
		{
			ptr_dest[index] = ptr_src[index];
			index++;
		}
	}
	return (dest);
}
