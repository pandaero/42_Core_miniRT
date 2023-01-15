/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:35:01 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/15 15:26:33 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./intersections.h"

/*The return value of this function needs to have memory allocated to it.*/
t_Vector3 *substract_vectors(t_Vector3 *V, t_Vector3 *W)
{
	t_Vector3 *ret_val;

	ret_val = malloc(sizeof(t_Vector3));
	ret_val->x = V->x - W->x;
	ret_val->y = V->y - W->y;
	ret_val->z = V->z - W->z;
	return (ret_val);
}

double	dot(t_Vector3 *first, t_Vector3 *second)
{
	return ((first->x * second->x) + \
	(first->y * second->y) + \
	(first->z * second->z));
}

double	length_two_points_local(t_Vector3 *point_one, t_Vector3 *point_two)
{
	double	distance;

	distance = sqrt(pow(point_two->x - point_one->x, 2)
			+ pow(point_two->y - point_one->y, 2)
			+ pow(point_two->z - point_one->z, 2));
	return (distance);
}

t_Vector3	*direction_two_points_local(t_Vector3 *start, t_Vector3 *end)
{
	t_Vector3	*new;

	if (start == end || (start->x == end->x
			&& start->y == end->y
			&& start->z == end->z))
		return (NULL);
	new = (t_Vector3 *)malloc(sizeof(t_Vector3));
	if (!new)
		return (NULL);
	new->x = (end->x - start->x) / length_two_points_local(start, end);
	new->y = (end->y - start->y) / length_two_points_local(start, end);
	new->z = (end->z - start->z) / length_two_points_local(start, end);
	return (new);
}

t_Vector3	*scalar_times_vector(double scalar, t_Vector3 *vector)
{
	t_Vector3 *product;

	product = malloc(sizeof(t_Vector3));
	product->x = scalar * vector->x;
	product->y = scalar * vector->y;
	product->z = scalar * vector->z;
	return (product);
}