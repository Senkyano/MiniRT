/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cam.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:10:12 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/04 13:48:01 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

// // si on as rien on met la couleur en noir
// typedef struct {
//     double x, y, z;
// } vec3;

// typedef vec3 point3;
// typedef vec3 color;

// typedef struct {
//     point3 origin;
//     vec3 direction;
// } ray;

// vec3 vec3_add(vec3 a, vec3 b) {
//     return (vec3){a.x + b.x, a.y + b.y, a.z + b.z};
// }

// vec3 vec3_sub(vec3 a, vec3 b) {
//     return (vec3){a.x - b.x, a.y - b.y, a.z - b.z};
// }

// vec3 vec3_div_scalar(vec3 v, double s) {
//     return (vec3){v.x / s, v.y / s, v.z / s};
// }

// vec3 vec3_mul_scalar(vec3 v, double s) {
//     return (vec3){v.x * s, v.y * s, v.z * s};
// }

// // color ray_color(ray r) {
// //     // Placeholder for ray_color function. Implement based on your scene.
// //     return (color){0.5, 0.7, 1.0}; // Returns a sky blue color
// // }

// void write_color(FILE* out, color pixel_color) {
//     fprintf(out, "%d %d %d\n", (int)(255.999 * pixel_color.x), (int)(255.999 * pixel_color.y), (int)(255.999 * pixel_color.z));
// }

void	camRay(t_window *window)
{

	// double aspect_ratio = 16.0 / 9.0;
    // int image_width = 400;
    // int image_height = (int)(image_width / aspect_ratio);
    // image_height = (image_height < 1) ? 1 : image_height;

    // double focal_length = 1.0;
    // double viewport_height = 2.0;
    // double viewport_width = viewport_height * ((double)image_width / image_height);
    // point3 camera_center = {0, 0, 0};

    // vec3 viewport_u = {viewport_width, 0, 0};
    // vec3 viewport_v = {0, -viewport_height, 0};
    // vec3 pixel_delta_u = vec3_div_scalar(viewport_u, image_width);
    // vec3 pixel_delta_v = vec3_div_scalar(viewport_v, image_height);

    // vec3 viewport_upper_left = vec3_sub(vec3_sub(vec3_sub(camera_center, (vec3){0, 0, focal_length}), vec3_div_scalar(viewport_u, 2)), vec3_div_scalar(viewport_v, 2));
    // vec3 pixel00_loc = vec3_add(viewport_upper_left, vec3_mul_scalar(vec3_add(pixel_delta_u, pixel_delta_v), 0.5));

    // for (int j = 0; j < image_height; j++) {
    //     // fprintf(stderr, "\rScanlines remaining: %d ", image_height - j);
    //     for (int i = 0; i < image_width; i++) {
    //         // vec3 pixel_center = vec3_add(vec3_add(pixel00_loc, vec3_mul_scalar(pixel_delta_u, i)), vec3_mul_scalar(pixel_delta_v, j));
    //         // vec3 ray_direction = vec3_sub(pixel_center, camera_center);
    //         // ray r = {camera_center, ray_direction};

    //         // color pixel_color = ray_color(r);
	// 		int pixel_color = color_pix(50, 70, 100);
    //         // write_color(stdout, pixel_color);
    //     }
    // }

    // fprintf(stderr, "\rDone.                 \n");
	//render

	t_objs	*cam;

	cam = window->scene.camera;
	cam->win_height = 2;
	cam->win_width = 2 * ((double)window->img_width / window->img_height);
	
	// t_coord	viewport_u = {cam->win_width, 0, 0};
	// t_coord	viewport_v = {0, -cam->win_height, 0};

	// t_coord pixel_delta_u = {cam->win_width / window->img_width, 0, 0};
	// t_coord pixel_delta_v = {0, -cam->win_height / window->img_height, 0};
	int	i = 0;
	int	j = 0;
	t_rgb	color;
	printf("window->img_width = %d, window->img_height = %d\n", window->img_width, window->img_height);
	lib_memset(&color, 0, sizeof(t_rgb));
	while (j < window->img_height)
	{
		i = 0;
		while (i < window->img_width)
		{
			double r = (double)i / (window->img_width - 1);
			double g = (double)j / (window->img_height - 1);
			double b = 0.5;

			// printf("r = %f, g = %f, b = %f\n", r, g, b);
			color.r = (int)(255.999 * r);
			color.g = (int)(255.999 * g);
			color.b = (int)(255.999 * b);
			
			int	color_pixel = color_pix(color.r, color.g, color.b);
			mlx_pixel_put(window->mlx, window->win, i, j, color_pixel);
			i++;
		}
		j++;
	}
}
