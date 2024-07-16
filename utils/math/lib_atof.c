/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_atof.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 18:17:23 by rihoy             #+#    #+#             */
/*   Updated: 2024/07/16 22:42:11 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include <stdio.h>

double	lib_atof(char *nbr)
{
	double	ent;
	double	neg;
	double	vir;
	int		len;
	int		i;

	i = 0;
	neg = 1;
	if (nbr[i] == '-')
	{
		neg = -1;
		i++;
	}
	ent = lib_atoi(nbr + i);
	while (nbr[i] && nbr[i] != '.')
		i++;
	if (nbr[i] == '.')
		i++;
	len = str_len(nbr + i);
	vir = lib_atoi(nbr + i);
	while (len-- && vir >= 1)
		vir /= 10;
	if (ent < 0)
		return ((ent - vir) * neg);
	return ((ent + vir) * neg);
}
