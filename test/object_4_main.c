//Tests for the functions in object_4

#include "test.h"
#include <stdlib.h>
#include <stdio.h>

//Test for object_plane_line
//From root: cc -Wall -Werror -Wextra test/test.c test/object_4_main.c src/object/* src/elements/* src/memory/* src/calculation/* src/program/* src/input/* libft/libft.a -lm
/*
int	main(void)
{
	char	*line = ft_strdup("pl  0,0,0   0,1.0,0 255,0,225");
	t_obj	*obj_plane = object_plane_line(line);

	printf("In:%s\n", line);
	object_print(obj_plane);
	free_object(obj_plane);
	free(line);
	return (0);
}
//*/

//Test for object_sphere_line
//From root: cc -Wall -Werror -Wextra test/test.c test/object_4_main.c src/object/* src/elements/* src/memory/* src/calculation/* src/program/* src/input/* libft/libft.a -lm
/*
int	main(void)
{
	char	*line = ft_strdup("sp 0,0,20 20 10,0,200");
	t_obj	*obj_sph = object_sphere_line(line);

	printf("In:%s\n", line);
	object_print(obj_sph);
	free_object(obj_sph);
	free(line);
	return (0);
}
//*/

//Test for object_cylinder_line
//From root: cc -Wall -Werror -Wextra test/test.c test/object_4_main.c src/object/* src/elements/* src/memory/* src/calculation/* src/program/* src/input/* libft/libft.a -lm
/*
int	main(void)
{
	char	*line = ft_strdup("cy 50.0,0.0,20.6 0,0,1.0 14.2 21.42 10,0,255");
	t_obj	*obj_cyl = object_cylinder_line(line);

	printf("In:%s\n", line);
	object_print(obj_cyl);
	free_object(obj_cyl);
	free(line);
	return (0);
}
//*/
