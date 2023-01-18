/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pandalaf <pandalaf@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/18 14:05:18 by pandalaf          #+#    #+#             */
/*   Updated: 2023/01/18 14:26:20 by pandalaf         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/minirt.h"
#include <stdlib.h>

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
