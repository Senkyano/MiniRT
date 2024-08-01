/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:48:27 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/01 16:24:13 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef COLOR_H
# define COLOR_H

# define MIN_COLOR 0
# define MAX_COLOR 255

typedef struct s_rgb
{
	unsigned char	r;
	unsigned char	g;
	unsigned char	b;
}	t_rgb;

bool	init_color(t_rgb *color, char *color_str);
int		color_pix(t_rgb	color);
t_rgb	mult_color_scalar(t_rgb color, double scalar);
t_rgb	add_color(t_rgb color1, t_rgb color2);

#endif