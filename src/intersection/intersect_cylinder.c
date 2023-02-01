/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intersect_cylinder.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:25:29 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/01 15:24:20 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <math.h>

//for tests
#include <stdio.h>
#include <stdlib.h>

#define HAS_TWO_RESULTS 1
#define HAS_ONE_OR_INFINITE_RESULT 2
/*Cylinder

Definition:
 C is the start cap point of the cylinder
 V is a unit length vector that determines cylinder's axis
 r is the cylinder's radius
 maxm determines cylinder's end cap point

To hit a cylinder we notice that:

   A = C + V*m
   ( P-A )|V = 0
   len( P-A ) = r
where m is a scalar that determines the closest point on the axis to the hit point. The P-A vector is perpendicular to V, what guarantees the closest distance to the axis. P-A is the cylinder's radius.
Solution:

   (P-C-V*m)|V = 0
   (P-C)|V = m*(V|V) = m   (len(V)=1)
   m = (D*t+X)|V
   m = D|V*t + X|V

   len(P-C-V*m) = r
   dot( D*t+X - V*(D|V*t + X|V) ) = r^2
   dot( (D-V*(D|V))*t + (X-V*(X|V)) ) = r^2
      dot( A-V*(A|V) ) = A|A - 2*(A|V)^2 + V|V * (A|V)^2 =
       = A|A - (A|V)^2
   a*t^2 + b*t + c = 0
   a = D|D - (D|V)^2
   c = X|X - (X|V)^2 - r^2
   b = 2 * (D-V*(D|V))|(X-V*(X|V)) =
     = 2 * (D|X - D|V*(X|V) - X|V*(D|V) + (D|V)*(X|V)) =
     = 2 * (D|X - (D|V)*(X|V))
Finally:
   a   = D|D - (D|V)^2
   b/2 = D|X - (D|V)*(X|V)
   c   = X|X - (X|V)^2 - r*r
Surface normal is:

   m = D|V*t + X|V
   N = nrm( P-C-V*m )
There are two points on the cylinder that we hit (it can be the same point twice). We have to calculate two m values and test whether they fall in the range of [0,maxm]. If any falls out, we can either throw the point that corresponds to it away (the cylinder will have a hole) or we can cap the cylinder with planes. One of the planes is defined by a pair (C,-V) and the other by (C+V*maxm,V). We hit the planes like a typical plane; the dot products we have already calculated, we only need to do the division(s).
*/

// static t_disc	*summon_cylinder_caps(t_cylinder *cylinder, t_point *center_of_disc)
// {
// 	//Plane of disc
// 	// print_point("center of disc: ", center_of_disc);
// 	// print_direction("direction: ", cylinder->orientation);
// 	t_point *point_on_plane = point_coords(center_of_disc->x_co, center_of_disc->y_co, center_of_disc->z_co);
// 	t_direction *plane_norm = direction_copy(cylinder->orientation);
// 	t_plane *plane = plane_col_point_normal_dir(GREEN, point_on_plane, plane_norm);
// 	// Disc
// 	// print_point("center of disc test: ", center_of_disc);
// 	// print_direction("direction: ", cylinder->orientation);
// 	t_point *point_on_disc = point_coords(center_of_disc->x_co, center_of_disc->y_co, center_of_disc->z_co);
// 	t_direction *disc_norm = direction_copy(cylinder->orientation);
// 	t_disc *disc = disc_col_point_normal_dir_plane(0x000055FF, point_on_disc, disc_norm, cylinder->radius, plane);
// 	return(disc);
// }

static t_cylinder_locals	*initialize_variables(t_ray *ray, t_cylinder *cylinder)
{
	t_cylinder_locals	*loc;

	loc = (t_cylinder_locals*)malloc(sizeof(t_cylinder_locals));
	loc->cyl_up = vector_scale_direction(cylinder->height / 2, cylinder->orientation);
	loc->cyl_down = vector_scale_direction((-cylinder->height) / 2, cylinder->orientation);
	loc->C = point_point_vector(cylinder->centre, loc->cyl_up);
	loc->H = point_point_vector(cylinder->centre, loc->cyl_down);
	loc->w = vector_two_points(ray->ray_orig, loc->C);
	loc->ray_dir_vec = vector_scale_direction(1, ray->ray_dir);
	loc->cylinder_orientation_vec = vector_scale_direction(1, cylinder->orientation);
	loc->a = vector_dot(loc->ray_dir_vec, loc->ray_dir_vec) \
	- pow(vector_dot(loc->ray_dir_vec, loc->cylinder_orientation_vec), 2);
	loc->b = 2 * (vector_dot(loc->ray_dir_vec, loc->w) - vector_dot(loc->ray_dir_vec, loc->cylinder_orientation_vec) * vector_dot(loc->w, loc->cylinder_orientation_vec));
	loc->c = vector_dot(loc->w, loc->w) - pow(vector_dot(loc->w, loc->cylinder_orientation_vec), 2) - pow(cylinder->radius, 2);
	return(loc);
}

t_intersect *initialize_intersection()
{
	t_intersect	*intersection;
	
	intersection = (t_intersect*)malloc(sizeof(t_intersect));
	intersection->point = (t_point*)malloc(sizeof(t_point));
	return(intersection);
}

t_intersect	*intersection_ray_cylinder(t_ray *ray, t_cylinder *cylinder)
{
	t_intersect				*intersection;
	t_cylinder_locals		*loc;
	double					*quadratic_result;
	double					distance_from_base;

	intersection = initialize_intersection();
	loc = initialize_variables(ray, cylinder);
	quadratic_result = solve_quadratic_real(loc->a, loc->b, loc->c);
	if(quadratic_result[1] < quadratic_result[2] && quadratic_result[0] == HAS_TWO_RESULTS)
		intersection->point = get_intersection_point(ray, quadratic_result[1]);
	else if(quadratic_result[1] > quadratic_result[2] && quadratic_result[0] == HAS_TWO_RESULTS)
		intersection->point = get_intersection_point(ray, quadratic_result[2]);
	else if (quadratic_result[0] == HAS_ONE_OR_INFINITE_RESULT)
		intersection->point = get_intersection_point(ray, quadratic_result[1]);
	if(quadratic_result[0] == HAS_TWO_RESULTS || quadratic_result[0] == HAS_ONE_OR_INFINITE_RESULT)
	{
		t_vector *intersection_point_base_point = vector_two_points(intersection->point, loc->C);
		distance_from_base = vector_dot(intersection_point_base_point, vector_two_points(loc->C, loc->H));
	}
	else
	{
		intersection->state = 0;
		return (intersection);
	}
	if (distance_from_base >= 0.0 && distance_from_base <= cylinder->height)
	{
		intersection->state = 1;
		return (intersection);
	}
	intersection->state = 0;
	return(intersection);
}
