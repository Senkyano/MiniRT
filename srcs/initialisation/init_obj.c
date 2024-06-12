/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 16:58:45 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/12 17:21:35 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objs	*init_obj(t_scene *scene, char **split)
{
	t_objs	*obj;
	int		i;

	obj = malloc(sizeof(t_objs));
	if (!obj)
		return (NULL);
	i = -1;
	while (++i < 6)
	{
		if (scene->obj_can[i] == split[0][0])
		{
			if (!scene->f[i](obj, split))
				return (free(obj), NULL);
			break ;
		}
	}
	if (i == 6)
	{
		free(obj);
		return (NULL);
	}
	return (obj);
}

void	add_l_objs(t_objs **lst, t_objs *obj)
{
	t_objs	*tmp;

	if (!*lst)
	{
		*lst = obj;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = obj;
}
