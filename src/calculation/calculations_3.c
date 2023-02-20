/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:48:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/20 03:12:05 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//Function works out the dot product of two vectors.
double	vector_dot(t_vector *first, t_vector *second)
{
	return (first->x_comp * second->x_comp + \
			first->y_comp * second->y_comp + \
			first->z_comp * second->z_comp);
}

//Function returns the size of a ft_split-created array.
int	split_size(char **str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

//Function that returns a reversed direction, inherit both directions
t_direction	*reverse_direction(t_direction *direction)
{
	t_direction	*reverse_direction;

	reverse_direction = direction_components(\
	-direction->x_comp, \
	-direction->y_comp, \
	-direction->z_comp);
	return (reverse_direction);
}

//Function works out the closest surface normal to given cylinder intersection.
t_direction	*surface_normal_cylinder(t_intersect *itsct, t_cylinder *cylinder)
{
	t_direction	*dir;
	t_direction	*cyl;
	double		cx;
	double		cy;
	double		cz;
	double		dist;

	cyl = cylinder->orientation;
	cx = itsct->point->x_co - cylinder->centre->x_co;
	cy = itsct->point->y_co - cylinder->centre->y_co;
	cz = itsct->point->z_co - cylinder->centre->z_co;
	dist = sqrt(pow(cx, 2) + pow(cy, 2));

	if (dist < 0.001)
	{
		if (fabs(cz - cylinder->height) / 2 < 0.001)
			dir = direction_components(0,0,1);
		else if (fabs(cz + cylinder->height) / 2 < 0.001)
			dir = direction_components(0,0,-1);
		else
			dir = direction_components(cx, cy, cz - (cz / fabs(cz)) * (cylinder->height / 2));
		return (dir);
	}
	else
		dir = direction_components((cx / dist) * cyl->z_comp, \
									0 - (cx / dist) * cyl->z_comp, \
									(cx / dist) * cyl->y_comp - (cy / dist) * cyl->x_comp);
	return (dir);
}

//Function works out the surface normal vector closest to a point for an object.
t_direction	*surface_normal_object(t_intersect *itsct, t_obj *object)
{
	t_direction	*dir;

	if (object->elem == PLANE)
		dir = direction_copy(object->plane->normal);
	if (object->elem == SPHERE)
		dir = direction_two_points(object->sphere->centre, itsct->point);
	if (object->elem == CYLINDER)
		dir = surface_normal_cylinder(itsct, object->cylinder);
	return (dir);
}
