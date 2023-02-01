/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pbiederm <pbiederm@student.42wolfsburg.de> +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 13:47:01 by pbiederm          #+#    #+#             */
/*   Updated: 2023/01/28 12:09:51 by pbiederm         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdio.h>

void print_vector(char *name, t_vector *to_print)
{
	printf("%s: ", name);
	printf("[%f, %f, %f]\n", to_print->x_comp, to_print->y_comp, to_print->z_comp);
}

void print_point(char *name, t_point *to_print)
{
	printf("%s: ", name);
	printf("[%f, %f, %f]\n", to_print->x_co, to_print->y_co, to_print->z_co);
}

void print_direction(char *name, t_direction *to_print)
{
	printf("%s: ", name);
	printf("[%f, %f, %f]\n", to_print->x_comp, to_print->y_comp, to_print->z_comp);
}