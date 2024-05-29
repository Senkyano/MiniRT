/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/16 11:31:18 by eturiot           #+#    #+#             */
/*   Updated: 2022/11/19 16:56:55 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char			*str_res;
	size_t			lenght;
	unsigned int	i;

	lenght = ft_strlen(s);
	str_res = malloc(sizeof(char) * (lenght + 1));
	if (!str_res)
		return (NULL);
	i = 0;
	while (f && str_res && i < lenght)
	{
		str_res[i] = f(i, s[i]);
		i++;
	}
	str_res[i] = '\0';
	return (str_res);
}
