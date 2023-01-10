/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_elements.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 17:47:39 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/10 21:27:51 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"
#include <stdlib.h>

//Function frees all the allocations belonging to a point object.
void	free_point(t_point *point)
{
	free(point);
}

//Function frees all the allocations belonging to a direction object.
void	free_direction(t_direction *direction)
{
	free(direction);
}

//Function frees all the allocations belonging to a vector object.
void	free_vector(t_vector *vector)
{
	free_point(vector->start);
	free_point(vector->end);
	free_direction(vector->dir);
	free(vector);
}

//Function frees all the allocations belonging to a ray object.
void	free_ray(t_ray *ray)
{
	free_point(ray->ray_orig);
	free_direction(ray->ray_dir);
	free(ray);
}
