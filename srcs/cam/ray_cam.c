/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:10:12 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/12 12:59:20 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"
#include "ray.h"
#include <math.h>

/* element qui defini si on touche un obj ou pas raytrace + intersection 
(inter choisis le bonne equation a faire)*/

t_ray	build_camray(t_objs *o_cam, double x, double y);
t_rgb	ray_color(t_ray r, t_objs *objs, t_window *window);

void	cam_ray(t_window *window)
{
	t_ray	ray;
	int		color;
	int		i;
	int		j;

	j = -1;
	while (j++ < window->img_height)
	{
		i = -1;
		while (++i < window->img_width)
		{
			ray = build_camray(window->scene.camera, i, j);
			color = color_pix(ray_color(ray, window->scene.objs, window));
			mlx_pixel_put(window->mlx, window->win, i, j, color);
		}
	}
}

t_rgb	ray_color(t_ray r, t_objs *objs, t_window *window)
{
	double	a;
	t_objs	*tmp;

	tmp = objs;
	(void)window;
	while (tmp)
	{
		if (tmp->type == SPHERE)
		{
			a = hit_sphere(tmp, &r);
			if (a > 0.0)
				return (tmp->color);
		}
		if (tmp->type == PLANE)
		{
			a = hit_plane(tmp, &r);
			if (a > 0.0)
				return (tmp->color);
		}
		tmp = tmp->next;
	}
	return ((t_rgb){0, 0, 0});
}

t_coord	cam_to_world(t_cam *cam, t_coord dir)
{
	t_coord	new_dir;

	new_dir.x = cam->vec_right.x * dir.x + cam->vec_up.x
		* dir.y + cam->vec_forward.x * dir.z;
	new_dir.y = cam->vec_right.y * dir.x + cam->vec_up.y
		* dir.y + cam->vec_forward.y * dir.z;
	new_dir.z = cam->vec_right.z * dir.x + cam->vec_up.z
		* dir.y + cam->vec_forward.z * dir.z;
	return (new_dir);
}

t_ray	build_camray(t_objs *o_cam, double x, double y)
{
	t_ray	ray;
	t_cam	cam;

	ray.origin = o_cam->origin;
	cam.origin = o_cam->origin;
	cam.vec_forward = normalize(o_cam->vecteur);
	cam.vec_right = cross_product(cam.vec_forward, (t_coord){0, 1, 0});
	cam.vec_up = cross_product(cam.vec_right, cam.vec_forward);
	cam.dir.x = (2.0 * (x + 0.5) / (double)WIN_WIDTH - 1)
		* tan(o_cam->fov / 2 * PI / 180.0)
		* ((double)((double)WIN_WIDTH / (double)WIN_HEIGHT));
	cam.dir.y = (1.0 - 2.0 * (y + 0.5) / (double)WIN_HEIGHT)
		* tan(o_cam->fov / 2 * PI / 180.0);
	cam.dir.z = FOCAL_DIST;
	cam.dir = cam_to_world(&cam, cam.dir);
	cam.dir = normalize(cam.dir);
	ray.dir = cam.dir;
	return (ray);
}
