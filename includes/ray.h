/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:31 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/10 13:23:32 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "lib_math.h"
# include "minirt.h"

# define RAY_T_MIN 0.001
# define RAY_T_MAX 1.0e30

typedef struct s_ray
{
	t_coord	origin;
	t_coord	dir;
}	t_ray;

t_coord	point_of_ray(t_ray ray, double t);

typedef struct s_eq
{
	double	t0;
	double	t1;
	double	discriminant;
}	t_eq;

//(~r - p)*n = 0 (plane equation)
// ray ~r = p + td

#endif