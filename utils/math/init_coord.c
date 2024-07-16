/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_coord.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:28:29 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/16 22:17:56 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_math.h"

bool	init_coord(t_coord *coord, char *coord_str)
{
	char	**coord_split;

	lib_memset(coord, 0, sizeof(t_coord));
	coord_split = lib_split(coord_str, ",");
	if (!coord_split)
		return (false);
	if (sent_len(coord_split) != 3)
	{
		printf_error(RED"Incorrect number of arguments for coord\n"RST);
		return (lib_free_split(coord_split), false);
	}
	if (!is_numberf(coord_split[0]) || !is_numberf(coord_split[1]) || \
	!is_numberf(coord_split[2]))
	{
		printf_error(RED"Incorrect type of arguments for coord\n"RST);
		return (lib_free_split(coord_split), false);
	}
	coord->x = lib_atof(coord_split[0]);
	coord->y = lib_atof(coord_split[1]);
	coord->z = lib_atof(coord_split[2]);
	return (lib_free_split(coord_split), true);
}
