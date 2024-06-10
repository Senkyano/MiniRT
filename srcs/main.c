/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eturiot <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/29 13:30:36 by eturiot           #+#    #+#             */
/*   Updated: 2024/06/10 16:18:00 by eturiot          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "miniRT.h"

int	main(int ac, char **av, char **env)
{
	int		fd;
	t_image	img;

	(void)env;
	if (ac == 2)
	{
		fd = open_str(av[1]);
		if (fd)
		{
			if (parsing(&(img.scene), fd))
				ft_printf("check in main\n");
		}
	}
	else
		return (ft_printf_fd(2, "Error\n%s\n", ENUMBER_ARGS), 1);
	return (0);
}
