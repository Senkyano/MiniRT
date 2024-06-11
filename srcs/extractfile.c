/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:33:39 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/11 16:13:50 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	analysis_file(t_scene *scene, t_file *fd_lines);

bool	extractfile(t_scene *scene, char *file)
{
	int		fd;
	t_file	*fd_lines;
	t_file	*tmp;
	char	*line;

	fd = open(file, O_RDONLY);
	if (fd < 0)
	{
		printf_error(RED"Error\nCan't open file\n"RST);
		return (false);
	}
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = new_line(line);
		if (!tmp)
			return (clear_fd(fd_lines), close(fd), false);
		add_line(&fd_lines, tmp);
	}
	
	return (true);
}

bool	analysis_file(t_scene *scene, t_file *fd_lines)
{
	t_file	*tmp;

	tmp = fd_lines;
	while (tmp)
	{
		
		tmp = tmp->next;
	}
	clear_fd(fd_lines);
	return (true);
}
