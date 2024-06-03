/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cylinder.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:52:24 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/03 12:53:01 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*init_cylinder(t_objs *obj, char **arg)
{
	obj->type = CYLINDER;
	if (!init_coord(&obj->coord, lib_split(arg[1], ',')))
		return (NULL);
	if (!init_coord(&obj->vecteur, lib_split(arg[2], ',')))
		return (NULL);
	obj->diameter = lib_atof(arg[3]);
	if (obj->diameter < 0)
		return (print_error(RED"Error : \nInvalid diameter\n"RST), NULL);
	obj->height = lib_atof(arg[4]);
	if (obj->height < 0)
		return (print_error(RED"Error : \nInvalid height\n"RST), NULL);
	if (!init_color(&obj->color, lib_split(arg[5], ',')))
		return (NULL);
	obj->next = NULL;
	return (obj);
}
