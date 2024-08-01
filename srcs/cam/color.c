/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 11:34:29 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/01 16:30:26 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	color_pix(t_rgb	color)
{
	return (color.r << 16 | color.g << 8 | color.b);
}

t_rgb	mult_color_scalar(t_rgb color, double scalar)
{
	t_rgb	result;

	result.r = fmin(color.r * scalar, 255);
	result.g = fmin(color.g * scalar, 255);
	result.b = fmin(color.b * scalar, 255);
	return (result);
}

t_rgb	add_color(t_rgb color1, t_rgb color2)
{
	t_rgb	result;

	result.r = fmin(color1.r + color2.r, 255);
	result.g = fmin(color1.g + color2.g, 255);
	result.b = fmin(color1.b + color2.b, 255);
	return (result);
}
