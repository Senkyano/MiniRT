/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:11:12 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/29 15:40:35 by rihoy            ###   ########.fr       */
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
	hit.dst = INFINITY;
	t_coord dir_cross_cyl = cross_product(r->dir, cylinder->vecteur);
	t_coord deltaP_cross_cyl = cross_product(sub_vec(r->origin, cylinder->origin), cylinder->vecteur);
	eq.a = dot_product(dir_cross_cyl, dir_cross_cyl);
	eq.b = 2 * dot_product(dir_cross_cyl, deltaP_cross_cyl);
	eq.c = dot_product(deltaP_cross_cyl, deltaP_cross_cyl) - (sqr_nbr(cylinder->radius));
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
	p_to_cyl_base = sub_vec(hit.p, cylinder->origin);
	height_along_axis = dot_product(p_to_cyl_base, cylinder->vecteur);
	if (height_along_axis < 0 || height_along_axis > cylinder->height)
	{
		double t_cap_top = 0, t_cap_bottom;
		bool hit_cap_top = false, hit_cap_bottom = false;
		t_coord cap_normal = cylinder->vecteur;
		t_coord normalized_vecteur = normalize(cylinder->vecteur);
		// Intersection avec le cap inférieur
		t_coord bottom_cap_center = cylinder->origin;
		double t_to_bottom_cap = dot_product(sub_vec(bottom_cap_center, r->origin), cap_normal) / dot_product(r->dir, cap_normal);
		if (t_to_bottom_cap > 0.0001 && t_to_bottom_cap < RAY_T_MAX)
		{
			t_coord p_bottom_cap = point_of_ray(*r, t_to_bottom_cap);
			if (vec_length(sub_vec(p_bottom_cap, bottom_cap_center)) <= cylinder->radius)
			{
				hit_cap_bottom = true;
				t_cap_bottom = t_to_bottom_cap;
			}
		}
		// Intersection avec le cap supérieur
		t_coord top_cap_center = add_vec(cylinder->origin, mult_vec(normalized_vecteur, cylinder->height)); // Centre du cap supérieur
		double t_to_top_cap = dot_product(sub_vec(top_cap_center, r->origin), normalized_vecteur) / dot_product(r->dir, normalized_vecteur);
		if (t_to_top_cap > 0.0001 && t_to_top_cap < RAY_T_MAX)
		{
			t_coord p_top_cap = point_of_ray(*r, t_to_top_cap);
			if (vec_length(sub_vec(p_top_cap, top_cap_center)) <= cylinder->radius)
			{
				hit_cap_top = true;
				t_cap_top = t_to_top_cap;
			}
		}
		// Déterminer le point d'intersection le plus proche
		if (hit_cap_bottom || hit_cap_top)
		{
			if (hit_cap_bottom && (!hit_cap_top || t_cap_bottom < t_cap_top))
			{
				hit.hit = true;
				hit.dst = t_cap_bottom;
				hit.p = point_of_ray(*r, t_cap_bottom);
				hit.normal = inv_vec(cap_normal); // Normale dirigée vers le bas pour le cap inférieur
			}
			else if (hit_cap_top)
			{
				hit.hit = true;
				hit.dst = t_cap_top;
				hit.p = point_of_ray(*r, t_cap_top);
				hit.normal = cap_normal; // Normale dirigée vers le haut pour le cap supérieur
			}
		}
		return (hit);
	}
	hit.hit = true;
	cyl_to_p = mult_vec(cylinder->vecteur, height_along_axis);
	hit.normal = unit_vector(sub_vec(p_to_cyl_base, cyl_to_p));
	return (hit);
}

t_coord	inv_vec(t_coord v)
{
	return ((t_coord){-v.x, -v.y, -v.z});
}
