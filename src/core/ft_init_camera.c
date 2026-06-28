/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init_camera.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 23:35:27 by ncarrera          #+#    #+#             */
/*   Updated: 2026/06/28 12:03:07 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_camera_north(t_data *data)
{
	data->dir_x = 0;
	data->dir_y = -1;
	data->plane_x = 0.66;
	data->plane_y = 0;
}

static void	set_camera_south(t_data *data)
{
	data->dir_x = 0;
	data->dir_y = 1;
	data->plane_x = -0.66;
	data->plane_y = 0;
}

static void	set_camera_east(t_data *data)
{
	data->dir_x = 1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = 0.66;
}

static void	set_camera_west(t_data *data)
{
	data->dir_x = -1;
	data->dir_y = 0;
	data->plane_x = 0;
	data->plane_y = -0.66;
}

void	set_camera(t_data *data)
{
	data->pos_x = data->player_x + 0.5;
	data->pos_y = data->player_y + 0.5;
	if (data->player_dir == 'N')
		set_camera_north(data);
	else if (data->player_dir == 'S')
		set_camera_south(data);
	else if (data->player_dir == 'E')
		set_camera_east(data);
	else if (data->player_dir == 'W')
		set_camera_west(data);
}
