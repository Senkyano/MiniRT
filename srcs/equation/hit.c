/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/12 11:11:12 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/16 20:05:00 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_in_hit	hit_sphere(t_objs *sphere, t_ray *r)
{
	t_coord	oc;
	double	a;
	double	b;
	double	c;
	double	discriminant;
	t_in_hit	hit;

	lib_memset(&hit, 0, sizeof(t_in_hit));
	oc = sub_vec(r->origin, sphere->origin);
	a = dot_product(r->dir, r->dir);
	b = dot_product(oc, r->dir) * 2; 
	c = dot_product(oc, oc) - sqr_nbr(sphere->radius);
	discriminant = sqr_nbr(b) - 4 * a * c;
	if (discriminant >= 0)
	{
		hit.hit = true;
		hit.dst = -b - sqrt(discriminant) / (2 * a);
		hit.p = point_of_ray(*r, hit.dst);
		hit.normal = unit_vector(sub_vec(hit.p, sphere->origin));
		return (hit);
	}
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
	return (hit);
}
