/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   object_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 18:52:47 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/12 18:53:07 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../minirt.h"

//Function creates a direction object.
t_obj	*object_ray(t_ray *ray)
{
	t_obj	*new;

	new = object_create();
	if (!new)
		return (NULL);
	new->elem = RAY;
	new->ray = ray;
	return (new);
}
