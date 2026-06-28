/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 00:24:41 by ncarrera          #+#    #+#             */
/*   Updated: 2026/06/28 01:06:36 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char	*dup_map_line(char *line, t_data *data)
{
	int		i;
	int		len;
	char	*copy;

	len = line_length(line);
	copy = malloc(sizeof(char) * (len + 1));
	if (!copy)
		handle_error(MALLOCERROR, data);
	i = 0;
	while (i < len)
	{
		copy[i] = line[i];
		i++;
	}
	copy[i] = '\0';
	return (copy);
}

void	copy_map(t_data *data, char **lines, int start, int total)
{
	int	i;
	int	len;

	data->height = total - start;
	data->map = malloc(sizeof(char *) * (data->height + 1));
	if (!data->map)
		handle_error(MALLOCERROR, data);
	i = 0;
	while (i < data->height)
	{
		data->map[i] = dup_map_line(lines[start + i], data);
		len = line_length(data->map[i]);
		if (len > data->width)
			data->width = len;
		i++;
	}
	data->map[i] = NULL;
	data->size_x = data->width;
	data->size_y = data->height;
}

void	parse_file(t_data *data, char **lines, int total)
{
	int	i;

	i = 0;
	while (i < total)
	{
		if (is_blank(lines[i]))
			i++;
		else if (parse_config_line(data, lines[i]))
			i++;
		else if (is_map_start(lines[i]))
			break ;
		else
			handle_error(CONFIG_ERROR, data);
	}
	if (i == total || !data->north_tex || !data->south_tex
		|| !data->west_tex || !data->east_tex
		|| !data->floor_set || !data->ceiling_set)
		handle_error(CONFIG_ERROR, data);
	copy_map(data, lines, i, total);
}
