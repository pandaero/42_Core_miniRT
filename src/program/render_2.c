/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:52:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/20 03:12:28 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function assigns colour to an intersection.
void	intersection_colour(t_objlist *list, t_intersect *intersect)
{
	if (intersect->state == MISSED)
	{
		intersect->colour = colour_ambient_list(list);
		return ;
	}
	colour_lighting(list, intersect);
}

//Function renders a single pixel fully, regarding all possible intersections.
void	render_pixel(t_program *program, t_pixel *pixel)
{
	t_obj		*object;
	t_intersect	*temp;
	t_ray		*ray;
	t_direction	*dir;
	int			unren;
	int			sec_unren;

	// ft_printf("intersection time\n");
	//first intersection
	unren = program->objlist->num_unren;
	sec_unren = program->objlist->num_sec_unren;
	object = object_first_list(program->objlist);
	dir = direction_two_points(camera_program(program)->location, pixel->point);
	ray = ray_start_dir(pixel->point, dir);
	while (object && unren > 0)
	{
		temp = intersection_ray_obj(ray, object);
		if (temp->state == MISSED)
		{
			temp->colour = colour_ambient_list(program->objlist);
		}
		else
		{
			temp->colour = colour_ambient(colour_object(temp->object), ambient_objlist(program->objlist));
		}
		if (object == object_first_list(program->objlist))
		{
			pixel->itsct = intersection_ray_obj(ray,object);
			if (pixel->itsct->state == MISSED)
				pixel->itsct->colour = colour_ambient_list(program->objlist);
			else
				pixel->itsct->colour = colour_ambient(colour_object(pixel->itsct->object), ambient_objlist(program->objlist));
			unren--;
			object = object->next;
			free_intersection(temp);
			continue ;
		}
		if (temp->distance < pixel->itsct->distance && temp->distance > 0)
		{
			free_intersection(pixel->itsct);
			pixel->itsct = temp;
		}
		else
		{
			free_intersection(temp);
		}
		unren--;
		object = object->next;
	}
	free_ray(ray);
	free_direction(dir);
	//primary colours
	if (pixel->itsct->state == MISSED)
		pixel->itsct->colour = colour_ambient_list(program->objlist);
	else
		colour_lighting(program->objlist, pixel->itsct);
	//secondary intersection
	if (diffuse_objlist(program->objlist) && pixel->itsct->state == INTERSECTED)
	{
		object = object_first_list(program->objlist);
		dir = direction_two_points(pixel->itsct->point, diffuse_objlist(program->objlist)->position);
		ray = ray_start_dir(pixel->itsct->point, dir);
		while (object && sec_unren > 0)
		{
			if (object == pixel->itsct->object)
			{
				object = object->next;
				sec_unren--;
				continue ;
			}
			temp = intersection_ray_obj(ray, object);
			if (temp->state == INTERSECTED && temp->distance <= distance_two_points(pixel->itsct->point, diffuse_objlist(program->objlist)->position))
			{
				pixel->sec_itsct = sec_intersect_create();
				pixel->sec_itsct->state = INTERSECTED;
				pixel->sec_itsct->distance = temp->distance;
				pixel->sec_itsct->parent = pixel->itsct;
				pixel->sec_itsct->shadow = colour_full(SHADOW);
			}
			free_intersection(temp);
			sec_unren--;
			object = object->next;
		}
		free_direction(dir);
		free_ray(ray);
	}
	//Assign colours to pixels
	if (pixel->sec_itsct)
	{
		if (pixel->sec_itsct->state == INTERSECTED)
			pixel->colour = colour_subtract(pixel->itsct->colour, pixel->sec_itsct->shadow);
		else
			pixel->colour = colour_copy(pixel->itsct->colour);
	}
	else if (pixel->itsct->state == INTERSECTED)
		pixel->colour = colour_copy(pixel->itsct->colour);
	else
		pixel->colour = colour_ambient_list(program->objlist);
}
