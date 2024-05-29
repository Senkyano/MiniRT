/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/10/23 18:07:35 by eturiot           #+#    #+#             */
/*   Updated: 2023/09/18 15:54:10 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_word(char const *s, char sep)
{
	int		flag;
	size_t	i;
	size_t	counter;

	counter = 0;
	i = 0;
	flag = 1;
	while (s && s[i])
	{
		if (s[i] != sep && flag == 1)
			counter++;
		if (s[i] == sep)
			flag = 1;
		else
			flag = 0;
		i++;
	}
	return (counter);
}

static char	*insert(char const *s, size_t size)
{
	char	*res_str;
	size_t	i;	

	res_str = malloc(sizeof(char) * (size + 1));
	if (res_str == NULL)
		return (NULL);
	i = 0;
	while (i < size && s[i])
	{
		res_str[i] = s[i];
		i++;
	}
	res_str[i] = '\0';
	return (res_str);
}

static char	**free_all_past_string(char **res_str, size_t index)
{
	while (index)
	{
		free(res_str[--index]);
		res_str[index] = NULL;
	}
	free(res_str);
	res_str = NULL;
	return (res_str);
}

char	**ft_split(char const *s, char c)
{
	char	**res_str;
	size_t	count;
	size_t	index;
	size_t	size;

	count = count_word(s, c);
	res_str = malloc(sizeof(char *) * (count + 1));
	if (res_str == NULL)
		return (NULL);
	index = 0;
	while (index < count)
	{
		size = 0;
		while (*s == c)
			s++;
		while (s[size] != c && s[size] != '\0')
			size++;
		res_str[index] = insert(s, size);
		if (res_str[index] == NULL)
			return (free_all_past_string(res_str, index));
		s += size + 1;
		index++;
	}
	res_str[index] = NULL;
	return (res_str);
}
