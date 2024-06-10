/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrac_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:11:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/10 14:20:07 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	extrac_file(char *argv, t_scene *scene)
{
	int		fd;
	char	*line;
	char	**split;
	t_objs	*obj;

	init_scene(scene);
	fd = 0;
	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (print_error(RED"Error : \nInvalid file\n"RST), false);
	line = get_next_line(fd);
	if (!line)
		return (print_error(RED"Error Malloc\n"RST), false);
	while (line)
	{
		line = get_next_line(fd);
		if (!line)
			return (false);
		printf("%s\n", line);
		split = lib_split(line, "	");
		if (split[0] != NULL)
		{
			free(line);
			obj = init_obj(split, scene);
			free(split);
			if (!obj)
				return (false);
			l_add_obj(&scene->objs, obj);
		}
		else
		{
			free(line);
			free(split);
			break ;
		}
	}
	return (close(fd), true);
}
