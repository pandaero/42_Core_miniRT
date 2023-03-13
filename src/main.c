/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/16 19:34:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 13:54:22 by pandalaf         ###   ########.fr       */
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
	if (FILEOUT)
		image_draw(program);
	if (FILEOUT != 2)
	{
		mlx_initialise(program);
		window_draw(program);
		mlx_looping(program);
	}
	free_program(program);
	return (EXIT_SUCCESS);
}
