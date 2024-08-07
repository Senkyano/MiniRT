/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_light.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:17:27 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/07 17:58:15 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*init_light(t_objs *obj, char **split, t_scene *scene)
{
	if (scene->light_on)
		return (printf_error(RED"Only one light is allowed\n"RST), NULL);
	if (scene->light)
	{
		printf_error(RED"Multiple light\n"RST);
		return (NULL);
	}
	if (str_len(split[0]) != 2 && sent_len(split) != 4)
	{
		printf_error(RED"Incorrect type or nbr arguments : %s\n"RST, split[0]);
		return (NULL);
	}
	obj->type = LIGHT;
	scene->light_on = true;
	if (!init_coord(&obj->origin, split[1]))
		return (NULL);
	if (!is_numberf(split[2]))
	{
		printf_error(RED"Incorrect type of arguments for light brightness\n"RST);
		return (NULL);
	}
	obj->ratio = lib_atof(split[2]);
	if (!init_color(&obj->color, split[3]))
		return (NULL);
	return (obj);
}
