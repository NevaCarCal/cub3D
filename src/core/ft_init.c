/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:28:07 by brimarti          #+#    #+#             */
/*   Updated: 2026/07/01 15:23:48 by ncarrera         ###   ########.fr       */
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
	t_struct_l	struct_l;

	struct_l.fd = open(path, O_RDONLY);
	if (struct_l.fd < 0)
		handle_error(FD, data);
	*total = count_lines(struct_l.fd);
	close(struct_l.fd);
	*lines = malloc(sizeof(char *) * (*total + 1));
	if (!*lines)
		handle_error(MALLOCERROR, data);
	struct_l.i = 0;
	while (struct_l.i <= *total)
		(*lines)[struct_l.i++] = NULL;
	data->file_lines = *lines;
	struct_l.fd = open(path, O_RDONLY);
	if (struct_l.fd < 0)
		handle_error(FD, data);
	struct_l.i = 0;
	while (struct_l.i < *total)
		(*lines)[struct_l.i++] = get_next_line(struct_l.fd);
	free(get_next_line(struct_l.fd));
	(*lines)[struct_l.i] = NULL;
	struct_l.tmp = get_next_line(struct_l.fd);
	free(struct_l.tmp);
	close(struct_l.fd);
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
	data->file_lines = NULL;
	map_checker(data);
	set_camera(data);
	return (0);
}
