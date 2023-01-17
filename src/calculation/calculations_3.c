/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculations_3.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 22:48:19 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/17 14:36:19 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function works out the dot product of two vectors.
double	vector_dot(t_vector *first, t_vector *second)
{
	return (first->x_comp * second->x_comp + \
			first->y_comp * second->y_comp + \
			first->z_comp * second->z_comp);
}
