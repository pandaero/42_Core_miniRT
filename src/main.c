/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:34:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/31 20:30:41 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <unistd.h>
#include <stdlib.h>

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
	render_screen(program);
	mlx_initialise(program);
	window_draw(program);
	mlx_looping(program);
	free_program(program);
	return (EXIT_SUCCESS);
}
