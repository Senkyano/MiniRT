/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:11:12 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/16 22:37:01 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// t_in_hit	hit_sphere(t_objs *sphere, t_ray *r)
// {
// 	t_coord		oc;
// 	double		tca;
// 	double		d2;
// 	double		thc;
// 	double		t2;
// 	t_in_hit	hit;

// 	lib_memset(&hit, 0, sizeof(t_in_hit));
// 	hit.dst = INFINITY;
// 	oc = sub_vec(r->origin, sphere->origin);
// 	tca = dot_product(oc, r->dir);
// 	if (tca < 0)
// 		return (hit);
// 	d2 = dot_product(oc, oc) - tca * tca;
// 	if (d2 > sphere->radius)
// 		return (hit);
// 	thc = sqrt(sphere->radius - d2);
// 	hit.dst = tca - thc;
// 	t2 = tca + thc;
// 	if (hit.dst < 0.0001 && t2 < 0.0001)
// 		return (hit);
// 	hit.hit = true;
// 	if (hit.dst < 0.0001 || hit.dst > t2)
// 		hit.dst = t2;
// 	hit.p = point_of_ray(*r, hit.dst);
// 	hit.normal = unit_vector(sub_vec(hit.p, sphere->origin));
// 	return (hit);
// }

t_in_hit	hit_sphere(t_objs *sphere, t_ray *r)
{
	double		a;
	double		b;
	double		c;
	double		discriminant;
	double		t0;
	double		t1;
	t_in_hit	hit;
	
	lib_memset(&hit, 0, sizeof(t_in_hit));
	hit.dst = INFINITY;
	a = dot_product(r->dir, r->dir);
	b = 2 * dot_product(sub_vec(r->origin, sphere->origin), r->dir);
	c = dot_product(sub_vec(r->origin, sphere->origin), sub_vec(r->origin, sphere->origin)) - (sphere->radius * sphere->radius);
	discriminant = b * b - 4 * a * c;
	if (discriminant < 0)
		return (hit);
	t0 = (-b + sqrt(discriminant)) / (2 * a);
	t1 = (-b - sqrt(discriminant)) / (2 * a);
	if (t0 < 0.0001 && t1 < 0.0001)
		return (hit);
	hit.hit = true;
	if (t0 < 0.0001 || t0 > t1)
		hit.dst = t1;
	else
		hit.dst = t0;
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
	t = dot_product(sub_vec(plane->origin, r->origin), plane->vecteur) / dotn;
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
