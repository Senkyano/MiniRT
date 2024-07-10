/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nearest.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 12:42:15 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/10 13:20:10 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	len_lst(t_objs *objs);

void	org_nearest(t_scene *scene)
{
	t_objs	*tmp;
	t_objs	*nearest;
	int		i;

	(void)nearest;
	(void)tmp;
	i = len_lst(scene->objs);
	printf("i = %d\n", i);
}

int	len_lst(t_objs *objs)
{
	int		i;
	t_objs	*tmp;

	i = 0;
	tmp = objs;
	while (tmp)
	{
		i++;
		tmp = tmp->next;
	}
	return (i);
}
