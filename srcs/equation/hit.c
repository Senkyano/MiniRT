/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:11:12 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/16 22:59:13 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_in_hit	hit_sphere(t_objs *sphere, t_ray *r)
{
	t_eq		eq;
	t_in_hit	hit;
	
	lib_memset(&hit, 0, sizeof(t_in_hit));
	hit.dst = INFINITY;
	eq.a = dot_product(r->dir, r->dir);
	eq.b = 2 * dot_product(sub_vec(r->origin, sphere->origin), r->dir);
	eq.c = dot_product(sub_vec(r->origin, sphere->origin), \
	sub_vec(r->origin, sphere->origin)) - (sphere->radius * sphere->radius);
	eq.discriminant = eq.b * eq.b - 4 * eq.a * eq.c;
	if (eq.discriminant < 0)
		return (hit);
	eq.t0 = (-eq.b + sqrt(eq.discriminant)) / (2 * eq.a);
	eq.t1 = (-eq.b - sqrt(eq.discriminant)) / (2 * eq.a);
	if (eq.t0 < 0.0001 && eq.t1 < 0.0001)
		return (hit);
	hit.hit = true;
	if (eq.t0 < 0.0001 || eq.t0 > eq.t1)
		hit.dst = eq.t1;
	else
		hit.dst = eq.t0;
	hit.p = point_of_ray(*r, hit.dst);
	hit.normal = unit_vector(sub_vec(hit.p, sphere->origin));
	return (hit);
}

t_in_hit	hit_plane(t_objs *plane, t_ray *r)
{
	double		dotn;
	double		t;
	t_in_hit	hit;

	lib_memset(&hit, 0, sizeof(t_in_hit));
	hit.dst = INFINITY;
	dotn = dot_product(plane->vecteur, r->dir);
	if (dotn == 0.0)
		return (hit);
	t = dot_product(sub_vec(r->origin, plane->origin), plane->vecteur) / dotn;
	if (t < 0.0001)
		return (hit);
	hit.hit = true;
	hit.dst = t;
	hit.p = point_of_ray(*r, t);
	hit.normal = plane->vecteur;
	if (dot_product(hit.normal, r->dir) > 0)
		hit.normal = inv_vec(hit.normal);
	return (hit);
}

t_coord	inv_vec(t_coord v)
{
	return ((t_coord){-v.x, -v.y, -v.z});
}
