/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_plan.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:47:49 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/03 12:52:05 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*init_plan(t_objs *obj, char **arg)
{
	obj->type = PLANE;
	if (!init_coord(&obj->coord, lib_split(arg[1], ',')))
		return (NULL);
	if (!init_coord(&obj->vecteur, lib_split(arg[2], ',')))
		return (NULL);
	if (!init_color(&obj->color, lib_split(arg[3], ',')))
		return (NULL);
	obj->next = NULL;
	return (obj);
}