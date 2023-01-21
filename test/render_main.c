//Tests for functions in render.c

#include "test.h"
#include <stdlib.h>

//Test for render_screen
//For root - linux:
//*
int	main(void)
{
	char		*filename = ft_strdup("test/test_input_one_plane.rt");
	t_program	*program = program_create();

	fill_objects_file(program, filename);
	render_screen(program);
	list_print(program->objlist);

	free(filename);
	return (0);
}
//*/
