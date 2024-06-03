/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrac_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:11:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/03 12:54:59 by rihoy            ###   ########.fr       */
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
	}
	return (true);
}
