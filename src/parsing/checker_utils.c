/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:26:58 by brimarti          #+#    #+#             */
/*   Updated: 2025/06/27 14:27:11 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_player(char c)
{
	return (c == 'N' || c == 'S' || c == 'E' || c == 'W');
}

int	is_valid_char(char c)
{
	return (c == ' ' || c == '0' || c == '1' || is_player(c));
}

int	is_walkable(char c)
{
	return (c == '0' || is_player(c));
}

char	map_at(t_data *data, int row, int col)
{
	if (row < 0 || col < 0 || row >= data->height)
		return (' ');
	if (col >= line_length(data->map[row]))
		return (' ');
	return (data->map[row][col]);
}

char	**duplicate_map(char **original, int height, t_data *data)
{
	int		i;
	char	**copy;

	copy = malloc(sizeof(char *) * (height + 1));
	if (!copy)
		return (NULL);
	i = 0;
	while (i < height)
	{
		copy[i] = ft_strdup(original[i]);
		if (!copy[i])
			handle_error(MALLOCERROR, data);
		i++;
	}
	copy[height] = NULL;
	return (copy);
}
