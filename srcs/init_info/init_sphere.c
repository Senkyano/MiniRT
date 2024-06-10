/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:33:10 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/10 13:06:49 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*init_sphere(t_objs *obj, char **arg)
{
	obj->type = SPHERE;
	if (!init_coord(&obj->coord, lib_split(arg[1], ",")))
		return (NULL);
	obj->diameter = lib_atof(arg[2]);
	if (obj->diameter < 0)
		return (print_error(RED"Error : \nInvalid diameter\n"RST), NULL);
	if (!init_color(&obj->color, lib_split(arg[3], ",")))
		return (NULL);
	obj->next = NULL;
	return (obj);
}
