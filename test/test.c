#include "test.h"
#include <stdio.h>

//Function prints the information of an object to STDOUT.
void	object_print(t_obj *object)
{
	if (object->elem == POINT)
		printf("POINT: x:%4.2f y:%4.2f z:%4.2f\n",
					object->point->x_co, object->point->y_co,
					object->point->z_co);
	if (object->elem == DIRECTION)
		printf("DIRECTION: x_comp:%4.2f y_comp:%4.2f z_comp:%4.2f\n",
					object->direction->x_comp, object->direction->y_comp,
					object->direction->z_comp);
	if (object->elem == VECTOR)
		printf("VECTOR: start:(%4.2f, %4.2f, %4.2f) end:(%4.2f, %4.2f, %4.2f) mag:%4.2f dir:(%4.2f, %4.2f, %4.2f)\n", object->vector->start->x_co, object->vector->start->y_co, object->vector->start->z_co, object->vector->end->x_co, object->vector->end->y_co, object->vector->end->z_co, object->vector->mag, object->vector->dir->x_comp, object->vector->dir->y_comp, object->vector->dir->z_comp);
	if (object->elem == RAY)
		printf("RAY: origin:(%4.2f, %4.2f, %4.2f) dir:(%4.2f, %4.2f, %4.2f)\n", object->ray->ray_orig->x_co, object->ray->ray_orig->y_co, object->ray->ray_orig->z_co, object->ray->ray_dir->x_comp, object->ray->ray_dir->y_comp, object->ray->ray_dir->z_comp);
}

//Function displays the objects within an object linked list on STDOUT.
void	list_print(t_objlist *list)
{
	t_obj	*curr;
	int		counter;

	printf("--- LIST %2d ---\n", list->list_id);
	printf("No. of objects: %3d\n", list->num_objects);
	counter = 0;
	curr = list->first;
	while (curr != NULL)
	{
		counter++;
		printf("--- OBJECT %3d ---\n", counter);
		object_print(curr);
		curr = curr->next;
	}
	printf("\n");
}
