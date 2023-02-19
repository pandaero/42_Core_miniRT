/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:52:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/20 00:29:44 by pandalaf         ###   ########.fr       */
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

//Function fills an intersection for a pixel.
static void	intersection_pass(t_program *program, t_obj *obj, int ii[2])
{
	t_inter_pass	strct;
	t_pixel			*pix;

	strct.list = program->objlist;
	strct.cam = camera_program(program);
	strct.scr = screen_program(program);
	pix = strct.scr->pixels[ii[0]][ii[1]];
	strct.dir = direction_two_points(strct.cam->location, pix->point);
	strct.ray = ray_start_dir(pix->point, strct.dir);
	strct.temp = intersection_ray_obj(strct.ray, obj);
	if (object_first_list(program->objlist) == obj)
	{
		pix->itsct = intersection_ray_obj(strct.ray, obj);
		intersection_colour(strct.list, pix->itsct);
	}
	if (strct.temp->distance < pix->itsct->distance && strct.temp->distance > 0)
	{
		free_intersection(pix->itsct);
		pix->itsct = strct.temp;
		intersection_colour(strct.list, pix->itsct);
	}
	else
		free_intersection(strct.temp);
	pix->itsct->object = obj;
	free_direction(strct.dir);
	free_ray(strct.ray);
}

//Function performs a secondary intersection calculation for a pixel.
void	sec_itsct_pass(t_program *program, t_obj *obj, int ii[2])
{
	t_screen	*screen;
	t_pixel		*pix;
	t_obj		*object;
	t_diffuse	*light;
	double		tolight;
	t_intersect	*temp_intrsct;
	t_ray		*ray_sec;

	screen = screen_program(program);
	object = object_first_list(program->objlist);
	light = diffuse_objlist(program->objlist);
	pix = screen->pixels[ii[0]][ii[1]];
	if (pix->itsct->state == INTERSECTED)
	{
		tolight = distance_two_points(pix->itsct->point, light->position);
		while (object->next && object != obj)
		{
			ray_sec = ray_two_points(pix->itsct->point, light->position);
			temp_intrsct = intersection_ray_obj(ray_sec, object);
			if (pix->itsct->object == temp_intrsct->object && temp_intrsct->object == obj)
				object = object->next;
			if (temp_intrsct->distance <= tolight && temp_intrsct->distance > 0)
			{
				pix->sec_itsct = sec_intersect_create();
				pix->sec_itsct->state = INTERSECTED;
				pix->sec_itsct->distance = temp_intrsct->distance;
				pix->sec_itsct->parent = pix->itsct;
				pix->sec_itsct->shadow = colour_full(SHADOW);
			}
			free_intersection(temp_intrsct);
			free_ray(ray_sec);
			// pix->sec_itsct = sec_itsct_calc(program->objlist, pix, object);
			object = object->next;
		}
	}
}

//Function performs a render through the screen for the input object.
void	render_intersection_pass(t_program *program, t_obj *object)
{
	int	ii[2];

	ii[0] = 0;
	while (ii[0] < WIN_HEIGHT)
	{
		ii[1] = 0;
		while (ii[1] < WIN_WIDTH)
		{
			intersection_pass(program, object, ii);
			if (diffuse_objlist(program->objlist))
				sec_itsct_pass(program, object, ii);
			ii[1]++;
		}
		ii[0]++;
	}
	object->ren = 1;
	program->objlist->num_unren--;
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

	//first intersection
	unren = program->objlist->num_unren;
	sec_unren = program->objlist->num_sec_unren;
	object = object_first_list(program->objlist);
	dir = direction_two_points(camera_program(program)->location, pixel->point);
	ray = ray_start_dir(pixel->point, dir);
	while (object && unren > 0)
	{
		temp = intersection_ray_obj(ray, object);
		if (object == object_first_list(program->objlist))
		{
			pixel->itsct = intersection_ray_obj(ray,object);
			unren--;
			object = object->next;
			continue ;
		}
		if (temp->distance < pixel->itsct->distance && temp->distance > 0)
		{
			// free_intersection(pixel->itsct);
			pixel->itsct = temp;
			intersection_colour(program->objlist, pixel->itsct);
		}
		else
			free_intersection(temp);
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
		// ft_printf("starting sec\n");
		object = object_first_list(program->objlist);
		dir = direction_two_points(pixel->itsct->point, diffuse_objlist(program->objlist)->position);
		ray = ray_start_dir(pixel->itsct->point, dir);
		while (object && sec_unren > 0)
		{
			// ft_printf("sec intersection\n");
			if (object == pixel->itsct->object)
			{
				object = object->next;
				sec_unren--;
				continue ;
			}
			temp = intersection_ray_obj(ray, object);
			if (temp->state == INTERSECTED && temp->distance <= distance_two_points(pixel->itsct->point, diffuse_objlist(program->objlist)->position))
			{
				// ft_printf("sec intersection full\n");
				pixel->sec_itsct = sec_intersect_create();
				pixel->sec_itsct->state = INTERSECTED;
				pixel->sec_itsct->distance = temp->distance;
				pixel->sec_itsct->parent = pixel->itsct;
				pixel->sec_itsct->shadow = colour_full(SHADOW);
			}
			// ft_printf("sec passed\n");
			free_intersection(temp);
			sec_unren--;
			object = object->next;
		}
		// free_direction(dir);
		// free_ray(ray);
	}
	//Assign colours to pixels
	if (pixel->sec_itsct)
	{
		if (pixel->sec_itsct->state == INTERSECTED)
		{
			// ft_printf("sec colouring\n");
			pixel->colour = colour_subtract(pixel->itsct->colour, pixel->sec_itsct->shadow);
		}
		else
		{
			// ft_printf("sec non-colouring\n");
			pixel->colour = colour_copy(pixel->itsct->colour);
		}
	}
	else if (pixel->itsct->state == INTERSECTED)
	{
		// ft_printf("prim colouring\n");
		pixel->colour = colour_copy(pixel->itsct->colour);
	}
	else
	{
		// ft_printf("prim non-colourin\n");
		pixel->colour = colour_ambient_list(program->objlist);
	}
}
