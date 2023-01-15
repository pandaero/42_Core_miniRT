//This code demonstrates a normal 2D array and a pointer-element 2D array.
//From root: cc -Wall -Werror -Wextra exercises/2d_array.c

#include <stdio.h>
#include <stdlib.h>

typedef	struct s_data
{
	int first;
	int	second;
}		t_data;

int	main(void)
{
	t_data	***arr_p;
	int		**arr_i;
	int		rows;
	int		cols;
	int		i;
	int		j;

	rows = 5;
	cols = 3;

	// Make the integer 2D array
	i = 0;
	arr_i = (int **)malloc((rows + 1) * sizeof(int *));
	while (i < rows)
	{
		arr_i[i] = (int *)malloc((cols + 1) * sizeof(int));
		j = 0;
		while(j < cols)
		{
			arr_i[i][j] = i * j;
			j++;
		}
		arr_i[i][j] = -1;
		i++;
	}
	arr_i[i] = NULL;

	// Print the integer 2D array
	printf("Integer 2D Array:\n");
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j <= cols)
		{
			printf("[%d,%d] - ", i, j);
			printf("%d ", arr_i[i][j]);
			j++;
		}
		printf("| Row: %p", arr_i[i]);
		printf("\n");
		i++;
	}
	printf("Final Row: %p\n", arr_i[i]);

	// Make the point 2D array
	arr_p = (t_data ***)malloc((rows + 1) * sizeof(t_data **));
	i = 0;
	while (i < rows)
	{
		j = 0;
		arr_p[i] = (t_data **)malloc((cols + 1) * sizeof(t_data *));
		while (j < cols)
		{
			arr_p[i][j] = (t_data *)malloc(sizeof(t_data));
			arr_p[i][j]->first = i;
			arr_p[i][j]->second = j;
			j++;
		}
		arr_p[i][j] = NULL;
		i++;
	}
	arr_p[i] = NULL;

	// Print the point 2D array
	printf("\nPoint 2D Array:\n");
	i = 0;
	while (i < rows)
	{
		j = 0;
		while (j <= cols)
		{
			printf("[%d,%d] - ", i, j);
			if (j == cols)
				printf("%p ", arr_p[i][j]);
			else
				printf("(%d,%d) ", arr_p[i][j]->first, arr_p[i][j]->second);
			j++;
		}
		printf("| Row: %p", arr_p[i]);
		printf("\n");
		i++;
	}
	printf("Final Row: %p\n", arr_i[i]);
	return (0);
}
