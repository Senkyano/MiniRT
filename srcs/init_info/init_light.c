/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 13:04:25 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/10 13:05:52 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	init_light(t_scene scene, char **arg)
{
	if (scene.light_on)
		return (print_error(RED"ERROR :\nNeed 1 light\n"RST), false);
	scene.light_on = true;
	if (!init_coord(&scene.light.coord, lib_split(arg[1], ",")))
		return (false);
	scene.light.ratio = lib_atof(arg[2]);
	if (scene.light.ratio < 0)
		return (print_error(RED"ERROR :\nInvalid brightness\n"RST), false);
	if (!init_color(&scene.light.color, lib_split(arg[3], ",")))
		return (false);
	return (true);
}

bool	init_ambiant(t_scene scene, char **arg)
{
	if (scene.ambiant_on)
		return (print_error(RED"ERROR :\nNeed 1 ambiant light\n"RST), false);
	scene.ambiant_on = true;
	scene.ambiant.ratio = lib_atof(arg[1]);
	if (scene.ambiant.ratio < 0)
	{
		print_error(RED"ERROR :\nInvalid ambiant brightness\n"RST);
		return (false);
	}
	if (!init_color(&scene.ambiant.color, lib_split(arg[2], ",")))
		return (false);
	return (true);
}
