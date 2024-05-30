/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_sphere.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:48:41 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/30 18:47:22 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	*init_sphere(t_objs *obj, char **arg)
{
	char	**tmp;

	if (ft_tablen(arg) != 4)
		return (NULL);
	obj->type = SPHERE;
	tmp = lib_split(arg[1], ',');
	if (!tmp)
		return (NULL);
	obj->coord = init_coord(tmp);
	return ((void *)obj);
}
