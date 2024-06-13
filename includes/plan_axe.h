/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plan_axe.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:44:34 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/13 15:23:05 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PLAN_AXE_H
# define PLAN_AXE_H

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

#endif