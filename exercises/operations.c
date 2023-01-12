/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:35:01 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/12 19:24:22 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./exercise.h"

/*The return value of this function needs to have memory allocated to it.*/
t_point *substract_vectors(t_point *V, t_point *W)
{
	t_point *ret_val;

	ret_val = malloc(sizeof(t_point));
	ret_val->x = V->x - W->x;
	ret_val->y = V->y - W->y;
	ret_val->z = V->z - W->z;
	return (ret_val);
}

double	dot(t_point *first, t_point *second)
{
	return ((first->x * second->x) + \
	(first->y * second->y) + \
	(first->z * second->z));
}

double	length_two_points(t_point *point_one, t_point *point_two)
{
	double	distance;

	distance = sqrt(pow(point_two->x - point_one->x, 2)
			+ pow(point_two->y - point_one->y, 2)
			+ pow(point_two->z - point_one->z, 2));
	return (distance);
}

t_point	*direction_two_points(t_point *start, t_point *end)
{
	t_point	*new;

	if (start == end || (start->x == end->x
			&& start->y == end->y
			&& start->z == end->z))
		return (NULL);
	new = (t_point *)malloc(sizeof(t_point));
	if (!new)
		return (NULL);
	new->x = (end->x - start->x) / length_two_points(start, end);
	new->y = (end->y - start->y) / length_two_points(start, end);
	new->z = (end->z - start->z) / length_two_points(start, end);
	return (new);
}
