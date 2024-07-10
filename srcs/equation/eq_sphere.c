/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eq_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:13:31 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/10 13:24:48 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

bool	eq_sphere(t_objs sphere, t_ray ray, double *t)
{
	t_coord	oc;
	double	a;
	double	b;
	double	c;
	t_eq	eq;

	oc = sub_vec(ray.origin, sphere.origin);
	a = dot_product(ray.dir, ray.dir);
	b = 2.0 * dot_product(oc, ray.dir);
	c = dot_product(oc, oc) - sqr_nbr(sphere.radius);
	eq.discriminant = sqr_nbr(b) - 4 * a * c;
	if (eq.discriminant < 0)
		return (false);
	eq.t0 = (-b + sqrt(eq.discriminant)) / (2 * a);
	eq.t1 = (-b - sqrt(eq.discriminant)) / (2 * a);
	if (eq.t0 < eq.t1)
		*t = eq.t0;
	else
		*t = eq.t1;
	return (true);
}
