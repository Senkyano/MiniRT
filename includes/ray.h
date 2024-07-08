/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:39:31 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/08 14:39:05 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAY_H
# define RAY_H

# include "lib_math.h"

typedef struct s_ray
{
	t_coord	origin;
	t_coord	direction;
}	t_ray;

//(~r - p)*n = 0 (plane equation)
// ray ~r = p + td

#endif