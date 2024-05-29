/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:16:24 by eturiot           #+#    #+#             */
/*   Updated: 2023/09/21 11:41:31 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_H
# define GNL_H

# include "libft.h"

/* ************************************************************************** */
/*                                   Macros                                   */
/* ************************************************************************** */

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1

# endif

/* ************************************************************************** */
/*                                 Functions                                  */
/* ************************************************************************** */

char	*ft_strjoin_gnl(char **save, char *s2);
char	*purge_gnl(char *s1, char *s2, char **save);
char	*save_and_return(ssize_t tag, char **save);

ssize_t	find_nl(char *str, char ref);
ssize_t	read_check_error(int fd, char *buffer, char **save);

#endif
