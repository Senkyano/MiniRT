/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:05:40 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/31 15:18:25 by rihoy            ###   ########.fr       */
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
// made includes
# include "lib_utils.h"
# include "get_next_line.h"
# include "plan_axe.h"
# include "vecteur.h"
# include "color.h"

# define PI 3.14159265358979323846
# define SPHERE 1
# define CYLINDER 2
# define PLANE 3

typedef struct s_objs
{
	char			type;
	t_coord			coord;
	t_vecteur		orient;
	double			diameter;
	double			height;
	t_rgb			color;
	struct s_objs	*next;
}	t_objs;

typedef struct s_cam
{
	t_coord		coord;
	t_vecteur	orient;
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
	t_light		light;
	t_light		ambiant;
	t_objs		*objs;
	char		obj_can[6];
	void		*(*f[3])(t_objs*, char**);
}	t_scene;

//		Init
void	init_scene(t_scene *scene);
// void	*init_cylinder(t_objs *objs, char **arg);
// void	*init_plane(t_objs *objs, char **arg);
// void	*init_sphere(t_objs *objs, char **arg);
// t_coord	init_coord(char **arg);

#endif
