/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:54:58 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/19 21:28:35 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function determines what type of element an input file line describes.
t_element	element_line(const char *line)
{
	char	**split;

	split = ft_split(line, ' ');
	if (ft_strncmp(split[0], "A", 2) == 0)
		return (AMBIENT);
	if (ft_strncmp(split[0], "C", 2) == 0)
		return (CAMERA);
	if (ft_strncmp(split[0], "L", 2) == 0)
		return (LIGHT);
	if (ft_strncmp(split[0], "pl", 3) == 0)
		return (PLANE);
	if (ft_strncmp(split[0], "sp", 3) == 0)
		return (SPHERE);
	if (ft_strncmp(split[0], "cy", 3) == 0)
		return (CYLINDER);
	free_split(split);
	return (INVALID);
}

//Function takes an input file line and creates an object.
t_obj	*object_from_line(const char *line)
{
	t_element	elem;

	elem = element_line(line);
	if (elem == INVALID || elem == EMPTY)
		return (NULL);
	// if (elem == AMBIENT)
	// 	return (object_ambient_line(line));
	if (elem == CAMERA)
		return (object_camera_line(line));
	// if (elem == LIGHT)
	// 	return (object_light_line(line));
	// if (elem == PLANE)
	// 	return (object_plane_line(line));
	// if (elem == SPHERE)
	// 	return (object_sphere_line(line));
	// if (elem == CYLINDER)
	// 	return (object_cylinder_line(line));
	return (NULL);
}

//Function performs the input file parsing to program objects.
//Take filename
//check file formatting
//take file input line by line
//make elements and put into objects and add to object list
void	parse_input_file(const char *filename)
{
	has_valid_formatting(filename);

}
