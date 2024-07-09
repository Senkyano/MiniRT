/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   normal_vec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 12:08:39 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/09 13:48:35 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_math.h"

t_coord	normal_vec(t_coord vec)
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