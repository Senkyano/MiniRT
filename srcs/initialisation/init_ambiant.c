/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_ambiant.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 17:20:27 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/13 17:45:29 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*init_ambiant(t_objs *obj, char **split, t_scene *scene)
{
	if (scene->ambiant)
	{
		printf_error(RED"Multiple ambiant light\n"RST);
		return (NULL);
	}
	if (str_len(split[0]) != 2 && sent_len(split) != 3)
	{
		printf_error(RED"Incorrect type or nbr arguments : %s\n"RST, split[0]);
		return (NULL);
	}
	obj->type = AMBIANT;
	scene->ambiant_on = true;
	if (!is_numberf(split[1]))
	{
		printf_error(RED"Incorrect type of arguments for ambiant brightness\n"RST);
		return (NULL);
	}
	obj->ratio = lib_atof(split[1]);
	if (!init_color(&obj->color, split[2]))
		return (NULL);
	return (obj);
}
