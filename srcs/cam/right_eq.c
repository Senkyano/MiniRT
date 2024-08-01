/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_eq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:46:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/01 14:01:10 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "minirt.h"

bool	hit_something(t_objs *objs, t_ray *r, t_in_hit *hit, double *dst)
{
	t_in_hit	tmp_hit;

	lib_memset(&tmp_hit, 0, sizeof(t_in_hit));
	if (objs->type == SPHERE)
		tmp_hit = hit_sphere(objs, r);
	else if (objs->type == PLANE)
		tmp_hit = hit_plane(objs, r);
	else if (objs->type == CYLINDER)
		tmp_hit = hit_cylinder(objs, r);
	if (tmp_hit.hit && tmp_hit.dst < (*dst))
	{
		*hit = tmp_hit;
		*dst = tmp_hit.dst;
		return (true);
	}
	return (false);
}

t_rgb	add_ambiant(t_rgb color_objs, t_objs *ambiant)
{
	t_rgb	final;
	double	ratio;

	if (ambiant->ratio == 0)
		ratio = 0;
	else if (ambiant->ratio > 1)
		ratio = 1;
	else
		ratio = ambiant->ratio;
	final.r = ((color_objs.r * ambiant->color.r) / 255) * ratio;
	final.g = ((color_objs.g * ambiant->color.g) / 255) * ratio;
	final.b = ((color_objs.b * ambiant->color.b) / 255) * ratio;
	return (final);
}
