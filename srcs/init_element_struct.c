/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_element_struct.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 16:34:11 by eturiot           #+#    #+#             */
/*   Updated: 2024/06/10 16:54:45 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool	setup_ambiant(t_ambient *ambient, char *str)
{
	bool	is_set;

	is_set = false;
	if (ambient->is_set = false)
	{
		is_set = true;
	}
	else
		ft_printf_fd(2, "ERROR\n%s\n", ENB_AMBIENT);
	return (is_set);
}

bool	setup_camera(t_camera *camera, char *str)
{
	bool	is_set;

	is_set = false;
	if (camera->is_set = false)
	{
		is_set = true;
	}
	else
		ft_printf_fd(2, "ERROR\n%s\n", ENB_CAMERA);
	return (is_set);
}

bool	setup_light(t_light *light, char *str)
{
	bool	is_set;

	is_set = false;
	if (light->is_set = false)
	{
		is_set = true;
	}
	else
		ft_printf_fd(2, "ERROR\n%s\n", ENB_LIGHT);
	return (is_set);
}

bool	setup_object(t_objet *obj, char *str)
{
	bool	is_set;
	t_object	tmp;

	is_set = false;
	if (light->is_set = false)
	{
		is_set = true;
	}
	else
		ft_printf_fd(2, "ERROR\n%s\n", ENB_LIGHT);
	return (is_set);
	//si tmp est good alors suce

}
