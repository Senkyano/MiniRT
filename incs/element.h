/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:53:54 by eturiot           #+#    #+#             */
/*   Updated: 2024/06/10 16:40:32 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H
 
# include "rgb.h" 
# include "vector.h"

/* ************************************************************************** */
/*                                   Macros                                   */
/* ************************************************************************** */

# define AMBIENT	'A'
# define CAMERA		'C'
# define LIGHT		'L'
# define CYLINDER	'c'
# define SPHERE		's'
# define PLANE		'p'

# define FOV_MIN		0
# define FOV_MAX		180
# define LIGHT_MIN		0.0
# define LIGHT_MAX		1.0

# define X	0
# define Y	1
# define Z	2

/* ************************************************************************** */
/*                                 Structures                                 */
/* ************************************************************************** */

typedef	struct s_ambient
{
	bool	is_set;
	float	ratio;
	t_rgb	color;
}	t_ambient;

typedef	struct s_camera
{
	bool		is_set;
	float		coordinate[3];
	t_vector	norm;
	int			fov;
}	t_camera;

typedef struct s_light
{
	bool	is_set;
	float	coordinate[3];
	float	brightness;
	t_rgb	color;
}	t_light;

typedef	struct s_object
{
	char			identifier;
	float			coordinate[3];
	t_vector		norm;
	float			diameter;
	float			height;
	t_rgb			color;
	struct s_object	*next;
}	t_object;

typedef struct s_element
{
	t_ambient		ambient;
	t_camera		camera;
	t_light			light;		
	t_object		*obj;
}	t_element;

/* ************************************************************************** */
/*                                 Functions                                  */
/* ************************************************************************** */

bool	setup_ambiant(t_ambient *ambient, char *str);
bool	setup_camera(t_camera *ambient, char *str);
bool	setup_light(t_light *ambient, char *str);
bool	setup_object(t_object *obj, char *str);

#endif
