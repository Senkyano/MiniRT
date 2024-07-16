/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:31 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/16 22:46:53 by rihoy            ###   ########.fr       */
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

typedef struct s_info_hit
{
	bool	hit;
	double	dst;
	t_coord	p;
	t_coord	normal;
}	t_in_hit;

typedef struct s_eq
{
	double	t0;
	double	a;
	double	b;
	double	c;
	double	t1;
	double	discriminant;
}	t_eq;

typedef struct s_objs t_objs;

t_coord		inv_vec(t_coord v);

t_coord		point_of_ray(t_ray ray, double t);
t_in_hit	hit_sphere(t_objs *sphere, t_ray *r);
t_in_hit	hit_plane(t_objs *plane, t_ray *r);
t_coord		unit_vector(t_coord v);

#endif