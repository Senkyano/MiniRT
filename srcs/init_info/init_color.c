/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/03 12:38:59 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/03 12:42:57 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	init_color(t_rgb *color, char **arg)
{
	int	i;

	if (!arg)
		return (NULL);
	i = lib_atoi(arg[0]);
	if (i < 0 || i > 255)
		return (free(arg), print_error(RED"Error :\nInvalid color\n"RST), NULL);
	color->r = (char)i;
	i = lib_atoi(arg[1]);
	if (i < 0 || i > 255)
		return (free(arg), print_error(RED"Error :\nInvalid color\n"RST), NULL);
	color->g = (char)i;
	i = lib_atoi(arg[2]);
	if (i < 0 || i > 255)
		return (free(arg), print_error(RED"Error :\nInvalid color\n"RST), NULL);
	color->b = (char)i;
	free(arg);
	return (true);
}
