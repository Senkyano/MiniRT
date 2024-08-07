/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_information.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/15 15:46:15 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/07 15:32:14 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minirt.h"

// void	display_sphere(t_objs *objs);
// void	display_cylinder(t_objs *objs);
// void	display_plane(t_objs *objs);
// void	display_cam(t_objs *objs);
// void	display_light(t_objs *objs);
// void	display_ambiant(t_objs *objs);

// void	display_infobj(t_objs *objs)
// {
// 	t_objs	*tmp;
// 	int		i;

// 	tmp = objs;
// 	i = 0;
// 	while (tmp)
// 	{
// 		i++;
// 		if (tmp->type == SPHERE)
// 			display_sphere(tmp);
// 		else if (tmp->type == CYLINDER)
// 			display_cylinder(tmp);
// 		else if (tmp->type == PLANE)
// 			display_plane(tmp);
// 		else if (tmp->type == CAM)
// 			display_cam(tmp);
// 		else if (tmp->type == LIGHT)
// 			display_light(tmp);
// 		else if (tmp->type == AMBIANT)
// 			display_ambiant(tmp);
// 		tmp = tmp->next;
// 	}
// }

// void	display_cam(t_objs *objs)
// {
// 	printf("===========\n");
// 	printf("Camera\n");
// 	printf("Coord: %f %f %f\n", objs->origin.x, objs->origin.y, 
// objs->origin.z);
// 	printf("Vecteur: %f %f %f\n", objs->vecteur.x, objs->vecteur.y, 
// objs->vecteur.z);
// 	printf("Fov: %d\n", objs->fov);
// 	printf("===========\n\n");
// }

// void	display_light(t_objs *objs)
// {
// 	printf("===========\n");
// 	printf("Light\n");
// 	printf("Coord: %f %f %f\n", objs->origin.x, objs->origin.y, objs->origin.z);
// 	printf("Ratio: %f\n", objs->ratio);
// 	printf("Color: %d %d %d\n", objs->color.r, objs->color.g, objs->color.b);
// 	printf("===========\n\n");
// }

// void	display_ambiant(t_objs *objs)
// {
// 	printf("===========\n");
// 	printf("Ambiant\n");
// 	printf("Ratio: %f\n", objs->ratio);
// 	printf("Color: %d %d %d\n", objs->color.r, objs->color.g, objs->color.b);
// 	printf("===========\n\n");
// }

// void	display_sphere(t_objs *objs)
// {
// 	printf("===========\n");
// 	printf("Sphere\n");
// 	printf("Coord: %f %f %f\n", objs->origin.x, objs->origin.y, objs->origin.z);
// 	printf("radius: %f\n", objs->radius);
// 	printf("Color: %d %d %d\n", objs->color.r, objs->color.g, objs->color.b);
// 	printf("===========\n\n");
// }

// void	display_cylinder(t_objs *objs)
// {
// 	printf("===========\n");
// 	printf("Cylinder\n");
// 	printf("Coord: %f %f %f\n", objs->origin.x, objs->origin.y, objs->origin.z);
// 	printf("radius: %f\n", objs->radius);
// 	printf("Height: %f\n", objs->height);
// 	printf("Color: %d %d %d\n", objs->color.r, objs->color.g, objs->color.b);
// 	printf("===========\n\n");
// }

// void	display_plane(t_objs *objs)
// {
// 	printf("===========\n");
// 	printf("Plane\n");
// 	printf("Coord: %f %f %f\n", objs->origin.x, objs->origin.y, objs->origin.z);
// 	printf("Vecteur: %f %f %f\n", objs->vecteur.x, objs->vecteur.y, 
// objs->vecteur.z);
// 	printf("Color: %d %d %d\n", objs->color.r, objs->color.g, objs->color.b);
// 	printf("===========\n\n");
// }
