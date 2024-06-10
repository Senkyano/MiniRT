/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   miniRT.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:34:07 by eturiot           #+#    #+#             */
/*   Updated: 2024/05/31 15:41:54 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINIRT_H
# define MINIRT_H

# include <unistd.h>

# include "libft.h"
# include "mlx.h"

# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>
# include <X11/keysym.h>
# include <X11/X.h>

# include "element.h"
# include "error.h"

/* ************************************************************************** */
/*                                   Macros                                   */
/* ************************************************************************** */

/* ************************************************************************** */
/*                                 Structures                                 */
/* ************************************************************************** */

typedef	struct s_image
{
	void		*mlx_ptr;
	void		*win;
	t_element	scene;
}	t_image;

/* ************************************************************************** */
/*                                 Functions                                  */
/* ************************************************************************** */

int		open_str(char *file);

bool	extractor(t_element *scene, const int fd);
bool	parsing(t_element *scene, const int fd);

#endif
