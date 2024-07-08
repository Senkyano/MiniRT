/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minirt.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/20 17:05:40 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/08 12:02:48 by rihoy            ###   ########.fr       */
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
# include "lib_math.h"
# include "get_next_line.h"
# include "color.h"
// # include ""
# include <X11/X.h>
# include <X11/keysym.h>
# include "mlx.h"
# include "mlx_int.h"

# define PI 3.14159265358979323846
# define SPHERE 's'
# define CYLINDER 'c'
# define PLANE 'p'
# define CAM 'C'
# define LIGHT 'L'
# define AMBIANT 'A'

typedef struct s_objs
{
	char			type;
	t_coord			origin;
	t_coord			vecteur;
	double			diameter;
	double			height;
	int				fov;
	double			win_width;
	double			win_height;
	t_rgb			color;
	float			ratio;
	struct s_objs	*next;
	struct s_objs	*prev;
}	t_objs;

typedef struct s_scene	t_scene;

typedef struct s_scene
{
	t_objs		*camera;
	bool		cam_on;
	t_objs		*light;
	bool		light_on;
	t_objs		*ambiant;
	bool		ambiant_on;
	t_objs		*objs;
	int			obj_can[6];
	void		*(*f[6])(t_objs*, char**, t_scene*);
}	t_scene;

typedef struct s_window
{
	void	*mlx;
	void	*win;
	int		img_width;
	int		img_height;
	t_scene	scene;
}	t_window;

// color

bool	extractfile(t_scene *scene, char *file);
//		Init
t_objs	*init_obj(t_scene *scene, char **split);
void	add_l_objs(t_objs **lst, t_objs *obj);
void	clear_objs(t_objs **lst);
void	org_lst(t_scene *scene);
// void	l_add_obj(t_objs **l_objs, t_objs *obj);

int		clear_minirt(t_window *window);
void	clear_scene(t_scene *scene);

int	handle_key(int keycode, t_window *window);

void	camRay(t_window *window);

// bool	extrac_file(char *argv, t_scene *scene);
void	*init_ambiant(t_objs *obj, char **split, t_scene *scene);
void	*init_cylinder(t_objs *obj, char **split, t_scene *scene);
void	*init_plane(t_objs *obj, char **split, t_scene *scene);
void	*init_sphere(t_objs *obj, char **split, t_scene *scene);
void	*init_cam(t_objs *obj, char **split, t_scene *scene);
void	*init_light(t_objs *obj, char **split, t_scene *scene);

//diaplay
void	display_infobj(t_objs *objs);

#endif
