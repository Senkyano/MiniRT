/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/13 09:46:34 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/11 16:20:56 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <bsd/string.h>
# include <stdlib.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 50
# endif

typedef struct s_stock
{
	char	*rest;
	char	*curr;
	char	*line;
}	t_stock;

typedef struct s_file
{
	char	*line;
	struct	s_file	*next;
}	t_file;

char	*get_next_line(int fd);
void	clear_fd(t_file *lst);
void	add_line(t_file **lst, t_file *new);
t_file	*new_line(char *line);

#endif