/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <eturiot@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/19 17:42:24 by eturiot           #+#    #+#             */
/*   Updated: 2022/11/19 18:19:15 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int n, int fd)
{
	long	res;

	res = n;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		res = -res;
	}
	if (res > 9)
		ft_putnbr_fd(res / 10, fd);
	ft_putchar_fd(res % 10 + '0', fd);
}
