/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd_lines.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 14:50:35 by rihoy             #+#    #+#             */
/*   Updated: 2024/08/07 16:14:05 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "lib_utils.h"

t_file	*new_line(char *line)
{
	t_file	*new;

	new = malloc(sizeof(t_file));
	if (!new)
		return (NULL);
	new->line = line;
	new->next = NULL;
	new->prev = NULL;
	return (new);
}

void	add_line(t_file **lst, t_file *new)
{
	t_file	*tmp;

	if (!*lst)
	{
		*lst = new;
		return ;
	}
	tmp = *lst;
	while (tmp->next)
		tmp = tmp->next;
	new->prev = tmp;
	tmp->next = new;
}

void	clear_fd(t_file *lst)
{
	t_file	*tmp;

	while (lst)
	{
		tmp = lst;
		lst = lst->next;
		free(tmp->line);
		free(tmp);
	}
}
