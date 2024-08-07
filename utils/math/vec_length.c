/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_length.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:06:39 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/07 17:59:59 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_math.h"

double	vec_length(t_coord vec)
{
	return (sqrt((vec.x * vec.x) + (vec.y * vec.y) + (vec.z * vec.z)));
}

double	distance(t_coord p1, t_coord p2)
{
	return (sqrt(sqr_nbr(p1.x - p2.x) + sqr_nbr(p1.y - p2.y) + \
	sqr_nbr(p1.z - p2.z)));
}
