/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 13:42:48 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/10 13:19:33 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*init_sphere(t_objs *obj, char **split, t_scene *scene)
{
	(void)scene;
	if (str_len(split[0]) != 2 || sent_len(split) != 4)
	{
		printf_error(RED"Incorrect type or nbr arguments : %s\n"RST, split[0]);
		return (NULL);
	}
	obj->type = SPHERE;
	if (!init_coord(&obj->origin, split[1]))
		return (NULL);
	if (!is_numberf(split[2]))
	{
		printf_error(RED"Incorrect type of arguments for sphere radius\n"RST);
		return (NULL);
	}
	obj->radius = lib_atof(split[2]) / 2;
	if (!init_color(&obj->color, split[3]))
		return (NULL);
	return (obj);
}
