/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:11:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/06/03 13:12:57 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	t_scene	scene;

	lib_memset(&scene, 0, sizeof(t_scene));
	if (argc != 2)
		return (print_error(RED"Error : \nInvalid number of arguments\n"RST), 0);
	if (!last_cmp(argv[1], ".rt"))
		return (print_error(RED"Error : \nInvalid file extension\n"RST), 0);
	if (!extract_file(argv[1], &scene))
		return (1);
}
