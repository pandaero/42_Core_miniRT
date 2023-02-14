/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 00:29:56 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/13 15:32:24 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function frees all the allocations belonging to a vector object.
void	free_vector(t_vector *vector)
{
	free_direction(vector->dir);
	free(vector);
}

//Function frees all the allocations belonging to a vector object, returns null.
void	*free_vector_null(t_vector *vector)
{
	free_direction(vector->dir);
	free(vector);
	return (NULL);
}

//Function frees all the allocations belonging to a ray object.
void	free_ray(t_ray *ray)
{
	free_point(ray->ray_orig);
	free_direction(ray->ray_dir);
	free(ray);
}

//Function frees all the allocations belonging to a ray, returns null.
void	*free_ray_null(t_ray *ray)
{
	free_point(ray->ray_orig);
	free_direction(ray->ray_dir);
	free(ray);
	return (NULL);
}

//Function frees all the allocations belonging to a camera.
void	free_camera(t_camera *camera)
{
	free_point(camera->location);
	free_direction(camera->view_dir);
	free(camera);
}
