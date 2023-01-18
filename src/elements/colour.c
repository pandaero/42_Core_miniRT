/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:41:50 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/17 14:36:31 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function adds ambient light to a colour.
t_colour	colour_ambient(t_colour colour, t_ambient *ambient)
{
	t_colour	resulting;

	resulting = colour + (int)(ambient->ratio * ambient->colour);
	if (resulting > WHITE)
		resulting = WHITE;
	if (resulting < BLACK)
		resulting = BLACK;
	return (resulting);
}
