/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eq_sphere.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 12:13:31 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/09 16:24:32 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

bool	eq_sphere(t_objs sphere, t_ray ray, double *t)
{
	t_coord	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	double	t0;
	double	t1;

	oc = sub_vec(ray.origin, sphere.origin);
	a = dot_product(ray.dir, ray.dir);
	b = 2.0 * dot_product(oc, ray.dir);
	c = dot_product(oc, oc) - sqr_nbr(sphere.radius);
	discriminant = sqr_nbr(b) - 4 * a * c;
	if (discriminant < 0)
		return (false);
	t0 = (-b + sqrt(discriminant)) / (2 * a);
	t1 = (-b - sqrt(discriminant)) / (2 * a);
	if (t0 < t1)
		*t = t0;
	else
		*t = t1;
	return (true);
}
