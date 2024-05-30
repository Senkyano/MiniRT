/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vecteur.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 12:47:01 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/30 14:39:59 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef VECTEUR_H
# define VECTEUR_H

# define MIN_VECTOR -1.0
# define MAX_VECTOR 1.0

typedef struct s_vecteur
{
	double	x;
	double	y;
	double	z;
}	t_vecteur;

#endif
