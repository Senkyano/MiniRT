/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extractor.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 16:11:37 by eturiot           #+#    #+#             */
/*   Updated: 2024/05/29 16:11:40 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

bool extractor(t_element *scene, const int fd)
{
	bool	is_extracted;
	char	*tmp;
	(void)scene;

	is_extracted = false;
	tmp = get_next_line(fd);
	while (tmp && !errno)
	{
		ft_printf("ok -> %s", tmp);
		free(tmp);
		tmp = get_next_line(fd);
	}
	return (is_extracted);
}
