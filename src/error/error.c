/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:56:44 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/20 04:24:42 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <unistd.h>

/*
//Function prints an memory allocation error message, frees program, exits.
void	error_malloc_exit(t_program *program, const char *str)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	if (ft_strncmp(str, "PROGRAM", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Program data struct creation: ", STDERR_FILENO);
	if (ft_strncmp(str, "LIST", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("List creation: ", STDERR_FILENO);
	if (ft_strncmp(str, "OBJECT", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Object creation: ", STDERR_FILENO);
	if (ft_strncmp(str, "POINT", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Point creation: ", STDERR_FILENO);
	if (ft_strncmp(str, "DIRECTION", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Direction creation: ", STDERR_FILENO);
	if (ft_strncmp(str, "VECTOR", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Vector creation: ", STDERR_FILENO);
	if (ft_strncmp(str, "RAY", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Ray creation: ", STDERR_FILENO);
	ft_putstr_fd("Couldn't allocate memory.\n", STDERR_FILENO);
	free_program(program);
	exit (EXIT_FAILURE);
}
*/

//Function prints a file error, frees the program memory, and exits,
void	error_file_exit(t_program *program, const char *str)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	if (ft_strncmp(str, "EXTENSION", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Incorrect file extension.\n", STDERR_FILENO);
	if (ft_strncmp(str, "CONTENT", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Forbidden characters in file.\n", STDERR_FILENO);
	if (ft_strncmp(str, "FORMATTING", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Invalid input formatting.\n", STDERR_FILENO);
	if (ft_strncmp(str, "ELEMENTS", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Invalid scene elements.\n", STDERR_FILENO);
	free_program(program);
	exit (EXIT_FAILURE);
}

//Function prints out an element creation error, frees memory and exits program.
void	error_object_creation_exit(t_program *program, const char *str)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	if (ft_strncmp(str, "AMBIENT", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Ambient light creation.\n", STDERR_FILENO);
	if (ft_strncmp(str, "CAMERA", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Camera and screen creation.\n", STDERR_FILENO);
	if (ft_strncmp(str, "LIGHT", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Light creation.\n", STDERR_FILENO);
	if (ft_strncmp(str, "PLANE", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Plane creation.\n", STDERR_FILENO);
	if (ft_strncmp(str, "SPHERE", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Sphere creation.\n", STDERR_FILENO);
	if (ft_strncmp(str, "CYLINDER", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Cylinder creation.\n", STDERR_FILENO);
	free_program(program);
	exit (EXIT_FAILURE);
}

//Function prints error for file open, frees program memory and exits.
void	error_file_open_exit(t_program *program)
{
	ft_putstr_fd("Error: Couldn't open file.\n", STDERR_FILENO);
	free_program(program);
	exit (EXIT_FAILURE);
}

//Function prints error MLX, frees program memory and exits.
void	error_mlx_exit(t_program *program)
{
	ft_putstr_fd("Error: Couldn't initialise MLX.\n", STDERR_FILENO);
	free_program(program);
	exit (EXIT_FAILURE);
}
