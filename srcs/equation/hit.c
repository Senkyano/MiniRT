/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:11:12 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/02 16:11:30 by rihoy            ###   ########.fr       */
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

t_coord	inv_vec(t_coord v)
{
	return ((t_coord){-v.x, -v.y, -v.z});
}

// t_in_hit	circle_plane(t_objs *cir, t_ray *r)
// {
	
// }

t_in_hit	hit_cylinder(t_objs *cyl, t_ray *r)
{
	t_in_hit	hit;
	t_eq		eq;
	t_coord		r_cross_cyl;
	t_coord		ocrossd;
	double		heigth;

	lib_memset(&hit, 0, sizeof(t_in_hit));
	r_cross_cyl = sub_vec(r->origin, cyl->origin);
	ocrossd = cross_product(r->dir, cyl->vecteur);
	eq.a = dot_product(ocrossd, ocrossd);
	eq.b = 2 * dot_product(ocrossd, cross_product(r_cross_cyl, cyl->vecteur));
	eq.c = dot_product(cross_product(r_cross_cyl, cyl->vecteur), \
	cross_product(r_cross_cyl, cyl->vecteur)) - sqr_nbr(cyl->radius);
	eq.discriminant = sqr_nbr(eq.b) - 4 * eq.a * eq.c;
	if (eq.discriminant < 0.0)
		return (hit);
	eq.t0 = (-eq.b - sqrt(eq.discriminant)) / (2 * eq.a);
	eq.t1 = (-eq.b + sqrt(eq.discriminant)) / (2 * eq.a);
	if (eq.t0 > 0.0001 && eq.t0 < RAY_T_MAX)
		hit.dst = eq.t0;
	else if (eq.t1 > 0.0001 && eq.t1 < RAY_T_MAX)
		hit.dst = eq.t1;
	else
		return (hit);
	hit.p = point_of_ray(*r, hit.dst);
	heigth = dot_product(sub_vec(hit.p, cyl->origin), cyl->vecteur);
	if (heigth <= 0 || heigth >= cyl->height)
		return (hit);
	hit.hit = true;
	hit.normal = normalize(sub_vec(sub_vec(hit.p, cyl->origin), \
	mult_vec(cyl->vecteur, heigth)));
	return (hit);
}
