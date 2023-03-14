//Tests for intersect_plane.c
#include "test.h"
#include <stdio.h>

// Compilation command
// cc -Wall -Werror -Wextra test/intersect_plane_main.c src/calculation/* src/intersection/* src/elements/* src/memory/* src/input/* src/object/* src/error/* src/program/parsing.c libft/libft.a -lm

int	main()
{
	t_point		orig = point_coords(0,0,0);
	t_direction	dir = direction_components(1, 5, 0);
	t_ray		ray = ray_start_dir(orig, dir);
	
	t_point		point = point_coords(0,10,0);
	t_direction	normal = direction_components(0, 1, 0);
	t_colour	colour = colour_str("255,0,0");
	t_plane		plane = plane_col_point_normal_dir(colour, point, normal);

	t_intersect	itsct = intersection_ray_plane(ray, plane);
	
	printf("Ray  : start (%f, %f, %f), dir (%f, %f, %f)\n", ray.ray_orig.x_co, ray.ray_orig.y_co, ray.ray_orig.z_co, ray.ray_dir.x_comp, ray.ray_dir.y_comp, ray.ray_dir.z_comp);
	printf("Plane: point (%f, %f, %f), dir (%f, %f, %f)\n", plane.point.x_co, plane.point.y_co, plane.point.z_co, plane.normal.x_comp, plane.normal.y_comp, plane.normal.z_comp);

	char	*str;

	switch (itsct.state)
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
	if (itsct.state != MISSED)
	{
		printf("point (%f, %f, %f), distance %f, normal: (%f, %f, %f)\n", itsct.point.x_co, itsct.point.y_co, itsct.point.z_co, itsct.distance, itsct.normal.x_comp, itsct.normal.y_comp, itsct.normal.z_comp);
	}

	return (0);
}
