/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:40:29 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/30 18:44:29 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

//on m'envoie un tableau de char **arg de la forme [type, coord, vecteur, RGB]

t_objs	*init_obj(char **arg)
{
	t_objs	*obj;
	char	type[3];
	int		i;
	void	*(*f[3])(t_objs*, char**);

	i = -1;
	type[0] = 's';
	type[1] = 'c';
	type[2] = 'p';
	(f[0]) = &init_sphere;
	(f[1]) = &init_cylinder;
	(f[2]) = &init_plane;
	obj = malloc(sizeof(t_objs));
	if (!obj)
		return (NULL);
	while (type[++i] && i < 3)
	{
		if (type[i] == arg[0][0])
		{
			if (f[i](obj, arg) == NULL)
					return (free(obj), NULL);
			break ;
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
