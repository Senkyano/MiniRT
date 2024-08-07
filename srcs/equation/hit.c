/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:11:12 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/07 18:02:00 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_in_hit	hit_sphere(t_objs *sphere, t_ray *r)
{
	t_eq		eq;
	t_in_hit	hit;

	lib_memset(&hit, 0, sizeof(t_in_hit));
	hit.dst = INFINITY;
	eq.u = sub_vec(r->origin, sphere->origin);
	eq.a = dot_product(r->dir, r->dir);
	eq.b = 2 * dot_product(sub_vec(r->origin, sphere->origin), r->dir);
	eq.c = dot_product(eq.u, eq.u) - sqr_nbr(sphere->radius);
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

bool	solve_equa(t_objs *objs, t_ray *r, t_eq *eq, t_in_hit *tmp_hit)
{
	eq->u = cross_product(r->dir, objs->vecteur);
	eq->v = sub_vec(r->origin, objs->origin);
	eq->v = cross_product(eq->v, objs->vecteur);
	eq->a = dot_product(eq->u, eq->u);
	eq->b = 2 * dot_product(eq->u, eq->v);
	eq->c = dot_product(eq->v, eq->v) - sqr_nbr(objs->radius);
	eq->discriminant = sqr_nbr(eq->b) - 4 * eq->a * eq->c;
	eq->t1 = (-eq->b + sqrt(eq->discriminant)) / (2.0 * eq->a);
	eq->t0 = (-eq->b - sqrt(eq->discriminant)) / (2.0 * eq->a);
	if (eq->discriminant < 0.0)
		return (false);
	if (eq->t0 < 0.0001 && eq->t1 < 0.0001)
		return (false);
	if (eq->t0 > 0.0001 && eq->t0 < RAY_T_MAX)
		tmp_hit->dst = eq->t0;
	else if (eq->t1 > 0.0001 && eq->t1 < RAY_T_MAX)
		tmp_hit->dst = eq->t1;
	else
		return (false);
	return (true);
}

void	hit_fini_cylinder(t_objs *objs, t_ray *r, t_in_hit *tmp_hit)
{
	t_eq	eq;
	double	height_projection;

	lib_memset(tmp_hit, 0, sizeof(t_in_hit));
	tmp_hit->dst = INFINITY;
	if (!solve_equa(objs, r, &eq, tmp_hit))
		return ;
	tmp_hit->hit = true;
	tmp_hit->p = point_of_ray(*r, tmp_hit->dst);
	tmp_hit->normal = normalize(sub_vec(sub_vec(tmp_hit->p, objs->origin), \
	mult_vec(objs->vecteur, dot_product(sub_vec(tmp_hit->p, objs->origin), \
	objs->vecteur))));
	height_projection = dot_product(sub_vec(tmp_hit->p, objs->origin), \
	objs->vecteur);
	if (height_projection <= 0 || height_projection >= objs->height)
	{
		tmp_hit->hit = false;
		tmp_hit->dst = INFINITY;
	}
	if (dot_product(tmp_hit->normal, r->dir) > 0)
		tmp_hit->normal = inv_vec(tmp_hit->normal);
}

t_in_hit	hit_cylinder(t_objs *objs, t_ray *r)
{
	t_in_hit	hit;
	t_in_hit	tmp;
	t_objs		pl;

	lib_memset(&hit, 0, sizeof(t_in_hit));
	hit.dst = INFINITY;
	pl = *objs;
	tmp = hit_plane(&pl, r);
	if (tmp.hit && distance(tmp.p, objs->origin) <= objs->radius
		&& hit.dst > tmp.dst)
		hit = tmp;
	pl.origin = add_vec(objs->origin,
			mult_vec(objs->vecteur, objs->height));
	tmp = hit_plane(&pl, r);
	if (tmp.hit && distance(tmp.p, pl.origin) <= objs->radius
		&& hit.dst > tmp.dst)
		hit = tmp;
	hit_fini_cylinder(objs, r, &tmp);
	if (tmp.hit && hit.dst > tmp.dst)
		hit = tmp;
	return (hit);
}
