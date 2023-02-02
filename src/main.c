/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:34:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/01 17:37:31 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <unistd.h>
#include <stdlib.h>

//for test
#include <stdio.h>

//Program runs parsing routine, and renders the scene described.
int	main(int argc, char **argv)
{
	t_program	*program;

	if (argc != 2)
	{
		ft_putstr_fd("Error: Invalid number of arguments.\n", STDERR_FILENO);
		return (EXIT_FAILURE);
	}
	program = program_create();
	parse_input_file(program, argv[1]);
	// printf("Segfault check\n");
	// exit(0);
	render_screen(program);
	// printf("Sefault \n");
	// exit(0);
	mlx_initialise(program);
	window_draw(program);
	mlx_looping(program);
	free_program(program);
	return (EXIT_SUCCESS);
}
