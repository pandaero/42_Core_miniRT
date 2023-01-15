/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_5.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 16:14:07 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/15 16:16:39 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/minirt.h"
#include <stdlib.h>

//Function frees a cylinder.
void	free_cylinder(t_cylinder *cylinder)
{
	free_point(cylinder->centre);
	free_direction(cylinder->orientation);
	free(cylinder);
}
