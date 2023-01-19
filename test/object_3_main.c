//Tests for the functions in object_3

#include "test.h"
#include <stdlib.h>
#include <stdio.h>

//Test for object_ambient_line
//From root: cc -Wall -Werror -Wextra test/test.c test/object_3_main.c src/object/* src/elements/* src/memory/* src/calculation/* src/program/* src/input/* libft/libft.a -lm
/*
int	main(void)
{
	char	*line = ft_strdup("A 0.34  23,255,233");
	t_obj	*obj_amb = object_ambient_line(line);

	printf("In:%s\n", line);
	object_print(obj_amb);
	free_object(obj_amb);
	free(line);
	return (0);
}
//*/

//Test for object_camera_line
//From root: cc -Wall -Werror -Wextra test/test.c test/object_3_main.c src/object/* src/elements/* src/memory/* src/calculation/* src/program/* src/input/* libft/libft.a -lm
/*
int	main(void)
{
	char	*line = ft_strdup("C 1,2.4,-5  0,-1,3  12.34");
	t_obj	*obj_cam = object_camera_line(line);

	printf("In:%s\n", line);
	object_print(obj_cam);
	free_object(obj_cam);
	free(line);
	return (0);
}
//*/

//Test for object_light_line
//From root: cc -Wall -Werror -Wextra test/test.c test/object_3_main.c src/object/* src/elements/* src/memory/* src/calculation/* src/program/* src/input/* libft/libft.a -lm
//*
int	main(void)
{
	char	*line = ft_strdup("L -12,0.45,50  0.45");
	t_obj	*obj_light = object_light_line(line);

	printf("In:%s\n", line);
	object_print(obj_light);
	free_object(obj_light);
	free(line);
	return (0);
}
//*/
