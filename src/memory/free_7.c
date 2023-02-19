/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:51:50 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/19 16:00:06 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function frees a plane and a cylinder cap struct.
void	free_cylinder_plane(t_cylinder_cap *t)
{
	free_plane(t->cap_plane);
	free(t);
}

//Function frees objects related to a cylinder cap.
void	free_cylinder_cap(t_cylinder_cap *t)
{
	free_vector(t->disc_center_to_point_plane);
	free_plane(t->cap_plane);
	free(t);
}

//Function frees a secondary intersection.
void	free_sec_intersection(t_sec_itsct *sec)
{
	free_intersection(sec->parent);
	free_colour(sec->shadow);
}

//Function frees a colour.
void	free_colour(t_colour *colour)
{
	free(colour);
}
