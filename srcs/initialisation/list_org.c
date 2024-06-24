/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_org.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/24 10:20:19 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/24 11:28:32 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

t_objs	*supp_btw(t_objs *obj_prec, t_objs *obj, t_objs *obj_next);

void	org_lst(t_scene *scene)
{
	t_objs	*tmp;

	tmp = scene->objs;
	while (tmp)
	{
		if (tmp->type == CAM)
		{
			scene->camera = tmp;
			// tmp = supp_btw(tmp->prev, tmp, tmp->next);
		}
		else if (tmp->type == LIGHT)
		{
			scene->light = tmp;
			// tmp = supp_btw(tmp->prev, tmp, tmp->next);
		}
		else if (tmp->type == AMBIANT)
		{
			scene->ambiant = tmp;
			// tmp = supp_btw(tmp->prev, tmp, tmp->next);
		}
		tmp = tmp->next;
	}
}
