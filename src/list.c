/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 12:02:10 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/13 01:02:19 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises a new object linked list in the program.
t_objlist	*list_create(t_program *program)
{
	t_objlist	*new;

	new = (t_objlist *)malloc(sizeof(t_objlist));
	new->num_objects = 0;
	new->first = NULL;
	new->last = NULL;
	program_add_obj_list(program, new);
	return (new);
}

//Function adds an object to a linked list.
void	list_add_object(t_objlist *list, t_obj *object)
{
	if (list->num_objects == 0)
	{
		list->first = object;
		object->prev = NULL;
	}
	else
	{
		object->prev = list->last;
		list->last->next = object;
	}
	list->last = object;
	object->next = NULL;
	list->num_objects++;
}

//Function removes an object from a linked list, freeing its memory.
void	list_remove_object(t_objlist *list, t_obj *object)
{
	if (list->first == object)
	{
		list->first = object->next;
		if (object->next != NULL)
			object->next->prev = NULL;
	}
	else if (list->last == object)
	{
		list->last = object->prev;
		if (object->prev != NULL)
			object->prev->next = NULL;
	}
	else
	{
		object->next->prev = object->prev;
		object->prev->next = object->next;
	}
	free_object(object);
	list->num_objects--;
}
