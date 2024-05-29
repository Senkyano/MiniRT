/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:48:52 by eturiot           #+#    #+#             */
/*   Updated: 2023/09/21 10:19:56 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "gnl.h"

ssize_t	find_nl(char *str, char ref)
{
	ssize_t	i;

	i = 0;
	while (str && str[i] && str[i] != '\n')
		i++;
	if (!str || !str[i])
		i = -1;
	if (ref == 0)
		i = ft_strlen(str) - 1;
	return (i);
}

char	*purge_gnl(char *s1, char *s2, char **save)
{
	free(s1);
	free(s2);
	free(*save);
	*save = NULL;
	return (NULL);
}

char	*ft_strjoin_gnl(char **save, char *s2)
{
	char	*s1;
	char	*res;
	size_t	i;
	size_t	j;

	s1 = *save;
	res = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!res)
		return (purge_gnl(NULL, NULL, save));
	i = 0;
	while (s1 && s1[i])
	{
		res[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		res[i++] = s2[j++];
	res[i] = '\0';
	free(*save);
	*save = res;
	return (res);
}

ssize_t	read_check_error(int fd, char *buffer, char **save)
{
	ssize_t	nbytes;

	nbytes = read(fd, buffer, BUFFER_SIZE);
	if (nbytes < 0)
		purge_gnl(NULL, NULL, save);
	else
		buffer[nbytes] = '\0';
	return (nbytes);
}
