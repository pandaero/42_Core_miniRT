/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 14:56:44 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/13 01:02:31 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdlib.h>
#include <unistd.h>

//Function handles cleanly an error that requires the program to exit.
int	error_exit(t_program *program, char *str)
{
	free_program(program);
	error_malloc_print(str);
	return (EXIT_FAILURE);
}

//Function prints an memory allocation error message.
void	error_malloc_print(char *str)
{
	ft_putstr_fd("Error: ", STDERR_FILENO);
	if (ft_strncmp(str, "PROGRAM", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Program data struct creation: ", STDERR_FILENO);
	else if (ft_strncmp(str, "LIST", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("List creation: ", STDERR_FILENO);
	else if (ft_strncmp(str, "OBJECT", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Object creation: ", STDERR_FILENO);
	else if (ft_strncmp(str, "POINT", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Point creation: ", STDERR_FILENO);
	else if (ft_strncmp(str, "DIRECTION", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Direction creation: ", STDERR_FILENO);
	else if (ft_strncmp(str, "VECTOR", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Vector creation: ", STDERR_FILENO);
	else if (ft_strncmp(str, "RAY", ft_strlen(str) + 1) == 0)
		ft_putstr_fd("Ray creation: ", STDERR_FILENO);
	else
	{
		ft_putstr_fd("Unspecified\n", STDERR_FILENO);
		return ;
	}
	ft_putstr_fd("Couldn't allocate memory\n", STDERR_FILENO);
}
