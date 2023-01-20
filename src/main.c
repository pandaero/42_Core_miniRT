/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:34:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/20 03:33:45 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
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
