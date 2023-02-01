/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:53:38 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/20 13:59:58 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function frees the program struct.
void	free_program(t_program *program)
{
	if (program->mldt)
	{
		free(program->mldt->mlx);
		free(program->mldt->window);
		free(program->mldt->imdt->image);
	}
	if (program->objlist)
		free_list(program->objlist);
	free(program);
}

//Function frees an entire object linked list.
void	free_list(t_objlist *list)
{
	t_obj	*curr;
	t_obj	*next;

	curr = list->first;
	while (curr != NULL)
	{
		next = curr->next;
		free_object(curr);
		curr = next;
	}
	free(list);
}

//Function frees an object. (cont.)
void	free_object_2(t_obj *object)
{
	if (object->elem == CYLINDER)
		free_cylinder(object->cylinder);
	if (object->elem == SPHERE)
		free_sphere(object->sphere);
	if (object->elem == DIFFUSE)
		free_diffuse(object->diffuse);
	free(object);
}

//Function frees an object.
void	free_object(t_obj *object)
{
	if (object->elem == EMPTY || object->elem == INVALID)
	{
		free(object);
		return ;
	}
	else if (object->elem == AMBIENT)
		free_ambient(object->ambient);
	else if (object->elem == POINT)
		free_point(object->point);
	else if (object->elem == DIRECTION)
		free_direction(object->direction);
	else if (object->elem == VECTOR)
		free_vector(object->vector);
	else if (object->elem == RAY)
		free_ray(object->ray);
	else if (object->elem == CAMERA)
		free_camera(object->camera);
	else if (object->elem == SCREEN)
		free_screen(object->screen);
	else if (object->elem == PLANE)
		free_plane(object->plane);
	else
		return (free_object_2(object));
	free(object);
}
