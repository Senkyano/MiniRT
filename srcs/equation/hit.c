/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:11:12 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/12 12:59:37 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	hit_sphere(t_objs *sphere, t_ray *r)
{
	t_coord	oc;
	double	a;
	double	b;
	double	c;
	double	t1;
	double	t2;
	double	discriminant;

	oc = sub_vec(r->origin, sphere->origin);
	a = dot_product(r->dir, r->dir);
	b = 2.0 * dot_product(oc, r->dir);
	c = dot_product(oc, oc) - sqr_nbr(sphere->radius);
	discriminant = sqr_nbr(b) - 4 * a * c;
	if (discriminant < 0)
		return (0);
	t1 = (-b - sqrt(discriminant)) / (2.0 * a);
	t2 = (-b + sqrt(discriminant)) / (2.0 * a);
	if (t1 > RAY_T_MIN && t1 < RAY_T_MAX)
		return (t1);
	else if (t2 > RAY_T_MIN && t2 < RAY_T_MAX)
		return (t2);
	return (0);
}

double	hit_plane(t_objs *plane, t_ray *r)
{
	(void)plane;
	(void)r;
	return (0);
}
