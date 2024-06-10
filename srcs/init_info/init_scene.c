/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_scene.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:12:28 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/10 14:03:47 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_scene(t_scene *scene)
{
	scene->objs = NULL;
	scene->obj_can[0] = 'A';
	scene->obj_can[1] = 'C';
	scene->obj_can[2] = 'L';
	scene->obj_can[3] = 's';
	scene->obj_can[4] = 'c';
	scene->obj_can[5] = 'p';
	scene->f[0] = &init_sphere;
	scene->f[1] = &init_cylinder;
	scene->f[2] = &init_plan;
}
