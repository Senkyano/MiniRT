/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/19 12:44:33 by eturiot           #+#    #+#             */
/*   Updated: 2023/11/21 22:30:03 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "printf.h"

void	print_char(int c, int *res, int fd)
{
	if (write(fd, &c, 1))
		(*res)++;
	else
		(*res) = -1;
}

void	print_str(char *str, int *res, int fd)
{
	size_t	length;

	if (!str)
	{
		if (write(fd, "(null)", 6))
			(*res) += 6;
		else
			(*res) = -1;
	}
	else if (str[0])
	{
		length = ft_strlen(str);
		if (write(fd, str, length))
			(*res) += length;
		else
			(*res) = -1;
	}
}

void	print_nbr(long n, int *res, int fd)
{
	if (n < 0 && (*res) >= 0)
	{
		n *= -1;
		print_char('-', res, fd);
	}
	if (n > 9 && (*res) >= 0)
		print_nbr(n / 10, res, fd);
	if ((*res) >= 0)
		print_char(n % 10 + '0', res, fd);
}

void	print_unbr(unsigned long n, int *res, int fd)
{
	if (n > 9 && (*res) >= 0)
		print_unbr(n / 10, res, fd);
	if ((*res) >= 0)
		print_char(n % 10 + '0', res, fd);
}
