/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:28:07 by brimarti          #+#    #+#             */
/*   Updated: 2025/06/27 14:28:12 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	check_filename(char *argv, t_data *data)
{
	if (ft_strlen(argv) < 4)
		handle_error(CUB, data);
	argv = argv + (ft_strlen(argv) - 4);
	if (ft_strncmp(argv, ".cub", 4))
		handle_error(CUB, data);
}

void	read_lines(char *path, char ***lines, int *total, t_data *data)
{
	int	fd;
	int	i;

	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_error(FD, data);
	*total = count_lines(fd);
	close(fd);
	*lines = malloc(sizeof(char *) * (*total + 1));
	if (!*lines)
		handle_error(MALLOCERROR, data);
	fd = open(path, O_RDONLY);
	if (fd < 0)
		handle_error(FD, data);
	i = 0;
	while (i < *total)
		(*lines)[i++] = get_next_line(fd);
	free(get_next_line(fd));
	(*lines)[i] = NULL;
	close(fd);
}

void	free_lines(char **lines)
{
	int	i;

	i = 0;
	if (!lines)
		return ;
	while (lines[i])
		free(lines[i++]);
	free(lines);
}

int	ft_init(t_data *data, char **argv)
{
	char	**lines;
	int		total;

	lines = NULL;
	check_filename(argv[1], data);
	read_lines(argv[1], &lines, &total, data);
	parse_file(data, lines, total);
	free_lines(lines);
	map_checker(data);
	set_camera(data);
	return (0);
}
