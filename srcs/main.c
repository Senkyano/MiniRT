/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:30:36 by eturiot           #+#    #+#             */
/*   Updated: 2024/05/29 13:33:08 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av, char **env)
{
	t_image	img;
	(void)env;

	if (ac == 2)
	{
		if (parsing(&(img.scene), av[1]))
			ft_printf("check in main\n");
	}
	else
		return (ft_printf_fd(2, "Error\n%s\n", ENUMBER_ARGS), 1);
	return (0);
}
