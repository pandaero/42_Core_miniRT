//Tests for intersect_sphere.c
#include "test.h"
#include <stdio.h>

// Compilation command
// cc -Wall -Werror -Wextra test/intersect_sphere_main.c src/calculation/* src/intersection/* src/elements/* src/memory/* src/input/* src/object/* src/error/* src/program/parsing.c libft/libft.a

int	main()
{
	t_point		*orig = point_coords(0,11,0);
	t_direction	*into_y = direction_components(-1, 1, 0);
	t_ray		*ray = ray_start_dir(orig, into_y);
	
	t_point		*sph_ctr = point_coords(0,10,0);
	t_colour	*sph_col = colour_str("255,0,0");
	t_sphere	*sphere = sphere_col_centre_radius(sph_col, sph_ctr, 5);

	t_intersect	*itsct = intersection_ray_sphere(ray, sphere);	
	
	printf("Ray   : start  (%f, %f, %f), dir (%f, %f, %f)\n", ray->ray_orig->x_co, ray->ray_orig->y_co, ray->ray_orig->z_co, into_y->x_comp, into_y->y_comp, into_y->z_comp);
	printf("Sphere: centre (%f, %f, %f), radius %f\n", sph_ctr->x_co, sph_ctr->y_co, sph_ctr->z_co, sphere->radius);

	char	*str;

	switch (itsct->state)
	{
		case MISSED:
			str = ft_strdup("MISSED");
			break;
		case INTERSECTED:
			str = ft_strdup("INTERSECTED");
			break;
		default:
			str = ft_strdup("UNKNOWN");
			break;
	}
	printf("\nIntersection: state %s\n", str);
	if (itsct->state != MISSED)
	{
		printf("point (%f, %f, %f), distance %f, normal: (%f, %f, %f)\n", itsct->point->x_co, itsct->point->y_co, itsct->point->z_co, itsct->distance, itsct->normal->x_comp, itsct->normal->y_comp, itsct->normal->z_comp);
	}

	return (0);
}
