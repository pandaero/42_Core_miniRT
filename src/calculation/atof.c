/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   atof.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 18:52:11 by pandalaf          #+#    #+#             */
/*   Updated: 2023/03/13 15:06:06 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

//Function skips through spacing characters within a string.
static int	skip_spacing_atof(const char *str)
{
	int	i;

	i = 0;
	while (str[i] == ' ' || str[i] == '\t' \
			|| str[i] == '\n' || str[i] == '\v' \
			|| str[i] == '\f' || str[i] == '\r')
		i++;
	return (i);
}

//Function initialises the variables needed for the string to double conversion.
static t_atof_vars	init_values(const char *str)
{
	t_atof_vars	vars;

	vars.divide = 1;
	vars.i = skip_spacing_atof(str);
	vars.sign = 1;
	vars.int_digs = 0;
	vars.frac_digs = 0;
	vars.non_zero_out = 0;
	return (vars);
}

//Function adds the integral digits component to the number.
static void	int_digs(const char *str, t_atof_vars *vars)
{
	while (str[vars->i] >= '0' && str[vars->i] <= '9' && str[vars->i] != '.')
	{
		vars->int_digs = 10 * vars->int_digs + \
		(double)(str[vars->i] - '0');
		vars->non_zero_out = 1;
		vars->i++;
	}
	vars->i++;
}

//Function adds the fractional digits component to the number.
static void	frac_digs(const char *str, t_atof_vars *vars)
{
	while (str[vars->i] >= '0' && str[vars->i] <= '9')
	{
		vars->frac_digs = 10 * vars->frac_digs + \
			(double)(str[vars->i] - '0');
		vars->divide = 10 * vars->divide;
		vars->non_zero_out = 1;
		vars->i++;
	}
	vars->frac_digs = vars->frac_digs / vars->divide;
}

//Function that converts a string's contents to a double type variable.
double	ft_atof(const char *str)
{
	t_atof_vars	vars;
	double		ret;

	vars = init_values(str);
	if (str[vars.i] == '-')
		vars.sign = -1;
	if (str[vars.i] == '-' || str[vars.i] == '+')
	{
		vars.i++;
		if (str[vars.i + 1] == '-' || str[vars.i + 1] == '+')
			return (-1);
	}
	int_digs(str, &vars);
	if (contains_decimal(str) == 1)
		frac_digs(str, &vars);
	if (vars.non_zero_out == 0)
		return (-1);
	ret = vars.sign * (vars.int_digs + vars.frac_digs);
	return (ret);
}
