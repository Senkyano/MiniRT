/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:08:48 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/30 18:42:40 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_coord	init_coord(char **arg)
{
	t_coord	coord;

	coord.x = ft_atof(arg[0]);
	coord.y = ft_atof(arg[1]);
	coord.z = ft_atof(arg[2]);
	return (coord);
}
