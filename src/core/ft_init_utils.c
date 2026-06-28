/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/21 00:24:33 by ncarrera          #+#    #+#             */
/*   Updated: 2026/06/21 01:50:09 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*skip_spaces(char *str)
{
	while (*str == ' ' || *str == '\t')
		str++;
	return (str);
}

int	is_blank(char *line)
{
	line = skip_spaces(line);
	return (*line == '\n' || *line == '\0');
}

char	*dup_clean(char *line, t_data *data)
{
	int		i;
	int		end;
	char	*copy;

	line = skip_spaces(line);
	end = line_length(line);
	while (end > 0 && (line[end - 1] == ' ' || line[end - 1] == '\t'))
		end--;
	copy = malloc(sizeof(char) * (end + 1));
	if (!copy)
		handle_error(MALLOCERROR, data);
	i = 0;
	while (i < end)
	{
		copy[i] = line[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}
