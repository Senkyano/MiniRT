/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rihoy <rihoy@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/05/30 13:11:53 by rihoy             #+#    #+#             */
/*   Updated: 2024/05/30 14:25:34 by rihoy            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minirt.h"

int	main(int argc, char **argv)
{
	if (argc != 2)
		return (print_error(RED"Error : \nInvalid number of arguments\n"RST), 0);
	if (!last_cmp(argv[1], ".rt"))
		return (print_error(RED"Error : \nInvalid file extension\n"RST), 0);
	if (!extract_file(argv[1]))
		return (1);
}
