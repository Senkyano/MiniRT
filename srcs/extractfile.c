/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:33:39 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/07 17:37:36 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	analysis_file(t_scene *scene, t_file *fd_lines);
void	sgline_supp(t_file **fd_lines);

bool	primary_items(t_scene *scene)
{
	bool	error;

	error = true;
	if (!scene->camera)
	{
		printf_error(RED"Error\nNo camera\n"RST);
		error = false;
	}
	if (!scene->ambiant)
	{
		printf_error(RED"Error\nNo ambiant\n"RST);
		error = false;
	}
	if (!scene->light)
	{
		printf_error(RED"Error\nNo light\n"RST);
		error = false;
	}
	if (!scene->objs)
	{
		printf_error(RED"Error\nNo objects\n"RST);
		error = false;
	}
	return (error);
}

bool	extractfile(t_scene *scene, char *file)
{
	int		fd;
	t_file	*fd_lines;
	t_file	*tmp;
	char	*line;

	fd_lines = NULL;
	fd = open(file, O_RDONLY);
	if (fd < 0)
		return (printf_error(RED"Error\nCan't open file\n"RST), false);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			break ;
		tmp = new_line(line);
		if (!tmp)
			return (free(line), clear_fd(fd_lines), close(fd), false);
		add_line(&fd_lines, tmp);
	}
	if (!fd_lines)
		return (printf_error(RED"Error\nEmpty file\n"RST), false);
	if (!analysis_file(scene, fd_lines))
		return (false);
	return (true);
}

bool	analysis_file(t_scene *scene, t_file *fd_lines)
{
	t_file	*tmp;
	t_objs	*obj;
	char	**split;

	sgline_supp(&fd_lines);
	tmp = fd_lines;
	(void)scene;
	while (tmp)
	{
		split = lib_split(tmp->line, " 	\n");
		if (!split || !split[0])
			return (clear_fd(fd_lines), false);
		obj = init_obj(scene, split);
		if (!obj)
		{
			printf_error(RED"Error\n%s\n"RST, tmp->line);
			return (clear_fd(fd_lines), clear_objs(&scene->objs), \
			lib_free_split(split), false);
		}
		add_l_objs(&scene->objs, obj);
		lib_free_split(split);
		tmp = tmp->next;
	}
	clear_fd(fd_lines);
	return (true);
}

bool	char_no_whitespaces(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if ((line[i] < 7 || line[i] > 13) && line[i] != 32)
			return (true);
		i++;
	}
	return (false);
}

void	sgline_supp(t_file **fd_lines)
{
	t_file	*tmp;
	t_file	*next;
	t_file	*prev;

	prev = NULL;
	tmp = *fd_lines;
	while (tmp)
	{
		next = tmp->next;
		if (!char_no_whitespaces(tmp->line))
		{
			if (*fd_lines == tmp)
				*fd_lines = next;
			else
				prev->next = next;
			free(tmp->line);
			free(tmp);
		}
		else 
			prev = tmp;
		tmp = next;
	}
}
