/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:08:39 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/01 13:38:36 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_math.h"

t_coord	normalize(t_coord vec)
{
	double	length;

	length = vec_length(vec);
	vec.x /= length;
	vec.y /= length;
	vec.z /= length;
	return (vec);
}

t_coord	sub_vec(t_coord vec1, t_coord vec2)
{
	t_coord	sub;

	sub.x = vec1.x - vec2.x;
	sub.y = vec1.y - vec2.y;
	sub.z = vec1.z - vec2.z;
	return (sub);
}

t_coord	add_vec(t_coord vec1, t_coord vec2)
{
	t_coord	add;

	add.x = vec1.x + vec2.x;
	add.y = vec1.y + vec2.y;
	add.z = vec1.z + vec2.z;
	return (add);
}

t_coord	mult_vec(t_coord vec1, double d)
{
	t_coord	mult;

	mult.x = (double)(vec1.x * d);
	mult.y = (double)(vec1.y * d);
	mult.z = (double)(vec1.z * d);
	return (mult);
}

t_coord	invert_vec(t_coord vec)
{
	t_coord	invert;

	invert.x = -vec.x;
	invert.y = -vec.y;
	invert.z = -vec.z;
	return (invert);
}
