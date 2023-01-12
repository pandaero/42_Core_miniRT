/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_cylinder.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:40:09 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/12 19:34:32 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./exercises.h"

/*
Now let's talk about the intersection of a ray and a cylinder.

A cylinder can be defined by it's center point C, 
it's axis direction vector A, and it's radius r.
Like with the previous example, let's consider the same starting point and direction vector 
for the ray, R = (1, 2, 3) and D = (4, 5, 6).

Here's the basic algorithm for determining if the ray intersects the cylinder:

Translate the cylinder and ray so that the cylinder's center is at the origin. 
This is done by subtracting the center coordinates of the cylinder from the starting 
point of the ray and from the cylinder's axis point. 
R' = (x1 - x2, y1 - y2, z1 - z2) 
C' = (0, 0, 0) 
A' = (ax-x2, ay-y2, az-z2) 
Compute the projection of R' onto A': 
t = (R' . A') / (A' . A') 
Compute the vector from the projected point to the point on the ray: 
Q = R' - t*A' Check if Q is within the radius of the cylinder: 
If (Q . Q) <= r^2, then the ray intersects the cylinder 
Here's an example with numbers: 
Let R = (1, 2, 3), D = (4, 5, 6), 
C = (10, 20, 30), A = (40,50,60) and r = 5.

Translate the cylinder and ray so that the cylinder's center is at the origin: 
R' = (1 - 10, 2 - 20, 3 - 30) = (-9, -18, -27)

cc ray_cylinder.c operations.c input.c -lm
*/