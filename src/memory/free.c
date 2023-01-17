/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:47:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/17 14:38:32 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function frees a pointer and returns NULL.
void	*free_void_null(void *ptr)
{
	free(ptr);
	return (NULL);
}

//Function frees all the allocations belonging to a point object.
void	free_point(t_point *point)
{
	free(point);
}

//Function frees all the allocations belonging to a point object, returns NULL.
void	*free_point_null(t_point *point)
{
	free(point);
	return (NULL);
}

//Function frees all the allocations belonging to a direction object.
void	free_direction(t_direction *direction)
{
	free(direction);
}

//Function frees all the allocations in a direction object, returns NULL.
void	*free_direction_null(t_direction *direction)
{
	free(direction);
	return (NULL);
}
