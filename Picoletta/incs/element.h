/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:53:54 by eturiot           #+#    #+#             */
/*   Updated: 2024/05/29 13:53:58 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ELEMENT_H
# define ELEMENT_H
 
# include "rgb.h" 
# include "vector.h"

/* ************************************************************************** */
/*                                   Macros                                   */
/* ************************************************************************** */

# define FOV_MIN		0
# define FOV_MAX		180
# define LIGHT_MIN		0.0
# define LIGHT_MAX		1.0

/* ************************************************************************** */
/*                                 Structures                                 */
/* ************************************************************************** */

typedef	struct s_ambient
{
	float	ratio;
	t_rgb	color;
}	t_ambient;

typedef	struct s_camera
{
	float		coordinate[3];
	t_vector	norm;
	int			fov;
}	t_camera;

typedef struct s_light
{
	float	coordinate[3];
	float	brightness;
	float	rgb[3];
}	t_light;


typedef struct s_sphere
{
	float	coordinate[3];
	float	diameter;
	t_rgb	color;
}	t_sphere;

typedef struct s_plane
{
	float		coordinate[3];
	t_vector	norm;
	t_rgb		color;
}	t_plane;

typedef struct s_cylinder
{
	float		coordinate[3];
	t_vector	norm;
	float		diameter;
	float		height;
	t_rgb		color;
}	t_cylinder;

/* typedef	struct s_obj
{
	float	coordinate[3];
	t_vector	norm;
	float	diameter;
	float	height;
	t_rgb	color;
}	t_obj; */


typedef struct s_element
{
	t_ambient		ambient;
	t_camera		camera;
	t_light			light;		
	t_sphere		sphere;
	t_plane			plane;
	t_cylinder		cylinder;
	//t_obj;

}	t_element;

/* ************************************************************************** */
/*                                 Functions                                  */
/* ************************************************************************** */

#endif