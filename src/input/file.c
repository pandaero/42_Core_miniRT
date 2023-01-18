/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:05:18 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/18 20:08:05 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <fcntl.h>

//Function checks whether the filename has the input extension.
int	has_extension(const char *str, const char *ext)
{
	char	*extension;
	int		i;
	int		ret;

	ret = 0;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '.')
		{
			extension = ft_substr(str, i + 1, ft_strlen(ext) + 1);
			if (ft_strncmp(extension, ext, ft_strlen(ext) + 1) == 0)
				ret = 1;
			else
				ret = 0;
			free(extension);
			return (ret);
		}
		i++;
	}
	return (ret);
}

//Function checks file contents against forbidden characters.
int	has_valid_contents(const char *filename)
{
	char	*line;
	int		ii[2];

	ii[0] = open(filename, O_RDONLY);
	line = get_next_line(ii[0]);
	while (line != NULL)
	{
		ii[1] = 0;
		while (line[ii[1]] != '\0')
		{
			if (is_valid_char(line[ii[1]]) == 1)
				ii[1]++;
			else
			{
				free(line);
				return (0);
			}
		}
		free(line);
		line = get_next_line(ii[0]);
	}
	close(ii[0]);
	return (1);
}

//Function frees the pointers used in the file valid formatting loop.
static void	free_valid_formatting(char *line, char *clean)
{
	free(line);
	free(clean);
}

//Function checks whether the formatting of an input file is correct.
int	has_valid_formatting(const char *filename)
{
	t_valid_formatting	strct;

	strct.fd = open(filename, O_RDONLY);
	strct.line = get_next_line(strct.fd);
	while (strct.line != NULL)
	{
		if (ft_strncmp(strct.line, "\n", 2) == 0)
		{
			free(strct.line);
			strct.line = get_next_line(strct.fd);
			continue ;
		}
		strct.clean = replace_spacing(strct.line);
		if (check_valid_line(strct.clean) == 0)
		{
			free_valid_formatting(strct.line, strct.clean);
			return (0);
		}
		free_valid_formatting(strct.line, strct.clean);
		strct.line = get_next_line(strct.fd);
	}
	close(strct.fd);
	return (1);
}
