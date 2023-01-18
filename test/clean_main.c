//Tests for the functions in clean.c

#include "test.h"
#include <stdlib.h>

//Test for skip_spacing
//From root: cc -Wall -Werror -Wextra test/clean_main.c src/input/clean.c src/input/valid.c libft/libft.a
/*
int	main(void)
{
	char	*str1 = ft_strdup("   hello");
	char	*str2 = ft_strdup(" hello");
	char	*str3 = ft_strdup("hello");
	int		i1 = skip_spacing(str1);
	int		i2 = skip_spacing(str2);
	int		i3 = skip_spacing(str3);

	ft_printf("str:%s, i:%d, str[i]:%c\n", str1, i1, str1[i1]);
	ft_printf("str:%s, i:%d, str[i]:%c\n", str2, i2, str2[i2]);
	ft_printf("str:%s, i:%d, str[i]:%c\n", str3, i3, str3[i3]);
	free(str1);
	free(str2);
	free(str3);
	return (0);
}
//*/

//Test for replace_spacing
//From root: cc -Wall -Werror -Wextra test/clean_main.c src/input/clean.c src/input/valid.c libft/libft.a
//*
int	main(void)
{
	char	*str = ft_strdup("  A\t\tB\n");
	char	*out = replace_spacing(str);

	ft_printf("In :%s\nOut:%s\n", str, out);
	free(str);
	free(out);
	return (0);
}
//*/
