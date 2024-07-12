/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:31 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/12 12:44:21 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "lib_math.h"
# include "minirt.h"
# include "lib_utils.h"

# define RAY_T_MIN 0.001
# define RAY_T_MAX 1.0e30

typedef struct s_ray
{
	t_coord	origin;
	t_coord	dir;
}	t_ray;

typedef struct s_eq
{
	double	t0;
	double	t1;
	double	discriminant;
}	t_eq;

typedef struct s_objs t_objs;

t_coord	point_of_ray(t_ray ray, double t);
double	hit_sphere(t_objs *sphere, t_ray *r);
double	hit_plane(t_objs *plane, t_ray *r);

#endif