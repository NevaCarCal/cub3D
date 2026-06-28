/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_draw.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: brimarti <brimarti@student.42madrid.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/06/04 00:00:00 by brimarti          #+#    #+#             */
/*   Updated: 2026/06/04 00:00:00 by brimarti         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "raycast_internal.h"

static void	put_pixel(t_img *img, int x, int y, int color)
{
	char	*dst;

	if (x < 0 || x >= WIN_WIDTH || y < 0 || y >= WIN_HEIGHT)
		return ;
	dst = img->addr + (y * img->line_length
			+ x * (img->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

static void	wall_limits(t_ray *ray)
{
	ray->line_height = (int)(WIN_HEIGHT / ray->perp_wall_dist);
	ray->draw_start = -ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = ray->line_height / 2 + WIN_HEIGHT / 2;
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT - 1;
}

static int	get_tex_x(t_data *data, t_ray *ray)
{
	double	wall_x;
	int		tex_x;

	get_wall_hit_x(data, ray, &wall_x);
	tex_x = (int)(wall_x * ray->texture->width);
	if (ray->side == 0 && ray->ray_dir_x > 0)
		tex_x = ray->texture->width - tex_x - 1;
	if (ray->side == 1 && ray->ray_dir_y < 0)
		tex_x = ray->texture->width - tex_x - 1;
	return (tex_x);
}

static void	draw_textured_wall(t_data *data, int x, t_ray *ray)
{
	double	tex_step;
	double	tex_pos;
	int		tex_x;
	int		tex_y;

	tex_x = get_tex_x(data, ray);
	tex_step = (double)ray->texture->height / ray->line_height;
	tex_pos = (ray->draw_start - WIN_HEIGHT / 2
			+ ray->line_height / 2) * tex_step;
	while (ray->draw_start <= ray->draw_end)
	{
		tex_y = (int)tex_pos;
		if (tex_y < 0)
			tex_y = 0;
		if (tex_y >= ray->texture->height)
			tex_y = ray->texture->height - 1;
		put_pixel(&data->frame, x, ray->draw_start,
			get_texture_color(ray->texture, tex_x, tex_y));
		tex_pos += tex_step;
		ray->draw_start++;
	}
}

void	draw_column(t_data *data, int x, t_ray *ray)
{
	int	y;

	wall_limits(ray);
	y = 0;
	while (y < ray->draw_start)
		put_pixel(&data->frame, x, y++, data->ceiling_color);
	draw_textured_wall(data, x, ray);
	y = ray->draw_end + 1;
	while (y < WIN_HEIGHT)
		put_pixel(&data->frame, x, y++, data->floor_color);
}
