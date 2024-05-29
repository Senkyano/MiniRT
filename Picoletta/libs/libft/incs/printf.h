/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/09/21 10:10:16 by eturiot           #+#    #+#             */
/*   Updated: 2023/09/21 11:41:41 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_H
# define PRINTF_H

# include "libft.h"

# include <stdarg.h>

/* ************************************************************************** */
/*                                   Macros                                   */
/* ************************************************************************** */

# define HEXA_LO "0123456789abcdef"
# define HEXA_UP "0123456789ABCDEF"

# ifdef __APPLE__
#  define NULL_OS "0x0"
# else
#  define NULL_OS "(nil)"
# endif

/* ************************************************************************** */
/*                                 Functions                                  */
/* ************************************************************************** */

void	flags_managers(va_list args, const char flag, int *res, int fd);
void	hexa_converter(unsigned long n, char *base_to, int *res, int fd);
void	print_char(int c, int *res, int fd);
void	print_hexa(unsigned long n, char flag, int *res, int fd);
void	print_nbr(long n, int *res, int fd);
void	print_percent(int *res, int fd);
void	print_ptr(void *ptr, int *res, int fd);
void	print_str(char *str, int *res, int fd);
void	print_unbr(unsigned long n, int *res, int fd);

#endif
