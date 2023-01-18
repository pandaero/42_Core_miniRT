/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:51:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/18 14:47:39 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises an intersection.
t_intersect	*intersect_create(void)
{
	t_intersect	*new;

	new = (t_intersect *)malloc(sizeof(t_intersect));
	new->state = 0;
	new->colour = 0;
	new->distance = 0;
	new->point = NULL;
	return (new);
}

//Function copies an intersection.
t_intersect	*intersect_copy(t_intersect *intersect)
{
	t_intersect	*new;

	new = intersect_create();
	new->state = intersect->state;
	new->colour = intersect->colour;
	new->distance = intersect->distance;
	new->point = point_copy(intersect->point);
	return (new);
}

//Function creates an intersection from colour, state, ditance, and a point.
t_intersect	*intersection_input(t_colour colour, int state, double dist, \
								t_point *point)
{
	t_intersect	*intersection;

	intersection = intersect_create();
	intersection->state = state;
	intersection->colour = colour;
	intersection->distance = dist;
	intersection->point = point_copy(point);
	return (intersection);
}
