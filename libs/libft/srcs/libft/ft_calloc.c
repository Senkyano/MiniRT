/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/14 14:33:25 by eturiot           #+#    #+#             */
/*   Updated: 2022/11/21 18:07:12 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nmemb, size_t size)
{
	void	*ptr;

	if (nmemb != 0 && nmemb * size / nmemb != size)
		return (NULL);
	ptr = malloc(size * nmemb);
	if (ptr != NULL && nmemb > 0 && size > 0)
		ft_bzero(ptr, nmemb * size);
	return (ptr);
}
