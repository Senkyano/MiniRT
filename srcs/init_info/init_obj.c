/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_obj.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 15:40:29 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/30 16:10:15 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

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
