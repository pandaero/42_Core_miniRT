/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colour.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:41:50 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/15 16:55:25 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

//Function adds ambient light to a colour.
t_colour	colour_ambient(t_colour colour, t_ambient ambient)
{
	t_colour	resulting;

	if (colour > (int) 0.5 * ambient->colour)
		resulting = colour + (int) ambient->ratio * ambient->colour;
	else if (colour < (int) 0.5 * ambient->colour)
		resulting = colour - (int) ambient->ratio * ambient->colour;
	else
		resulting = colour;
	if (resulting > 0x00FFFFFF)
		resulting = 0x00FFFFFF;
	if (resulting < 0x00000000)
		resulting = 0x00000000;
	return (resulting);
}
