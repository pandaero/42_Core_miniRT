//Tests for the functions in file.c

#include "test.h"
#include <stdlib.h>

//Test for fill_objects_file
//From root - linux: cc -Wall -Wextra -Werror test/test.c test/file_main.c src/*/* libft/libft.a minilibx-linux/libmlx.a -lX11 -lXext -lm
/*
int	main(void)
{
	char	*filename = ft_strdup("test/test_input_one_plane.rt");
	t_program	*program = program_create();

	fill_objects_file(program, filename);
	list_print(program->objlist);
	free_program(program);
	free(filename);
}
//*/
