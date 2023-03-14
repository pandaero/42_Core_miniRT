//Tests for intersect_cylinder.c
#include "test.h"
#include <stdio.h>

// Compilation command
// cc -Wall -Werror -Wextra test/intersect_cylinder_main.c src/calculation/* src/intersection/* src/elements/* src/memory/* src/input/* src/object/* src/error/* src/program/parsing.c libft/libft.a

int	main()
{
	t_point		*orig = point_coords(10,10,0);
	t_direction	*into_y = direction_components(-1, 0, 0);
	t_ray		*ray = ray_start_dir(orig, into_y);
	
	t_cylinder	*cyl = cylinder_line("cy 0,10,0 0,0,1 10 10 255,0,0");

	t_intersect	*itsct = intersection_ray_cylinder(ray, cyl);	
	
	printf("Ray     : start  (%f, %f, %f), dir (%f, %f, %f)\n", ray->ray_orig->x_co, ray->ray_orig->y_co, ray->ray_orig->z_co, into_y->x_comp, into_y->y_comp, into_y->z_comp);
	printf("Cylinder: centre (%f, %f, %f), orientation (%f, %f, %f), radius %f, height %f\n", cyl->centre->x_co, cyl->centre->y_co, cyl->centre->z_co, cyl->orientation->x_comp, cyl->orientation->y_comp, cyl->orientation->z_comp, cyl->radius, cyl->height);

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
	// if (itsct->state != MISSED)
	// {
		printf("point (%f, %f, %f), distance %f\n", itsct->point->x_co, itsct->point->y_co, itsct->point->z_co, itsct->distance);
		printf("normal: (%f, %f, %f)\n", itsct->normal->x_comp, itsct->normal->y_comp, itsct->normal->z_comp);
	// }

	return (0);
}
