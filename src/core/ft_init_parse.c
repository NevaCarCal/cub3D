/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_parse.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 00:53:50 by ncarrera          #+#    #+#             */
/*   Updated: 2026/06/28 01:31:22 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	set_texture(char **target, char *line, t_data *data)
{
	if (*target)
		handle_error(CONFIG_ERROR, data);
	*target = dup_clean(line, data);
}

int	parse_number(char **line, t_data *data)
{
	int	value;

	value = 0;
	*line = skip_spaces(*line);
	if (**line < '0' || **line > '9')
		handle_error(COLOR_ERROR, data);
	while (**line >= '0' && **line <= '9')
	{
		value = value * 10 + (**line - '0');
		if (value > 255)
			handle_error(COLOR_ERROR, data);
		(*line)++;
	}
	*line = skip_spaces(*line);
	return (value);
}

int	parse_rgb(char *line, t_data *data)
{
	int	r;
	int	g;
	int	b;

	r = parse_number(&line, data);
	if (*line++ != ',')
		handle_error(COLOR_ERROR, data);
	g = parse_number(&line, data);
	if (*line++ != ',')
		handle_error(COLOR_ERROR, data);
	b = parse_number(&line, data);
	line = skip_spaces(line);
	if (*line != '\0' && *line != '\n')
		handle_error(COLOR_ERROR, data);
	return ((r << 16) | (g << 8) | b);
}

int	parse_floor_color(t_data *data, char *p)
{
	if (*p != 'F' || (p[1] != ' ' && p[1] != '\t') || data->floor_set)
		return (0);
	data->floor_color = parse_rgb(p + 1, data);
	data->floor_set = true;
	return (1);
}

int	parse_ceiling_color(t_data *data, char *p)
{
	if (*p != 'C' || (p[1] != ' ' && p[1] != '\t') || data->ceiling_set)
		return (0);
	data->ceiling_color = parse_rgb(p + 1, data);
	data->ceiling_set = true;
	return (1);
}
