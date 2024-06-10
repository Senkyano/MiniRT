/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/31 15:28:32 by eturiot           #+#    #+#             */
/*   Updated: 2024/06/10 16:51:33 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

/* static bool	whitespace_line(char *str) */
/* { */
/* 	bool	is_valid; */
/* 	size_t	i; */

/* 	is_valid = true; */
/* 	i = 0; */
/* 	while (str[i] && !is_valid) */
/* 	{ */
/* 		if (str[i] != SPACE && str[i] != TAB && str[i] != NEWLINE) */
/* 			is_valid = false; */
/* 		++i; */
/* 	} */
/* 	return (is_valid); */
/* } */

static char	identified_object(char *str)
{
	char	id;
	size_t	i;

	i = 0;
	while (str[i] && (str[i] == SPACE || str[i] == TAB))
		++i;
	if (str[i] == 'A')
		id = AMBIENT;
	else if (str[i] == 'C')
		id = CAMERA;
	else if (str[i] == 'L')
		id = LIGHT;
	else if (str[i] == 's' && str[++i] == 'p')
		id = SPHERE;
	else if (str[i] == 'p' && str[++i] == 'l')
		id = PLANE;
	else if (str[i] == 'c' && str[++i] == 'y')
		id = CYLINDER;
	if (str[i] == NEWLINE)
		id = NEWLINE;
	else if (!str[i + 1] && str[i + 1] != SPACE && str[i + 1] != TAB)
		id = '\0';
	return (id);
}

static bool	init_element(t_element *scene, char *str)
{
	bool	is_valid;
	char	id;

	is_valid = false;
	id = identified_object(str);
	if (id == AMBIENT)
		is_valid = setup_ambient(&(scene->ambient), str);
	else if (id == CAMERA)
		is_valid = setup_camera(&(scene->camera), str);
	else if (id == LIGHT)
		is_valid = setup_light(&(scene->light), str);
	else if (id == SPHERE || id == PLANE || id == CYLINDER)
		is_valid = setup_object(scene, id);
	else if (id != NEWLINE)
		ft_printf_fd(2, "ERROR\n%s\n", EID);
	return (is_valid);
}

bool parsing(t_element *scene, const int fd)
{
	bool	is_fully_extracted;
	char	*next_line;

	scene->ambient.is_set = false;
	scene->camera.is_set = false;
	scene->light.is_set = false;
	is_fully_extracted = false;
	next_line = get_next_line(fd);
	while (next_line && !is_fully_extracted && !errno)
	{
		ft_printf("%s", next_line);
		init_element(scene, next_line);
		free(next_line);
		next_line = get_next_line(fd);
	}
	close (fd);
	return (is_fully_extracted);
}
