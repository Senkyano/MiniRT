/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eq_plane.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:03:29 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/09 13:54:53 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

bool	plane_inter(t_ray ray, t_objs plane, double *t)
{
	double	denom;
	double	numer;
	t_coord	origin_to_plane;

	denom = dot_product(normal_vec(plane.vecteur), ray.dir);
	if (denom < 0.0)
		return (false);
	origin_to_plane = sub_vec(plane.origin, ray.origin);
	numer = dot_product(origin_to_plane, normal_vec(plane.vecteur));
	*t = numer / denom;
	if (*t <= RAY_T_MIN || *t >= RAY_T_MAX)
		return (false);
	return (true);
}
