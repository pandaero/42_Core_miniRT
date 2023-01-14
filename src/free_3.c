/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_3.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:53:38 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/14 20:25:05 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdlib.h>

//Function frees the program struct.
void	free_program(t_program *program)
{
	free_obj_lists(program->first_objlist);
	free(program);
}

//Function frees all the object linked lists.
void	free_obj_lists(t_objlist *first)
{
	t_objlist	*curr;

	curr = first;
	while (curr != NULL)
	{
		free_list(curr);
		curr = curr->next;
	}
}

//Function frees an entire object linked list.
void	free_list(t_objlist *list)
{
	t_obj	*curr;

	curr = list->first;
	while (curr != NULL)
	{
		free_object(curr);
		curr = curr->next;
	}
	free(list);
}

//Function frees an object.
void	free_object(t_obj *object)
{
	if (object->elem == EMPTY)
	{
		free(object);
		return ;
	}
	if (object->elem == POINT)
		free_point(object->point);
	if (object->elem == DIRECTION)
		free_direction(object->direction);
	if (object->elem == VECTOR)
		free_vector(object->vector);
	if (object->elem == RAY)
		free_ray(object->ray);
	if (object->elem == CAMERA)
		free_camera(object->camera);
	if (object->elem == SCREEN)
		free_screen(object->screen);
	free(object);
}
