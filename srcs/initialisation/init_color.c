/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_color.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 14:43:05 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/10 13:19:40 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	all_inrange(char **color_split);

bool	init_color(t_rgb *color, char *color_str)
{
	char	**color_split;

	color_split = lib_split(color_str, ",");
	if (!color_split)
		return (false);
	if (sent_len(color_split) != 3)
	{
		printf_error(RED"Incorrect number of arguments for color\n"RST);
		return (lib_free_split(color_split), false);
	}
	if (!is_number(color_split[0]) || !is_number(color_split[1]) || \
	!is_number(color_split[2]))
	{
		printf_error(RED"Incorrect type of arguments for color\n"RST);
		return (lib_free_split(color_split), false);
	}
	if (!all_inrange(color_split))
		return (lib_free_split(color_split), false);
	color->r = lib_atoi(color_split[0]);
	color->g = lib_atoi(color_split[1]);
	color->b = lib_atoi(color_split[2]);
	lib_free_split(color_split);
	return (true);
}

bool	all_inrange(char **color_split)
{
	if (lib_atoi(color_split[0]) < 0 || lib_atoi(color_split[0]) > 255)
	{
		printf_error(RED"Color value out of range\n"RST);
		return (false);
	}
	if (lib_atoi(color_split[1]) < 0 || lib_atoi(color_split[1]) > 255)
	{
		printf_error(RED"Color value out of range\n"RST);
		return (false);
	}
	if (lib_atoi(color_split[2]) < 0 || lib_atoi(color_split[2]) > 255)
	{
		printf_error(RED"Color value out of range\n"RST);
		return (false);
	}
	return (true);
}
