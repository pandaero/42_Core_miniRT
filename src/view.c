/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   view.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 22:36:44 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/13 02:56:17 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <math.h>
#include <stdlib.h>

//Function creates and initialises a camera.
t_camera *camera_create(void)
{
	t_camera	*new;

	new = (t_camera *)malloc(sizeof(t_camera));
	new->horiz_fov = 0;
	new->location = NULL;
	new->view_dir = NULL;
	return (new);
}
