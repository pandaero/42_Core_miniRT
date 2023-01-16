/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   light.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 23:22:21 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/15 23:29:38 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdlib.h>

//Function creates and initialises an ambient light.
t_ambient	*ambient_create(void)
{
	t_ambient	*new;

	new = (t_ambient *)malloc(sizeof(t_ambient));
	new->ratio = 0;
	new->colour = 0;
	return (new);
}

//Function creates an ambient light according to colour and ratio.
t_ambient	*ambient_input(t_colour colour, double ratio)
{
	t_ambient	*ambient;

	ambient = ambient_create();
	ambient->ratio = ratio;
	ambient->colour = colour;
	return (ambient);
}
