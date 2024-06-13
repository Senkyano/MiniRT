/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 16:49:23 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/13 16:54:46 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*init_cylinder(t_objs *obj, char **split, t_scene *scene)
{
	(void)scene;
	if (str_len(split[0]) != 2 || sent_len(split) != 6)
	{
		printf_error(RED"Incorrect type or nbr arguments : %s\n"RST, split[0]);
		return (NULL);
	}
	obj->type = CYLINDER;
	if (!init_coord(&obj->coord, split[1]))
		return (NULL);
	if (!init_coord(&obj->vecteur, split[2]))
		return (NULL);
	if (!is_numberf(split[3]) || !is_numberf(split[4]))
	{
		printf_error(RED"Incorrect type of arguments for cylinder diameter\n"RST);
		return (NULL);
	}
	obj->diameter = lib_atof(split[3]);
	obj->height = lib_atof(split[4]);
	if (!init_color(&obj->color, split[5]))
		return (NULL);
	return (obj);
}
