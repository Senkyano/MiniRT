/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plane.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:59:44 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/13 17:03:35 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*init_plane(t_objs *obj, char **split, t_scene *scene)
{
	(void)scene;
	if (str_len(split[0]) != 2 && sent_len(split) != 4)
	{
		printf_error(RED"Incorrect type or nbr arguments : %s\n"RST, split[0]);
		return (NULL);
	}
	obj->type = PLANE;
	if (!init_coord(&obj->coord, split[1]))
		return (NULL);
	if (!init_coord(&obj->vecteur, split[2]))
		return (NULL);
	if (!init_color(&obj->color, split[3]))
		return (NULL);
	return (obj);
}
