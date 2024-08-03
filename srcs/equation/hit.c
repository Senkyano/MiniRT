/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:11:12 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/03 02:36:54 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_in_hit	hit_infite_cylinder(t_objs *cyl, t_ray *r);

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
	eq.t1 = (-eq.b + sqrt(eq.discriminant)) / (2 * eq.a);
	eq.t0 = (-eq.b - sqrt(eq.discriminant)) / (2 * eq.a);
	if (eq.t0 > 0.0001 && eq.t0 < RAY_T_MAX)
		hit.dst = eq.t0;
	else if (eq.t1 > 0.0001 && eq.t1 < RAY_T_MAX)
		hit.dst = eq.t1;
	else
		return (hit);
	hit.hit = true;
	hit.p = point_of_ray(*r, hit.dst);
	hit.normal = normalize(sub_vec(hit.p, sphere->origin));
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

double	distance(t_coord p1, t_coord p2)
{
	return (sqrt(sqr_nbr(p1.x - p2.x) + sqr_nbr(p1.y - p2.y) + \
	sqr_nbr(p1.z - p2.z)));
}

t_in_hit	hit_cylinder(t_objs *objs, t_ray *r)
{
	t_in_hit	hit;
	t_in_hit	tmp;
	t_objs		pl;

	lib_memset(&hit, 0, sizeof(t_in_hit));
	hit.dst = INFINITY;
	pl.origin = objs->origin;
	pl.vecteur = objs->vecteur;
	tmp = hit_plane(&pl, r);
	if (tmp.hit && distance(tmp.p, objs->origin) <= objs->radius && hit.dst > tmp.dst)
		hit = tmp;
	pl.origin = add_vec(objs->origin, mult_vec(objs->vecteur, objs->height));
	tmp = hit_plane(&pl, r);
	if (tmp.hit && distance(tmp.p, add_vec(objs->origin, mult_vec(objs->vecteur, objs->height))) <= objs->radius && hit.dst > tmp.dst)
		hit = tmp;
	// tmp = hit_infite_cylinder(objs, r);
	// if (tmp.hit && distance(tmp.p, objs->origin) <= objs->height && hit.dst > tmp.dst)
	// 	hit = tmp;
	return (hit);
}
