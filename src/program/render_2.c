/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/08 16:52:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 23:14:10 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

// //Function gives colour to a pixel.
// void	pixel_colouring(t_program *program, t_pixel *pixel)
// {
// 	if (pixel->sec_itsct.state == INTERSECTED)
// 		pixel->colour = colour_subtract(pixel->itsct.colour, \
// 													pixel->sec_itsct.shadow);
// 	else
// 	{
// 		if (pixel->itsct.state == INTERSECTED)
// 			pixel->colour = colour_copy(pixel->itsct.colour);
// 		else
// 			pixel->colour = colour_ambient_list(program->objlist);
// 	}
// }

