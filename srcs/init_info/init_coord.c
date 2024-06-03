/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:34:55 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/03 12:36:26 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	init_coord(t_coord *coord, char **arg)
{
	if (!arg)
		return (NULL);
	coord->x = lib_atof(arg[0]);
	coord->y = lib_atof(arg[1]);
	coord->z = lib_atof(arg[2]);
	free(arg);
	return (true);
}
