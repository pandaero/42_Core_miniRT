//Tests for the functions in file.c

#include "test.h"
#include <stdlib.h>

//Test for has_extension
//From root: cc -Wall -Werror -Wextra test/file_main.c src/input/file.c libft/libft.a
int	main(void)
{
	char	*filename1 = ft_strdup("hello.rt");
	char	*filename2 = ft_strdup("hello.rtx");
	char	*filename3 = ft_strdup("hello.r");
	char	*filename4 = ft_strdup("hello");
	char	*ext = ft_strdup("rt");

	ft_printf("file:%s, ext:%s - %d\n", filename1, ext, has_extension(filename1, ext));
	ft_printf("file:%s, ext:%s - %d\n", filename2, ext, has_extension(filename2, ext));
	ft_printf("file:%s, ext:%s - %d\n", filename3, ext, has_extension(filename3, ext));
	ft_printf("file:%s, ext:%s - %d\n", filename4, ext, has_extension(filename4, ext));
	free(ext);
	free(filename1);
	free(filename2);
	free(filename3);
	free(filename4);
	return (0);
}
