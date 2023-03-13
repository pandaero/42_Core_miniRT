/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:51:50 by pbiederm          #+#    #+#             */
/*   Updated: 2023/03/12 00:21:04 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function frees a secondary intersection.
void	free_sec_intersection(t_sec_itsct *sec)
{
	free_intersection(sec->parent);
	free_colour(sec->shadow);
	free(sec);
}

//Function frees a colour.
void	free_colour(t_colour *colour)
{
	free(colour);
}

//Function frees the intermediate results of the ray-cylinder intersect calc.
void	free_ic(t_itsct_cyl *ic)
{
//    if(ic->itsct)
//        free_intersection(ic->itsct);
    if(ic->itsct_shaft)
        free_intersection(ic->itsct_shaft);
    if(ic->itsct_disc_top)
        free_intersection(ic->itsct_disc_top);
    if(ic->itsct_disc_base)
        free_intersection(ic->itsct_disc_base);
    if(ic->ray_orig_trans)
        free_point(ic->ray_orig_trans);
    if(ic->vec_ray)
        free_vector(ic->vec_ray);
    if(ic->vec_orig_trans)
        free_vector(ic->vec_orig_trans);
    if(ic->vec_cyl_axis)
        free_vector(ic->vec_cyl_axis);
    if(ic->vec_itsct)
        free_vector(ic->vec_itsct);
    if(ic->vec_cyl_to_pt)
        free_vector(ic->vec_cyl_to_pt);
    if(ic->proj_centre)
        free_vector(ic->proj_centre);
    if(ic->proj_cent)
        free_point(ic->proj_cent);
    if(ic->temp)
        free_direction(ic->temp);
	// (void) ic;
//	if (ic->proj_cent)
//		free_point(ic->proj_cent);
//	if (ic->proj_centre)
//		free_vector(ic->proj_centre);
//	if (ic->ray_orig_trans)
//		free_point(ic->ray_orig_trans);
//	if (ic->vec_ray)
//		free_vector(ic->vec_ray);
//	if (ic->vec_orig_trans)
//		free_vector(ic->vec_orig_trans);
//	if (ic->vec_cyl_axis)
//		free_vector(ic->vec_cyl_axis);
//	if (ic->vec_cyl_to_pt)
//		free_vector(ic->vec_cyl_to_pt);
//	if (ic->vec_itsct)
//		free_vector(ic->vec_itsct);
}

//Function frees the intermediate results of the ray-sphere intersect calc.
void	free_is(t_itsct_sphere *is)
{
	// (void) is;
	if (is->ray_to_ctr)
		free_vector(is->ray_to_ctr);
	if (is->vec_ray_dir)
		free_vector(is->vec_ray_dir);
}
