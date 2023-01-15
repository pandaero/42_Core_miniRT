/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:40:24 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/15 15:26:26 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./intersections.h"

void	populate_point(t_Vector3 *to_fill, double x, double y, double z)
{
	to_fill->x = x;
	to_fill->y = y;
	to_fill->z = z;
}
