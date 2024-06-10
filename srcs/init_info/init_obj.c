/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:40:29 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/10 14:16:33 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//on m'envoie un tableau de char **arg de la forme [type, coord, vecteur, RGB]

t_objs	*init_obj(char **arg, t_scene *scene)
{
	t_objs	*obj;
	int		i;

	i = -1;
	obj = malloc(sizeof(t_objs));
	if (!obj)
		return (NULL);
	while (scene->obj_can[++i + 3] && i < 3)
	{
		if (scene->obj_can[i + 3] == arg[0][0])
		{
			if (scene->f[i](obj, arg) == NULL)
				return (free(obj), NULL);
			break ;
		}
		else if (i == 2 && scene->obj_can[i + 3] != arg[0][0])
		{
			free(obj);
			return (print_error(RED"Error : \nInvalid object type\n"RST), NULL);
		}
	}
	return (obj);
}

void	l_add_obj(t_objs **l_objs, t_objs *obj)
{
	t_objs	*tmp;

	if (!*l_objs)
	{
		*l_objs = obj;
		return ;
	}
	tmp = *l_objs;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = obj;
}
