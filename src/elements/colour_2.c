/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/24 18:48:46 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/24 23:00:12 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

// colour += colour_diffuse_lin();
//Function works out the lighting of an intersection based on objects.
t_colour	colour_lighting(t_objlist *objlist, t_intersect *intersect)
{
	t_colour	colour;
	t_colour	objcolour;
	t_ambient	*ambient;
	t_diffuse	*diffuse;

	ambient = ambient_objlist(objlist);
	diffuse = diffuse_objlist(objlist);
	objcolour = colour_object(intersect->object);
	colour = colour_ambient(objcolour, ambient);
	colour += colour_diffuse_inverse_square(diffuse, intersect->point);
	if (colour > WHITE)
		colour = WHITE;
	return (colour);
}

//Function works out the ambient light colour from an object list.
t_colour	colour_ambient_list(t_objlist *objlist)
{
	t_ambient	*ambient;
	t_colour	colour;

	ambient = ambient_objlist(objlist);
	colour = colour_ambient(BLACK, ambient);
	return (colour);
}