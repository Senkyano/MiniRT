/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:11:12 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/26 14:56:13 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_in_hit	hit_sphere(t_objs *sphere, t_ray *r)
{
	t_eq		eq;
	t_in_hit	hit;

	lib_memset(&hit, 0, sizeof(t_in_hit));
	eq.a = dot_product(r->dir, r->dir);
	eq.b = 2 * dot_product(sub_vec(r->origin, sphere->origin), r->dir);
	eq.c = dot_product(sub_vec(r->origin, sphere->origin), \
	sub_vec(r->origin, sphere->origin)) - (sphere->radius * sphere->radius);
	eq.discriminant = sqr_nbr(eq.b) - 4 * eq.a * eq.c;
	if (eq.discriminant < 0.0)
		return (hit);
	eq.t0 = (-eq.b + sqrt(eq.discriminant)) / (2 * eq.a);
	eq.t1 = (-eq.b - sqrt(eq.discriminant)) / (2 * eq.a);
	if (eq.t0 < 0.0001 && eq.t1 < 0.0001)
		return (hit);
	hit.hit = true;
	if (eq.t0 < 0.0001 || eq.t0 < RAY_T_MAX)
		hit.dst = eq.t1;
	else if (eq.t1 < 0.0001 || eq.t1 < RAY_T_MAX)
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

t_in_hit hit_cylinder(t_objs *cylinder, t_ray *r)
{
	t_in_hit	hit;
	t_eq 		eq;
	t_coord		p_to_cyl_base;
	t_coord 	cyl_to_p;
	double		height_along_axis;

	lib_memset(&hit, 0, sizeof(t_in_hit));
	t_coord dir_cross_cyl = cross_product(r->dir, cylinder->vecteur);
	t_coord deltaP_cross_cyl = cross_product(sub_vec(r->origin, cylinder->origin), cylinder->vecteur);
	eq.a = dot_product(dir_cross_cyl, dir_cross_cyl);
	eq.b = 2 * dot_product(dir_cross_cyl, deltaP_cross_cyl);
	eq.c = dot_product(deltaP_cross_cyl, deltaP_cross_cyl) - (sqr_nbr(cylinder->radius));
	eq.discriminant = sqr_nbr(eq.b) - 4 * eq.a * eq.c;
	if (eq.discriminant < 0)
		return (hit);
	eq.t0 = (-eq.b - sqrt(eq.discriminant)) / (2 * eq.a);
	eq.t1 = (-eq.b + sqrt(eq.discriminant)) / (2 * eq.a);
	if (eq.t0 < 0.0001 && eq.t1 < 0.0001)
		return (hit);
	if (eq.t0 < 0.0001 || eq.t0 > RAY_T_MAX)
		hit.dst = eq.t1;
	else
		hit.dst = eq.t0;
	hit.p = point_of_ray(*r, hit.dst);
	p_to_cyl_base = sub_vec(hit.p, cylinder->origin);
	height_along_axis = dot_product(p_to_cyl_base, cylinder->vecteur);
	if (height_along_axis < 0 || height_along_axis > cylinder->height)
		return (hit);
	hit.hit = true;
	cyl_to_p = mult_vec(cylinder->vecteur, height_along_axis);
	hit.normal = unit_vector(sub_vec(p_to_cyl_base, cyl_to_p));
	return (hit);
}

t_coord	inv_vec(t_coord v)
{
	return ((t_coord){-v.x, -v.y, -v.z});
}
