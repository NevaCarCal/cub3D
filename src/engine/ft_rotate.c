/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ncarrera <ncarrera@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/28 01:12:44 by ncarrera          #+#    #+#             */
/*   Updated: 2026/06/28 01:57:32 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

/*	2D rotation matrix:
	new_x = old_x * cos(a) - old_y * sin(a)
	new_y = old_x * sin(a) + old_y * cos(a)*/
void	rotate_pair(double *x, double *y, double angle)
{
	double	old_x;

	old_x = *x;
	*x = *x * cos(angle) - *y * sin(angle);
	*y = old_x * sin(angle) + *y * cos(angle);
}

int	rotate_player(int keycode, t_data *data)
{
	double	angle;

	if (keycode != KEY_LEFT && keycode != KEY_RIGHT)
		return (0);
	angle = ROT_SPEED;
	if (keycode == KEY_LEFT)
		angle = -ROT_SPEED;
	rotate_pair(&data->dir_x, &data->dir_y, angle);
	rotate_pair(&data->plane_x, &data->plane_y, angle);
	return (1);
}
