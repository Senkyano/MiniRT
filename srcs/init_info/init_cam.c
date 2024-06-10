/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:57:51 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/10 13:05:06 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	init_cam(t_scene scene, char **arg)
{
	int	tmp;

	if (scene.cam_on)
		return (print_error(RED"ERROR :\nNeed 1 camera\n"RST), false);
	scene.cam_on = true;
	if (!init_coord(&scene.camera.coord, lib_split(arg[1], ",")))
		return (false);
	if (!init_coord(&scene.camera.vecteur, lib_split(arg[2], ",")))
		return (false);
	tmp = lib_atoi(arg[3]);
	if (tmp < 0 || tmp > 180)
		return (print_error(RED"ERROR :\nInvalid fov\n"RST), false);
	scene.camera.fov = tmp;
	return (true);
}
