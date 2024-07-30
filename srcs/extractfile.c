/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractfile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:33:39 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/29 14:56:51 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	analysis_file(t_scene *scene, t_file *fd_lines);
void	sgline_supp(t_file **fd_lines);

bool	extractfile(t_scene *scene, char *file)
{
	int		fd;
	t_file	*fd_lines;
	t_file	*tmp;
	char	*line;

	fd_lines = NULL;
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
			return (free(line), clear_fd(fd_lines), close(fd), false);
		add_line(&fd_lines, tmp);
	}
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
	while (tmp)
	{
		split = lib_split(tmp->line, " 	\n");
		if (!split)
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
		if (line[i] < 7 || line[i] > 13)
			return (true);
		i++;
	}
	return (false);
}

void	sgline_supp(t_file **fd_lines)
{
	t_file	*tmp;
	t_file	*tmp_check;

	tmp = *fd_lines;
	while (tmp)
	{
		tmp_check = tmp;
		tmp = tmp->next;
		if (!char_no_whitespaces(tmp_check->line))
		{
			if (!tmp_check->prev)
				fd_lines = &tmp;
			else
				tmp_check->prev->next = tmp;
			tmp->prev = tmp_check->prev;
			free(tmp_check->line);
			free(tmp_check);
		}
	}
}
