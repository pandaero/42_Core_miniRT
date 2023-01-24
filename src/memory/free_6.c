/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:03:35 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/20 00:08:20 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function frees a 2D char array made from ft_split. Returns zero.
int	free_split_ret_int_zero(char **charr)
{
	free_split(charr);
	return (0);
}

//Function frees a pointer, and returns a double -1.
double	free_ret_double_minusone(void *ptr)
{
	free(ptr);
	return ((double) -1);
}

//Function frees a light.
void	free_diffuse(t_diffuse *diffuse)
{
	free_point(diffuse->position);
	free(diffuse);
}

//Function frees a cylinder and returns NULL;
void	*free_cylinder_ret_null(t_cylinder *cylinder)
{
	free_cylinder(cylinder);
	return (NULL);
}
