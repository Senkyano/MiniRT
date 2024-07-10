/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:10:12 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/10 15:37:26 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include <math.h>

/* element qui defini si on touche un obj ou pas raytrace + intersection (inter choisis le bonne equation a faire)*/

t_ray	make_ray(t_cam *cam, double u, double v);
void	cam_pep(t_cam *cam, t_objs *info_cam);

void	cam_ray(t_window *window)
{
	t_cam	cam;
	t_ray	ray;
	int	i;
	int	j;
	t_rgb	color;

	lib_memset(&color, 0, sizeof(t_rgb));
	j = -1;
	cam_pep(&cam, window->scene.camera);
	while (j++ < window->img_height)
	{
		i = -1;
		while (++i < window->img_width)
		{
			ray = make_ray(&cam, (double)i / window->img_width, (double)j / window->img_height);
			
			int	color_pixel = color_pix(color.r, color.g, color.b);
			mlx_pixel_put(window->mlx, window->win, i, j, color_pixel);
		}
	}
}

void	cam_pep(t_cam *cam, t_objs *info_cam)
{
	cam->origin = info_cam->origin;
	cam->dir = info_cam->vecteur;
	cam->dir = normal_vec(cam->dir);
	cam->fov = info_cam->fov;
	cam->vec_right = cross_product(cam->dir, (t_coord){0, 1, 0});
	cam->vec_up = cross_product(cam->vec_right, cam->dir);
}

t_ray	make_ray(t_cam *cam, double u, double v)
{
	t_ray	ray;
	t_coord	dir;

	ray.origin = cam->origin;
	dir = add_vec(cam->dir, add_vec(mult_vec(cam->vec_right, u), mult_vec(cam->vec_up, v)));
	dir = normal_vec(dir);
	ray.dir = dir;
	return (ray);
}
