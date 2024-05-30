/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extrac_rt.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:11:43 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/30 15:39:55 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	extrac_file(char *argv, t_scene *scene)
{
	int		fd;
	char	*line;

	fd = open(argv, O_RDONLY);
	if (fd < 0)
		return (print_error(RED"Error : \nInvalid file\n"RST), false);
	while (1)
	{
		line = get_next_line(fd);
		if (!line)
		{
			return (false);
		}
		
	}
	return (true);
}
