/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:35:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/02 20:24:53 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"
#include "minirt.h"

t_coord	point_of_ray(t_ray ray, double t)
{
	t_coord	inter;

	inter.x = ray.origin.x + (t * ray.dir.x);
	inter.y = ray.origin.y + (t * ray.dir.y);
	inter.z = ray.origin.z + (t * ray.dir.z);
	return (inter);
}

// int	intersection(t_ray *r, t_objs *obj, double *t)
// {
// 	if (obj->type == SPHERE)
// 		return (eq_sphere(obj, r, t));
// 	if (obj->type == PLANE)
// 		return (plane_inter(r, obj, t));
// 	return (0);
// }
