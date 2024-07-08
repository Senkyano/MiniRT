/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_math.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 11:59:05 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/08 12:34:33 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIB_MATH_H
# define LIB_MATH_H

# include <math.h>
# include "lib_utils.h"

# define X 0
# define Y 1
# define Z 2
# define MIN_VECTOR -1.0
# define MAX_VECTOR 1.0


typedef struct s_coord
{
	double	x;
	double	y;
	double	z;
}	t_coord;

bool	init_coord(t_coord *coord, char *coord_str);

//base math
double	sqr_nbr(double nbr);

//vecteur calcul
double	vec_length(t_coord vec);
t_coord	vec_cross(t_coord vec1, t_coord vec2);
double	vec_dot(t_coord vec1, t_coord vec2);
t_coord	normal_vec(t_coord vec);

#endif
