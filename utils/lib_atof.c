/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_atof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:17:23 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/30 18:32:04 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

double	lib_atof(char *nbr)
{
	double	ent;
	double	vir;
	int		len;

	ent = lib_atoi(nbr);
	while (*nbr && *nbr != '.')
		nbr++;
	if (*nbr == '.')
		nbr++;
	len = ft_strlen(nbr);
	vir = lib_atoi(nbr);
	while (len-- && vir >= 1)
		vir /= 10;
	if (ent < 0)
		return (ent - vir);
	return (ent + vir);
}
