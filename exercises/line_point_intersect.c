#include <stdio.h>
#include <stdlib.h>


#define a 2
#define coordinate_x 1
#define coordinate_y 2
/*Checks if the given point x1 and y2 intersects with the function a*x = y
Simple introduction to the concept of intersection. This implementation would be too resource heavy.*/
int	main(void)
{
	int		x1;
	int		y2;
	int		x, y;

	x1 = coordinate_x;
	y2 = coordinate_y;
	x = 0;
	while (x < 10)
	{
		if (x1 * a == y2)
		{
			printf("It intesects\n");
			return(0);
		}
		x++;
	}
	printf("It does not intersect\n");
	return (0);
}
