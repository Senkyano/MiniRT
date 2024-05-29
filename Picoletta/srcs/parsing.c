/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 15:33:12 by eturiot           #+#    #+#             */
/*   Updated: 2024/05/29 15:33:15 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

static bool	check_file_extension(const char *file)
{
	bool	is_valid;
	int		len;

	is_valid = false;
	len = ft_strlen(file);
	if (len >= EXTENSION_SIZE && file[--len] == 't')
	{
		if (file[--len] == 'r')
		{
			if (file[--len] == '.')
				is_valid = true;
		}
	}
	return (is_valid);
}


bool	parsing(t_element *scene, char *file)
{
	bool	is_valid;
	int		fd;

	is_valid = false;
	if (file && file[0] && check_file_extension(file))
	{
		fd = open(file, O_RDONLY);
		if (fd >= 0)
		{
			if (extractor(scene, fd)) //tmp
				is_valid = true;
			close(fd);
		}
		else
		{
			ft_printf("here %d\n", errno);
			ft_printf_fd(2, "Error\n%s\n", strerror(errno));
		}
	}
	else
		ft_printf_fd(2, "Error\n%s\n", EEXTENSION);
	return (is_valid);
}