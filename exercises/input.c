/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 17:40:24 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/12 19:30:48 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./exercises.h"

void populate_point(t_point *to_fill, double x, double y, double z)
{
	to_fill->x = x;
	to_fill->y = y;
	to_fill->z = z;
}
