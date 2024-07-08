/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vec_dotcross.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:11:17 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/08 12:30:30 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_math.h"

// a faire

double	vec_dot(t_coord vec1, t_coord vec2)
{
	double	dot;

	dot = (vec1.x * vec2.x) + (vec1.y * vec2.y) + (vec1.z * vec2.z);
	return (dot);
}

t_coord	vec_cross(t_coord vec1, t_coord vec2)
{
	t_coord	cross;

	cross.x = (vec1.y * vec2.z) - (vec1.z * vec2.y);
	cross.y = (vec1.z * vec2.x) - (vec1.x * vec2.z);
	cross.z = (vec1.x * vec2.y) - (vec1.y * vec2.x);
	return (cross);
}
