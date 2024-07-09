/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point_inter.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:35:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/09 12:31:52 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ray.h"

t_coord	point_of_ray(t_ray ray, double t) // calcule le point d'intersection
{
	t_coord	inter;

	inter.x = ray.origin.x + (t * ray.dir.x);
	inter.y = ray.origin.y + (t * ray.dir.y);
	inter.z = ray.origin.z + (t * ray.dir.z);
	return (inter);
}
