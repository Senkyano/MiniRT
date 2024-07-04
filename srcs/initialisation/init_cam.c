/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_cam.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:10:47 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/04 09:59:58 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*init_cam(t_objs *obj, char **split, t_scene *scene)
{
	if (scene->cam_on)
		return (printf_error(RED"Only one camera is allowed\n"RST), NULL);
	if (str_len(split[0]) != 2 && sent_len(split) != 4)
	{
		printf_error(RED"Incorrect type or nbr arguments : %s\n"RST, split[0]);
		return (NULL);
	}
	obj->type = CAM;
	scene->cam_on = true;
	if (!init_coord(&obj->origin, split[1]))
		return (NULL);
	if (!init_coord(&obj->vecteur, split[2]))
		return (NULL);
	if (!is_number(split[3]))
	{
		printf_error(RED"Incorrect type of arguments for camera fov\n"RST);
		return (NULL);
	}
	obj->fov = lib_atoi(split[3]);
	if (obj->fov < 0 || obj->fov > 180)
	{
		printf_error(RED"Camera fov must be between 0 and 180\n"RST);
		return (NULL);
	}
	return (obj);
}
