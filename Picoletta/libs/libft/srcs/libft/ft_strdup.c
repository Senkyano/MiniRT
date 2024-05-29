/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/24 18:34:27 by eturiot           #+#    #+#             */
/*   Updated: 2022/11/14 12:42:42 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h" 

char	*ft_strdup(const char *s)
{
	int		lenght;
	int		index;
	char	*cpy;

	lenght = ft_strlen(s);
	cpy = malloc(sizeof(char) * (lenght + 1));
	if (!cpy)
		return (NULL);
	index = 0;
	while (index < lenght)
	{
		cpy[index] = s[index];
		index++;
	}
	cpy[index] = '\0';
	return ((char *)cpy);
}
