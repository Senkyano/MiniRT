/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 02:48:16 by eturiot           #+#    #+#             */
/*   Updated: 2023/11/22 12:58:01 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "gnl.h"

char	*save_and_return(ssize_t tag, char **save)
{
	char	*res;
	char	*temp;
	ssize_t	i;

	temp = NULL;
	res = malloc(sizeof(char) * (tag + 2));
	if (res)
	{	
		i = -1;
		while (++i <= tag && (*save)[i])
			res[i] = (*save)[i];
		res[i] = '\0';
		temp = malloc(sizeof(char *) * (ft_strlen((*save) + i) + 1));
	}
	if (!res || !temp || res[0] == '\0')
		return (purge_gnl(res, temp, save));
	tag = 0;
	while ((*save)[i])
		temp[tag++] = (*save)[i++];
	temp[tag] = '\0';
	free(*save);
	if (temp[0] == '\0')
		purge_gnl(NULL, NULL, &temp);
	*save = temp;
	return (res);
}

char	*get_next_line(int fd)
{
	char		buffer[BUFFER_SIZE + 1];
	ssize_t		newline;
	static char	*save = NULL;

	buffer[0] = -1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	newline = find_nl(save, -1);
	while (newline < 0 && read_check_error(fd, buffer, &save) >= 0)
	{
		newline = find_nl(buffer, -1);
		if (!ft_strjoin_gnl(&save, buffer) || buffer[0] == '\0')
			break ;
	}
	return (save_and_return(find_nl(save, buffer[0]), &save));
}
