/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 17:52:52 by pandalaf          #+#    #+#             */
/*   Updated: 2023/02/20 00:10:43 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>

//Function takes valid input file and populates program's object list.
void	fill_objects_file(t_program *program, const char *filename)
{
	char	*line;
	char	*clean;
	int		fd;

	fd = open(filename, O_RDONLY);
	if (fd == -1)
		error_file_open_exit(program);
	program->objlist = list_create();
	line = get_next_line(fd);
	while (line)
	{
		if (ft_strncmp(line, "\n", 2) == 0)
		{
			free(line);
			line = get_next_line(fd);
			continue ;
		}
		clean = replace_spacing(line);
		list_add_object(program->objlist, object_from_line(program, clean));
		free(clean);
		free(line);
		line = get_next_line(fd);
	}
	close(fd);
}
