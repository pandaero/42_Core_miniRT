//Tests for the functions in file.c

#include "test.h"
#include <stdlib.h>
#include <stdio.h>

//Test for has_extension
//From root: cc -Wall -Werror -Wextra test/file_main.c src/input/file.c libft/libft.a
/*
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
//*/

//Test for has_valid_contents
//From root: cc -Wall -Werror -Wextra test/file_main.c src/input/* libft/libft.a
/*
int	main(void)
{
	char	*filename1 = ft_strdup("test/test_contents_valid");
	char	*filename2 = ft_strdup("test/test_contents_invalid");
	int		ret1 = has_valid_contents(filename1);
	int		ret2 = has_valid_contents(filename2);
	
	printf("File:%s - Valid:%d\n", filename1, ret1);
	printf("File:%s - Valid:%d\n", filename2, ret2);
	free(filename1);
	free(filename2);
	return (0);
}
//*/

//Test for has_valid_formatting
//From root: cc -Wall -Werror -Wextra test/file_main.c src/input/* src/calculation/* src/memory/* src/elements/* libft/libft.a -lm
/*
int	main(void)
{
	char	*filename1 = ft_strdup("test/test_input_valid.rt");
	char	*filename2 = ft_strdup("test/test_input_invalid.rt");
	int		ret1 = has_valid_formatting(filename1);
	int		ret2 = has_valid_formatting(filename2);

	printf("File:%s - Valid_format:%d\n", filename1, ret1);
	printf("File:%s - Valid_format:%d\n", filename2, ret2);
	free(filename1);
	free(filename2);
	return (0);
}
//*/
