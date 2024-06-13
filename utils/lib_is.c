/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lib_is.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/29 15:44:50 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/13 16:40:52 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lib_utils.h"
#include <stdbool.h>

bool	is_space(char c)
{
	if (c <= ' ' || c >= 127)
		return (true);
	return (false);
}

bool	is_char(char c)
{
	if ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))
		return (true);
	return (false);
}

bool	is_num(char c)
{
	if (c >= '0' && c <= '9')
		return (true);
	return (false);
}

bool	is_numberf(char *str)
{
	int		i;
	bool	dot;

	i = -1;
	dot = false;
	if (str[i] == '-' || str[i] == '+')
		i++;
	while (str[++i])
	{
		if (!is_num(str[i]) && str[i] != '.')
			return (false);
		if (str[i] == '.')
		{
			if (dot)
				return (false);
			dot = true;
		}
	}
	return (true);
}

bool	is_number(char *str)
{
	int		i;

	i = -1;
	if (str[i] == '-')
		i++;
	while (str[++i])
	{
		if (!is_num(str[i]) && str[i] != '-')
			return (false);
	}
	return (true);
}
