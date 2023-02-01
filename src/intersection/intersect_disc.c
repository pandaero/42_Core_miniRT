/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_disc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:31:13 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/01 12:33:48 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
//For tests
#include <stdio.h>

//Returns intersection of ray and disc
// t_intersect	*intersection_ray_disc(t_ray *ray, t_disc *disc)
// {
// 	t_intersect	*intersect_plane;
// 	t_intersect	*intersect_disc;
// 	t_vector	*disc_center_to_point_plane;
// 	double		distance_center_point2;
	
// 	intersect_plane = intersection_ray_plane(ray, disc->plane);
// 	intersect_disc = (t_intersect *)malloc(sizeof(t_intersect));
// 	if (intersect_plane->state > 0)
// 	{
// 		disc_center_to_point_plane = vector_two_points(disc->center, intersect_plane->point);
// 		distance_center_point2 = vector_dot(disc_center_to_point_plane, disc_center_to_point_plane);
// 		double radius2 = disc->radius * disc->radius;
// 		if (distance_center_point2 <= radius2)
// 		{
// 			intersect_disc->state = 2;
// 			intersect_disc->point = (t_point *)malloc(sizeof(t_point));
// 			intersect_disc->point = intersect_plane->point;
// 			intersect_disc->distance = intersect_plane->distance;
// 		}
// 		else
// 		{
// 			intersect_disc->state = 0;
// 		}
// 		free(intersect_plane->point);
// 		free(intersect_plane);
// 	}
// 	else
// 	{
// 		intersect_disc->state = 0;
// 		free(intersect_plane->point);
// 		free(intersect_plane);
// 	}
// 	return(intersect_disc);
// }
