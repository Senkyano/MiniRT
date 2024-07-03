/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:10:12 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/03 14:37:42 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	camRay(t_window *window)
{
	//render

	int	i = 0;
	int	j = 0;
	t_rgb	color;
	int color_value;

	printf("window->img_width = %d, window->img_height = %d\n", window->img_width, window->img_height);
	lib_memset(&color, 0, sizeof(t_rgb));
	while (j < window->img_height)
	{
		i = 0;
		while (i < window->img_width)
		{
			double r = (double)i / window->img_width;
			double g = (double)j / window->img_height;
			double b = 0.65;

			// printf("r = %f, g = %f, b = %f\n", r, g, b);
			color.r = (int)(255.999 * r);
			color.g = (int)(255.999 * g);
			color.b = (int)(255.999 * b);
			
			color_value = (color.r << 16) | (color.g << 8) | color.b;
			mlx_pixel_put(window->mlx, window->win, i, j, color_value);
			i++;
		}
		j++;
	}
}
