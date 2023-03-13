/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   screen_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 00:11:29 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/14 00:05:48 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function defines a screen based on a camera element.
t_screen	screen_camera(int width, int height, t_camera camera)
{
	t_screen	new;

	new.width = width;
	new.height = height;
	screen_pixel_centres(width, height, camera, &new);
	return (new);
}

//Function locates the screen from the program structure.
t_screen	*screen_program(t_program *program)
{
	t_obj		*curr;

	curr = program->objlist->first;
	while (curr)
	{
		if (curr->elem == SCREEN)
			return (&curr->screen);
		curr = curr->next;
	}
	return (NULL);
}
