/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder_alternative.c                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:40:09 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/14 16:11:38 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


/*NOT SURE IF WORKS, NEED RENDERING TO TUNE IT
Cylinder
The infinite unit cylinder aligned along the z-axis is defined as:

 
x2+y2=1	(36)

In cylindrical polar coordinates it is just:
r=1	(37)

To intersect a ray with this, substitute Equation 24 in Equation 36.
 
 	 	(xE+txD)2+(yE+tyD)2=1	(38)
$\displaystyle \Rightarrow$	 	t2(xD2+yD2)+t(2xExD+2yEyD)	 
 	 	+(xE2+yE2-1)=0	(39)
$\displaystyle \Rightarrow$	 	at2+bt+c=0	(40)
$\displaystyle \Rightarrow$	 	$\displaystyle t=\frac{-b\pm\sqrt{b^2-4ac}}{2a}$	(41)

where a=xD2+yD2, b=2xExD+2yEyD, and c=xE2+yE2-1.
The finite open-ended unit cylinder aligned along the z-axis is defined as:

\begin{displaymath}x^2+y^2=1, z_{\min} < z < z_{\max}
\end{displaymath}	(42)

The only difference between this and Equation 36 being the restriction on z. In cylindrical polar coordinates this is obviously:
\begin{displaymath}r=1, z_{\min} < z < z_{\max}
\end{displaymath}	(43)

To handle this finite length cylinder, solve Equation 41 above. This gives, at most, two values of t. Call these t1 and t2. Calculate z1 and z2using Equation 24 ( z1 = zE + t1zD and z2 = zE + t2zD) and then check $z_{\min} < z_1 < z_{\max}$ and $z_{\min} < z_2 <
z_{\max}$. Whichever intersection point passes this test and, if both pass the test, has the smallest non-negative value of t, is the closest intersection point of the ray with the open-ended finite cylinder.
If we wish the finite length cylinder to be closed we must formulate an intersection calculation between the ray and the cylinder's end caps. The end caps have the formulae:
$\displaystyle z = z_{\min},$	 	$\displaystyle x^2+y^2 \leq 1$	(44)
$\displaystyle z = z_{\max},$	 	$\displaystyle x^2+y^2 \leq 1$	(45)

Once you have calculated the solutions to Equation 41 you will either know that there are no intersections with the infinite cylinder or you will know that there are one or two real intersection points (t1 and t2). The previous paragraph explained how to ascertain whether these correspond to points on the finite length open-ended cylinder. Now, if z1 and z2 lie either side of $z_{\min}$ we know that the ray intersects the $z_{\min}$ end cap, and can calculate the intersection point as:
\begin{displaymath}t_3=\frac{z_{\min}-z_E}{z_D}
\end{displaymath}	(46)

A similar equation holds for the $z_{\max}$ end cap. Note that the ray may intersect both end caps, for example when $z_1 < z_{\min}$ and $z_2 > z_{\max}$.
*/

#include "./intersections.h"

#define RAY_START_X 100
#define RAY_START_Y 100
#define RAY_START_Z 100
#define RAY_INPUT_DIRECTION_X 0
#define RAY_INPUT_DIRECTION_Y 0
#define RAY_INPUT_DIRECTION_Z 1
#define CYLINDER_CENTER_X 0
#define CYLINDER_CENTER_Y 0
#define CYLINDER_CENTER_Z 0
#define CYLINDER_INPUT_DIRECTION_X 0
#define CYLINDER_INPUT_DIRECTION_Y 0
#define CYLINDER_INPUT_DIRECTION_Z 1
#define CYLINDER_BASE_RADIUS 1

void	ray_cylinder_intersection()
{
	t_point	*ray_start;
	t_point	*ray_direction_input;
	t_point	*ray_direction;
	t_point	*cylinder_center;
	t_point	*cylinder_direction_input;
	// t_point	*cylinder_direction;
	double	a;
	double	b;
	double	c;

	ray_start = malloc(sizeof(t_point));
	ray_direction_input = malloc(sizeof(t_point));
	cylinder_center = malloc(sizeof(t_point));
	cylinder_direction_input = malloc(sizeof(t_point));
	populate_point(ray_start, RAY_START_X, RAY_START_Y, RAY_START_Z);
	populate_point(ray_direction_input, RAY_INPUT_DIRECTION_X, RAY_INPUT_DIRECTION_Y, RAY_INPUT_DIRECTION_Z);
	populate_point(cylinder_center, CYLINDER_CENTER_X, CYLINDER_CENTER_Y, CYLINDER_CENTER_Z);
	populate_point(cylinder_direction_input, CYLINDER_INPUT_DIRECTION_X, CYLINDER_INPUT_DIRECTION_Y, CYLINDER_INPUT_DIRECTION_Z);
	ray_direction = direction_two_points_local(ray_start, ray_direction_input);
	// cylinder_direction = direction_two_points_local(cylinder_center, cylinder_direction_input);
	a = pow(ray_direction->x, 2) + pow(ray_direction->y, 2);
	b = 2 * ray_start->x * ray_direction->x + 2 * ray_start->y * ray_direction->y;
	c = pow(ray_start->x, 2) + pow(ray_start->y, 2) - 1;
	solveQuadratic(a, b, c);
	free(ray_start);
	free(ray_direction_input);
	free(cylinder_center);
	free(cylinder_direction_input);
	free(ray_direction);
	// free(cylinder_direction);
	
}

int main(void)
{
	ray_cylinder_intersection();
	return(0);
}
