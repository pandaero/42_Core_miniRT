#include "test.h"
#include <stdio.h>

//Function prints the information of an object to STDOUT.
void	object_print(t_obj *object)
{
	if (object->elem == AMBIENT)
		printf("AMBIENT: r:%4.2f col:%08X\n", object->ambient->ratio, object->ambient->colour);
	if (object->elem == LIGHT)
		printf("LIGHT: r:%4.2f pos:(%4.2f, %4.2f, %4.2f)\n", object->light->ratio, object->light->position->x_co, object->light->position->y_co, object->light->position->z_co);
	if (object->elem == POINT)
		printf("POINT: x:%4.2f y:%4.2f z:%4.2f\n",
					object->point->x_co, object->point->y_co,
					object->point->z_co);
	if (object->elem == DIRECTION)
		printf("DIRECTION: x_comp:%4.2f y_comp:%4.2f z_comp:%4.2f\n",
					object->direction->x_comp, object->direction->y_comp,
					object->direction->z_comp);
	if (object->elem == VECTOR)
		printf("VECTOR: comps:(%4.2f, %4.2f, %4.2f) mag:%4.2f dir:(%4.2f, %4.2f, %4.2f)\n", object->vector->x_comp, object->vector->y_comp, object->vector->z_comp, object->vector->mag, object->vector->dir->x_comp, object->vector->dir->y_comp, object->vector->dir->z_comp);
	if (object->elem == RAY)
		printf("RAY: origin:(%4.2f, %4.2f, %4.2f) dir:(%4.2f, %4.2f, %4.2f)\n", object->ray->ray_orig->x_co, object->ray->ray_orig->y_co, object->ray->ray_orig->z_co, object->ray->ray_dir->x_comp, object->ray->ray_dir->y_comp, object->ray->ray_dir->z_comp);
	if (object->elem == PLANE)
		printf("PLANE: point:(%4.2f, %4.2f, %4.2f) norm:(%4.2f, %4.2f, %4.2f)\n", object->plane->point->x_co, object->plane->point->y_co, object->plane->point->z_co, object->plane->normal->x_comp, object->plane->normal->y_comp, object->plane->normal->z_comp);
	if (object->elem == CAMERA)
		printf("CAMERA: hfov:%f point:(%4.2f, %4.2f, %4.2f) dir:(%4.2f, %4.2f, %4.2f)\n", object->camera->horiz_fov, object->camera->location->x_co, object->camera->location->y_co, object->camera->location->z_co, object->camera->view_dir->x_comp, object->camera->view_dir->y_comp, object->camera->view_dir->z_comp);
	if (object->elem == SCREEN)
	{
		printf("SCREEN: ");
		printf("width:%d height:%d ", object->screen->width, object->screen->height);
		printf("centre:(%4.2f, %4.2f, %4.2f)\n", object->screen->pts->centre->x_co, object->screen->pts->centre->y_co, object->screen->pts->centre->z_co);
		printf("        dir_into:(%4.2f, %4.2f, %4.2f) ", object->screen->vecs->normal->x_comp, object->screen->vecs->normal->y_comp, object->screen->vecs->normal->z_comp);
		printf("top_left:(%4.2f, %4.2f, %4.2f)\n", object->screen->pts->tl_corner->x_co, object->screen->pts->tl_corner->y_co, object->screen->pts->tl_corner->z_co);
		printf("        first_px:(%4.2f, %4.2f, %4.2f)\n", object->screen->pts->first_px->x_co, object->screen->pts->first_px->y_co, object->screen->pts->first_px->z_co);
	}
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
