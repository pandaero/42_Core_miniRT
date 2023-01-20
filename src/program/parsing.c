/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 19:54:58 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/20 04:44:55 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"

//Function determines what type of element an input file line describes.
t_element	element_line(const char *line)
{
	t_element	ret;
	char		**split;

	ret = INVALID;
	split = ft_split(line, ' ');
	if (ft_strncmp(split[0], "A", 2) == 0)
		ret = AMBIENT;
	if (ft_strncmp(split[0], "C", 2) == 0)
		ret = CAMERA;
	if (ft_strncmp(split[0], "L", 2) == 0)
		ret = LIGHT;
	if (ft_strncmp(split[0], "pl", 3) == 0)
		ret = PLANE;
	if (ft_strncmp(split[0], "sp", 3) == 0)
		ret = SPHERE;
	if (ft_strncmp(split[0], "cy", 3) == 0)
		ret = CYLINDER;
	free_split(split);
	return (ret);
}

//Function takes an input file line and creates an object.
t_obj	*object_from_line(t_program *program, const char *line)
{
	t_element	elem;

	elem = element_line(line);
	if (elem == INVALID || elem == EMPTY)
		return (NULL);
	if (elem == AMBIENT)
		return (object_ambient_line(program, line));
	if (elem == CAMERA)
		return (object_camera_line(program, line));
	if (elem == LIGHT)
		return (object_light_line(program, line));
	if (elem == PLANE)
		return (object_plane_line(program, line));
	if (elem == SPHERE)
		return (object_sphere_line(program, line));
	if (elem == CYLINDER)
		return (object_cylinder_line(program, line));
	return (NULL);
}

//Function performs the input file parsing to create program objects.
void	parse_input_file(t_program *program, const char *filename)
{
	if (valid_file_extension(filename, "rt") == 0)
		error_file_exit(program, "EXTENSION");
	if (valid_file_contents(filename) == 0)
		error_file_exit(program, "CONTENT");
	if (valid_file_formatting(filename) == 0)
		error_file_exit(program, "FORMATTING");
	fill_objects_file(program, filename);
	if (valid_elements(program->objlist) == 0)
		error_file_exit(program, "ELEMENTS");
}
