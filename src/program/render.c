/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/20 02:55:08 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/02 17:12:11 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function fills the screen with ambient light.
void	render_empty_scene(t_program *program)
{
	int			ii[2];
	t_screen	*scr;
	t_pixel		*pixel;

	scr = screen_program(program);
	ii[0] = 0;
	while (ii[0] < WIN_HEIGHT)
	{
		ii[1] = 0;
		while (ii[1] < WIN_WIDTH)
		{
			pixel = scr->pixels[ii[0]][ii[1]];
			pixel->intrsct = intersect_create();
			pixel->intrsct->colour = colour_ambient_list(program->objlist);
			ii[1]++;
		}
		ii[0]++;
	}
}

//Function creates a screen from camera, then loops rendering through objlist.
void	render_screen(t_program *program)
{
	t_screen	*screen;
	t_obj		*obj;

	screen = screen_camera(WIN_WIDTH, WIN_HEIGHT, camera_program(program));
	list_add_object(program->objlist, object_screen(screen));
	if (program->objlist->num_unrendered == 0)
	{
		render_empty_scene(program);
		return ;
	}
	while (program->objlist->num_unrendered > 0)
	{
		obj = object_unrendered_list(program->objlist);
		render_intersection_pass(program, obj);
	}
}

//Function assigns colour to an intersection.
void	intersection_colour(t_objlist *list, t_intersect *intersect)
{
	if (intersect->state == 0)
	{
		//intersect->colour = WHITE;
		intersect->colour = colour_ambient_list(list);
		return ;
	}
	intersect->colour = colour_lighting(list, intersect);
}

//Function fills an intersection for a pixel.
static void	intersection_pass(t_program *program, t_obj *obj, int ii[2])
{
	t_camera	*cam;
	t_screen	*scr;
	t_direction	*dir;
	t_ray		*ray;
	t_objlist	*list;

	list = program->objlist;
	cam = camera_program(program);
	scr = screen_program(program);
	dir = direction_two_points(cam->location, scr->pixels[ii[0]][ii[1]]->point);
	ray = ray_start_dir(scr->pixels[ii[0]][ii[1]]->point, dir);
	scr->pixels[ii[0]][ii[1]]->intrsct = intersection_ray_obj(ray, obj);
	intersection_colour(list, scr->pixels[ii[0]][ii[1]]->intrsct);
	free_direction(dir);
	free_ray(ray);
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
			ii[1]++;
		}
		ii[0]++;
	}
	object->unrendered = 0;
	program->objlist->num_unrendered--;
}

//Function assigns each pixel its colour.
void	window_draw(t_program *program)
{
	int	i;
	int	j;

	i = 0;
	while (i < WIN_HEIGHT)
	{
		j = 0;
		while (j < WIN_WIDTH)
		{
			quick_put_pixel(program->mldt->imdt, j, i, \
					screen_program(program)->pixels[i][j]->intrsct->colour);
			j++;
		}
		i++;
	}
}
