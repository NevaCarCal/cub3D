/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_move.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/27 14:29:19 by brimarti          #+#    #+#             */
/*   Updated: 2025/06/27 14:29:22 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	is_wall(t_data *data, double x, double y)
{
	int	map_x;
	int	map_y;

	map_x = (int)x;
	map_y = (int)y;
	if (map_y < 0 || map_x < 0 || map_y >= data->height)
		return (1);
	if (map_x >= line_length(data->map[map_y]))
		return (1);
	return (data->map[map_y][map_x] == '1'
		|| data->map[map_y][map_x] == ' ');
}

/*	We test X and Y separately. That lets the player slide along walls
	instead of getting stuck when one axis is blocked and the other is free.*/
int	try_move(t_data *data, double move_x, double move_y)
{
	int	moved;

	moved = 0;
	if (!is_wall(data, data->pos_x + move_x, data->pos_y))
	{
		data->pos_x += move_x;
		moved = 1;
	}
	if (!is_wall(data, data->pos_x, data->pos_y + move_y))
	{
		data->pos_y += move_y;
		moved = 1;
	}
	return (moved);
}

/*	Strafe uses the perpendicular vector to the camera direction.
	If dir is (x, y), one perpendicular is (-y, x).*/
int	move_player(int keycode, t_data *data)
{
	if (keycode == W || keycode == KEY_UP)
		return (try_move(data, data->dir_x * MOVE_SPEED,
				data->dir_y * MOVE_SPEED));
	if (keycode == S || keycode == KEY_DOWN)
		return (try_move(data, -data->dir_x * MOVE_SPEED,
				-data->dir_y * MOVE_SPEED));
	if (keycode == A)
		return (try_move(data, data->dir_y * MOVE_SPEED,
				-data->dir_x * MOVE_SPEED));
	if (keycode == D)
		return (try_move(data, -data->dir_y * MOVE_SPEED,
				data->dir_x * MOVE_SPEED));
	return (0);
}

int	key_hook(int keycode, t_data *data)
{
	int	changed;

	if (keycode == KEY_ESC)
		destroy_all(data);
	changed = move_player(keycode, data);
	if (rotate_player(keycode, data))
		changed = 1;
	if (changed)
		render_frame(data);
	return (0);
}
