/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:11:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/11 14:42:46 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

bool	check_launch(int argc, char *arg);

int	main(int argc, char **argv)
{
	t_scene	scene;

	(void)scene;
	if (!check_launch(argc, argv[1]))
		return (1);
	printf(GR"Good\n"RST);
	if (!extractfile(&scene, argv[1]))
		return (1);
	return (0);
}

void	init_scene(t_scene *scene)
{
	lib_memset(scene, 0, sizeof(t_scene));
	scene->objs = NULL;
	scene->obj_can[0] = SPHERE;
	scene->obj_can[1] = CYLINDER;
	scene->obj_can[2] = PLANE;
	scene->obj_can[3] = CAM;
	scene->obj_can[4] = LIGHT;
	scene->obj_can[5] = AMBIANT;
	// scene->f[0] = &init_sphere;
	// scene->f[1] = &init_cylinder;
	// scene->f[2] = &init_plane;
	// scene->f[3] = &init_cam;
	// scene->f[4] = &init_light;
	// scene->f[5] = &init_ambiant;
}

bool	check_launch(int argc, char *arg)
{
	if (argc != 2)
	{
		printf_error(RED"Error\nWrong number of arguments\n"RST);
		return (false);
	}
	if (!last_cmp(arg ,".rt"))
	{
		printf_error(RED"Error\nWrong file extension\n"RST);
		return (false);
	}
	return (true);
}
