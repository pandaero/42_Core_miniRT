/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:48:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/23 15:58:55 by pbiederm         ###   ########.fr       */
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
	t_surf_norm	st;

	st.cyl = cylinder->orientation;
	st.cx = itsct->point->x_co - cylinder->centre->x_co;
	st.cy = itsct->point->y_co - cylinder->centre->y_co;
	st.cz = itsct->point->z_co - cylinder->centre->z_co;
	st.dist = sqrt(pow(st.cx, 2) + pow(st.cy, 2));
	if (st.dist < 0.001)
	{
		if (fabs(st.cz - cylinder->height) / 2 < 0.001)
			st.dir = direction_copy(cylinder->orientation);
		else if (fabs(st.cz + cylinder->height) / 2 < 0.001)
			st.dir = direction_reverse(cylinder->orientation);
		else
			st.dir = direction_components(st.cx, st.cy, st.cz - \
			(st.cz / fabs(st.cz)) * (cylinder->height / 2));
		return (st.dir);
	}
	else
		st.dir = direction_components((st.cx / st.dist) * st.cyl->z_comp, \
		0 - (st.cx / st.dist) * st.cyl->z_comp, (st.cx / st.dist) * \
		st.cyl->y_comp - (st.cy / st.dist) * st.cyl->x_comp);
	return (st.dir);
}

t_direction	*direction_normal_plane(t_ray *ray, t_plane *plane)
{
	t_direction	*temp;

	temp = direction_reverse(ray->ray_dir);
	if (angle_directions(temp, plane->normal) < \
		angle_directions(ray->ray_dir, plane->normal))
	{
		free_direction(temp);
		return (direction_copy(plane->normal));
	}
	else
	{
		free_direction(temp);
		return (direction_reverse(plane->normal));
	}
}

//Function works out the surface normal vector closest to a point for an object.
t_direction	*surface_normal_object(t_intersect *itsct, t_ray *ray, t_obj *object)
{
	t_direction	*dir;

	if (object->elem == PLANE)
		dir = direction_normal_plane(ray, object->plane);
	if (object->elem == SPHERE)
		dir = direction_two_points(object->sphere->centre, itsct->point);
	if (object->elem == CYLINDER)
		dir = surface_normal_cylinder(itsct, object->cylinder);
	return (dir);
}
