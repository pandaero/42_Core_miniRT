/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_3.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:17:23 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/15 16:20:47 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"

//Function creates a cylinder object.
t_obj	*object_cylinder(t_cylinder *cylinder)
{
	t_obj	*new;

	new = object_create();
	new->elem = CYLINDER;
	new->cylinder = cylinder;
	return (new);
}
