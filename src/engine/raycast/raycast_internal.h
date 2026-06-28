/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_internal.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/27 14:37:06 by brimarti          #+#    #+#             */
/*   Updated: 2026/06/28 02:31:54 by ncarrera         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef RAYCAST_INTERNAL_H
# define RAYCAST_INTERNAL_H

# include "cub3d.h"

typedef struct s_ray
{
	double		camera_x;
	double		ray_dir_x;
	double		ray_dir_y;
	double		side_dist_x;
	double		side_dist_y;
	double		delta_dist_x;
	double		delta_dist_y;
	double		perp_wall_dist;
	int			map_x;
	int			map_y;
	int			step_x;
	int			step_y;
	int			side;
	char		wall_dir;
	t_texture	*texture;
	int			draw_start;
	int			draw_end;
	int			line_height;
}				t_ray;

void			select_wall_texture(t_data *data, t_ray *ray);
unsigned int	get_texture_color(t_texture *texture, int x, int y);
void			get_wall_hit_x(t_data *data, t_ray *ray, double *wall_x);
void			init_ray(t_data *data, t_ray *ray, int x);
void			set_step(t_data *data, t_ray *ray);
void			run_dda(t_data *data, t_ray *ray);
void			draw_column(t_data *data, int x, t_ray *ray);

#endif
