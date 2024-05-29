/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/15 20:29:36 by eturiot           #+#    #+#             */
/*   Updated: 2022/11/23 15:04:02 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	check_occurence(char c, char const *set)
{
	int	i;

	i = 0;
	while (set && set[i])
	{
		if (set[i] == c)
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*res_str;
	int		lenght;
	int		i_count;
	int		i;

	lenght = ft_strlen(s1) - 1;
	i_count = 0;
	while (s1 && check_occurence(s1[i_count], set))
		i_count++;
	while (s1 && check_occurence(s1[lenght], set) && lenght >= i_count)
		lenght--;
	res_str = malloc(sizeof(char) * (lenght - i_count + 2));
	if (!res_str)
		return (NULL);
	i = 0;
	while (i_count <= lenght)
		res_str[i++] = s1[i_count++];
	res_str[i] = '\0';
	return (res_str);
}
