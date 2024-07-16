/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:11:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/16 17:45:07 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	init_scene(t_scene *scene);
bool	check_launch(int argc, char *arg);
void	creat_window(t_window *window);

int	main(int argc, char **argv)
{
	t_window	window;

	if (!check_launch(argc, argv[1]))
		return (1);
	window.mlx = NULL;
	window.win = NULL;
	init_scene(&window.scene);
	if (!extractfile(&window.scene, argv[1]))
		return (1);
	window.img_width = WIN_WIDTH;
	window.img_height = WIN_HEIGHT;
	org_lst(&window.scene);
	display_infobj(window.scene.objs);
	printf(YL"RayTracing Calculation ...\n"RST);
	creat_window(&window);
	printf(PUR"Clearing memory...\n"RST);
	clear_scene(&window.scene);
	return (0);
}

void	creat_window(t_window *window)
{
	window->mlx = mlx_init();
	if (window->mlx == NULL)
	{
		printf_error(RED"Error\nmlx_init failed\n"RST);
		clear_minirt(window);
		exit(1);
	}
	window->win = mlx_new_window(window->mlx, window->img_width, \
	window->img_height, "miniRT");
	if (window->win == NULL)
	{
		printf_error(RED"Error\nmlx_new_window failed\n"RST);
		clear_minirt(window);
	}
	mlx_hook(window->win, DestroyNotify, StructureNotifyMask, clear_minirt, \
	window);
	mlx_hook(window->win, KeyRelease, KeyReleaseMask, handle_key, window);
	cam_ray(window);
	mlx_loop(window->mlx);
}

void	clear_scene(t_scene *scene)
{
	free(scene->camera);
	free(scene->light);
	free(scene->ambiant);
	clear_objs(&scene->objs);
}

void	init_scene(t_scene *scene)
{
	lib_memset(scene, 0, sizeof(t_scene));
	scene->objs = NULL;
	scene->camera = NULL;
	scene->light = NULL;
	scene->ambiant = NULL;
	scene->obj_can[0] = SPHERE;
	scene->obj_can[1] = CYLINDER;
	scene->obj_can[2] = PLANE;
	scene->obj_can[3] = CAM;
	scene->obj_can[4] = LIGHT;
	scene->obj_can[5] = AMBIANT;
	scene->f[0] = &init_sphere;
	scene->f[1] = &init_cylinder;
	scene->f[2] = &init_plane;
	scene->f[3] = &init_cam;
	scene->f[4] = &init_light;
	scene->f[5] = &init_ambiant;
}

bool	check_launch(int argc, char *arg)
{
	if (argc != 2)
	{
		printf_error(RED"Error\nWrong number of arguments\n"RST);
		return (false);
	}
	if (!last_cmp(arg, ".rt"))
	{
		printf_error(RED"Error\nWrong file extension\n"RST);
		return (false);
	}
	return (true);
}
