/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:05:40 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/10 14:03:50 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>
# include <string.h>
# include "lib_utils.h"
# include "get_next_line.h"
# include "plan_axe.h"
# include "color.h"

# define PI 3.14159265358979323846
# define SPHERE 1
# define CYLINDER 2
# define PLANE 3
# define CAM 4
# define LIGHT 5
# define AMBIANT 6

typedef struct s_objs
{
	char			type;
	t_coord			coord;
	t_coord			vecteur;
	double			diameter;
	double			height;
	t_rgb			color;
	struct s_objs	*next;
}	t_objs;

typedef struct s_cam
{
	t_coord		coord;
	t_coord		vecteur;
	char		fov;
	bool		init;
}	t_cam;

typedef struct s_light
{
	t_coord		coord;
	t_rgb		color;
	float		ratio;
	bool		init;
}	t_light;

typedef struct s_scene
{
	t_cam		camera;
	bool		cam_on;
	t_light		light;
	bool		light_on;
	t_light		ambiant;
	bool		ambiant_on;
	t_objs		*objs;
	char		obj_can[6];
	void		*(*f[3])(t_objs*, char**);
}	t_scene;

//		Init
t_objs	*init_obj(char **arg, t_scene *scene);
void	l_add_obj(t_objs **l_objs, t_objs *obj);

bool	extrac_file(char *argv, t_scene *scene);

void	init_scene(t_scene *scene);
void	*init_cylinder(t_objs *objs, char **arg);
void	*init_plan(t_objs *objs, char **arg);
void	*init_sphere(t_objs *objs, char **arg);
bool	init_cam(t_scene scene, char **arg);
bool	init_light(t_scene scene, char **arg);
bool	init_coord(t_coord *coord, char **arg);
bool	init_color(t_rgb *color, char **arg);

#endif
