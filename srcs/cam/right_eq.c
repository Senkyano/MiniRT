/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   right_eq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 13:46:54 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/07 15:28:04 by rihoy            ###   ########.fr       */
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

void	add_rlight(t_info_obj *obj_info, t_in_hit *a,
t_objs *light, t_objs *objs)
{
	t_coord		light_dir;
	double		intensity;
	t_ray		shadow_ray;
	t_in_hit	shadow_hit;
	t_objs		*shadow_obj;

	light_dir = sub_vec(light->origin, a->p);
	light_dir = normalize(light_dir);
	shadow_ray.origin = a->p;
	shadow_ray.dir = light_dir;
	lib_memset(&shadow_hit, 0, sizeof(t_in_hit));
	shadow_obj = closest_hit(objs, &shadow_ray, &shadow_hit);
	if (shadow_obj && shadow_hit.dst < vec_length(sub_vec(light->origin, a->p)))
	{
		obj_info->final_c = obj_info->c_ambiant;
		return ;
	}
	intensity = dot_product(a->normal, light_dir);
	intensity = (fmax(0, intensity) / distance(a->p, light->origin)) * light->ratio;
	obj_info->c_diffuse = add_color(obj_info->c_ambiant, \
	mult_color_scalar(light->color, intensity));
	obj_info->final_c = add_color(obj_info->final_c, obj_info->c_diffuse);
}
