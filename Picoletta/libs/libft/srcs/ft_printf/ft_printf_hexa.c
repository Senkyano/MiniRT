/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/17 17:02:12 by eturiot           #+#    #+#             */
/*   Updated: 2023/09/21 10:15:38 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "printf.h"

void	hexa_converter(unsigned long n, char *base_to, int *res, int fd)
{
	if (n > 15)
		hexa_converter(n / 16, base_to, res, fd);
	print_char(base_to[n % 16], res, fd);
}

void	print_hexa(unsigned long n, char flag, int *res, int fd)
{
	if (flag == 'x')
		hexa_converter(n, HEXA_LO, res, fd);
	else
		hexa_converter(n, HEXA_UP, res, fd);
}

void	print_ptr(void *ptr, int *res, int fd)
{
	unsigned long	adress;

	adress = (unsigned long)ptr;
	if (!ptr)
		print_str(NULL_OS, res, fd);
	else
	{
		print_str("0x", res, fd);
		hexa_converter(adress, HEXA_LO, res, fd);
	}
}
