/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_org.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:20:19 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/25 11:33:16 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

void	extract_obj(t_objs *prev, t_objs **tmp, t_objs *next, t_scene *scene);

void	org_lst(t_scene *scene)
{
	t_objs	*tmp;

	tmp = scene->objs;
	while (tmp)
	{
		if (tmp->type == CAM)
		{
			scene->camera = tmp;
			extract_obj(tmp->prev, &tmp, tmp->next, scene);
		}
		else if (tmp->type == LIGHT)
		{
			scene->light = tmp;
			extract_obj(tmp->prev, &tmp, tmp->next, scene);
		}
		else if (tmp->type == AMBIANT)
		{
			scene->ambiant = tmp;
			extract_obj(tmp->prev, &tmp, tmp->next, scene);
		}
		else
			tmp = tmp->next;
	}
}

void	extract_obj(t_objs *prev, t_objs **tmp, t_objs *next, t_scene *scene)
{
	(*tmp)->prev = NULL;
	(*tmp)->next = NULL;
	if (!prev)
	{
		scene->objs = next;
		(*tmp) = next;
	}
	else
	{
		prev->next = next;
		(*tmp) = next;
	}
	if (next)
		next->prev = prev;
}
