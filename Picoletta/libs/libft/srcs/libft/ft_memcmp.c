/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 20:04:43 by eturiot           #+#    #+#             */
/*   Updated: 2022/11/28 14:24:54 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*ptr_s1;
	const unsigned char	*ptr_s2;
	size_t				i;

	ptr_s1 = s1;
	ptr_s2 = s2;
	i = 0;
	if (!ptr_s1 || !ptr_s2 || n == 0)
		return (0);
	while (ptr_s1[i] == ptr_s2[i] && (i < n - 1))
		i++;
	return (ptr_s1[i] - ptr_s2[i]);
}
