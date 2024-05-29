/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 16:44:11 by eturiot           #+#    #+#             */
/*   Updated: 2023/09/21 10:15:27 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include  "printf.h"

void	flags_managers(va_list args, const char flag, int *res, int fd)
{
	if (flag == 'c')
		print_char(va_arg(args, int), res, fd);
	if (flag == 's')
		print_str(va_arg(args, char *), res, fd);
	if (flag == 'p')
		print_ptr(va_arg(args, void *), res, fd);
	if (flag == 'd' || flag == 'i')
		print_nbr(va_arg(args, int), res, fd);
	if (flag == 'u')
		print_unbr(va_arg(args, unsigned int), res, fd);
	if (flag == 'x' || flag == 'X')
		print_hexa(va_arg(args, unsigned int), flag, res, fd);
	if (flag == '%')
		print_char('%', res, fd);
}

int	ft_printf(const char *str, ...)
{
	int		fd;
	int		i;
	int		res;
	va_list	args;

	fd = 1;
	i = 0;
	res = 0;
	va_start(args, str);
	while (str[i] && res >= 0)
	{
		if (str[i] == '%')
		{
			flags_managers(args, str[i + 1], &res, fd);
			i++;
		}
		else
			print_char(str[i], &res, fd);
		i++;
	}
	va_end(args);
	return (res);
}

int	ft_printf_fd(int fd, const char *str, ...)
{
	int		i;
	int		res;
	va_list	args;

	if (fd >= 0)
	{
		i = 0;
		res = 0;
		va_start(args, str);
		while (str[i] && res >= 0)
		{
			if (str[i] == '%')
			{
				flags_managers(args, str[i + 1], &res, fd);
				i++;
			}
			else
				print_char(str[i], &res, fd);
			i++;
		}
		va_end(args);
	}
	else
		res = -1;
	return (res);
}
