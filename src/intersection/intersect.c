/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 18:51:09 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/18 14:18:50 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Allocates memory and places argument values in the intersection structure
t_intersect	*intersection_data\
(t_colour color_in, int state, \
double dist_in, t_point *point_in)
{
	t_intersect	*intersection;

	intersection = intersect_create();
	intersection->colour = color_in;
	intersection->distance = dist_in;
	intersection->point = point_in;
	intersection->state = state;
}

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
