/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 01:23:40 by ncarrera          #+#    #+#             */
/*   Updated: 2026/06/28 01:54:07 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	load_single_texture(t_data *data, t_texture *texture, char *path)
{
	texture->img.img = mlx_xpm_file_to_image(data->mlx, path,
			&texture->width, &texture->height);
	if (!texture->img.img)
		handle_error(IMG_ERROR, data);
	texture->img.addr = mlx_get_data_addr(texture->img.img,
			&texture->img.bits_per_pixel, &texture->img.line_length,
			&texture->img.endian);
	if (!texture->img.addr)
		handle_error(IMG_ERROR, data);
}

void	load_textures(t_data *data)
{
	load_single_texture(data, &data->textures[0], data->north_tex);
	load_single_texture(data, &data->textures[1], data->south_tex);
	load_single_texture(data, &data->textures[2], data->west_tex);
	load_single_texture(data, &data->textures[3], data->east_tex);
}
