//Tests for functions in list_2.c

#include "test.h"
#include <stdlib.h>

//Test for objlist_count_ambient
//From root - linux: cc -Wall -Werror -Wextra test/list_2_main.c test/test.c src/*/* libft/libft.a minilibx-linux/libmlx.a -lm -lX11 -lXext
//*
int	main(void)
{
	char		*filename = ft_strdup("test/test_input_one_plane.rt");
	t_program	*program = program_create();
	fill_objects_file(program, filename);

	list_print(program->objlist);
	free(filename);
	free_program(program);
	return (0);
}
//*/
