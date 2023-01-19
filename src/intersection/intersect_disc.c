/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_disc.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 20:31:13 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/19 21:11:06 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//For tests
#include <stdio.h>

void intersect_ray_disc(t_ray *ray, t_disc *disc)
{
	printf("disc center point: [%f, %f, %f]\n", disc->point->x_co, disc->point->y_co, disc->point->z_co);
	printf("disc normal [%f, %f, %f]\n", disc->normal->x_comp, disc->normal->y_comp, disc->normal->z_comp);
	printf("disc radius: %f", disc->radius);
	// t_plane	*plane_of_disc;
	// plane_of_disc = 
	// plane_of_disc->point = 
}