/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_config.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 23:52:45 by ncarrera          #+#    #+#             */
/*   Updated: 2026/06/28 10:32:51 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	parse_texture(t_data *data, char *p)
{
	if (ft_strncmp(p, "NO", 2) == 0 && (p[2] == ' ' || p[2] == '\t'))
		set_texture(&data->north_tex, p + 2, data);
	else if (ft_strncmp(p, "SO", 2) == 0 && (p[2] == ' ' || p[2] == '\t'))
		set_texture(&data->south_tex, p + 2, data);
	else if (ft_strncmp(p, "WE", 2) == 0 && (p[2] == ' ' || p[2] == '\t'))
		set_texture(&data->west_tex, p + 2, data);
	else if (ft_strncmp(p, "EA", 2) == 0 && (p[2] == ' ' || p[2] == '\t'))
		set_texture(&data->east_tex, p + 2, data);
	else
		return (0);
	return (1);
}

int	parse_config_line(t_data *data, char *line)
{
	char	*p;

	p = skip_spaces(line);
	if (parse_texture(data, p))
		return (1);
	if (parse_floor_color(data, p))
		return (1);
	if (parse_ceiling_color(data, p))
		return (1);
	return (0);
}

int	is_map_start(char *line)
{
	line = skip_spaces(line);
	return (*line == '1' || *line == '0' || *line == 'N'
		|| *line == 'S' || *line == 'E' || *line == 'W');
}
