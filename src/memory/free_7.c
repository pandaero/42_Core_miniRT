/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_7.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/12 14:51:50 by pbiederm          #+#    #+#             */
/*   Updated: 2023/02/21 16:58:20 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function frees a secondary intersection.
void	free_sec_intersection(t_sec_itsct *sec)
{
	free_intersection(sec->parent);
	free_colour(sec->shadow);
	free(sec);
}

//Function frees a colour.
void	free_colour(t_colour *colour)
{
	free(colour);
}
