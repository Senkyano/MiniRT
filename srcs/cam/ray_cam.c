/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:10:12 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/16 20:00:48 by rihoy            ###   ########.fr       */
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

t_objs	*closest_hit(t_objs *obj, t_ray *r, t_in_hit *info_hit)
{
	t_objs		*tmp;
	t_objs		*closest_obj;
	double		t_dst;
	t_in_hit	tmp_info_hit;

	tmp = obj;
	lib_memset(&tmp_info_hit, 0, sizeof(t_in_hit));
	closest_obj = NULL;
	t_dst = INFINITY;
	tmp_info_hit.dst = INFINITY;
	while (tmp)
	{
		if (tmp->type == SPHERE)
		{
			tmp_info_hit = hit_sphere(tmp, r);
			if (tmp_info_hit.hit && tmp_info_hit.dst < t_dst)
			{
				*info_hit = tmp_info_hit;
				t_dst = tmp_info_hit.dst;
				closest_obj = tmp;
			}
		}
		if (tmp->type == PLANE)
		{
			tmp_info_hit = hit_plane(tmp, r);
			if (tmp_info_hit.hit && tmp_info_hit.dst < t_dst)
			{
				*info_hit = tmp_info_hit;
				t_dst = tmp_info_hit.dst;
				closest_obj = tmp;
			}
		}
		tmp = tmp->next;
	}
	return (closest_obj);
}

t_rgb	ray_color(t_ray r, t_objs *objs, t_window *window)
{
	t_in_hit	a;
	t_objs	*tmp;

	(void)window;
	lib_memset(&a, 0, sizeof(t_in_hit));
	tmp = closest_hit(objs, &r, &a);
	if (a.hit)
		return (tmp->color);
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
	cam.vec_right = cross_product((t_coord){0, 1, 0}, cam.vec_forward);
	cam.vec_up = cross_product(cam.vec_right, cam.vec_forward);
	cam.dir.x = (2.0 * (x + 0.5) / (double)WIN_WIDTH - 1)
		* tan(o_cam->fov / 2 * PI / 180.0)
		* ((double)((double)WIN_WIDTH / (double)WIN_HEIGHT));
	cam.dir.y = (1.0 - 2.0 * (y + 0.5) / (double)WIN_HEIGHT)
		* tan(o_cam->fov / 2 * PI / 180.0);
	cam.dir.z = FOCAL_DIST;
	cam.dir = cam_to_world(&cam, cam.dir);
	ray.dir = normalize(cam.dir);
	return (ray);
}
