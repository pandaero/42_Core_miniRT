/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_6.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 18:03:35 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/19 18:04:49 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function frees a 2D char array made from ft_split. Returns zero.
int	free_split_ret_int_zero(char **charr)
{
	free_split(charr);
	return (0);
}
