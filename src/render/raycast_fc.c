/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_fc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:43:03 by aloubier          #+#    #+#             */
/*   Updated: 2023/12/21 18:43:03 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_floor(t_data *data, t_floor *f, int y)
{
	f->ray[0].x = data->player.dir_x - data->plane.x;
	f->ray[0].y = data->player.dir_y - data->plane.y;
	f->ray[1].x = data->player.dir_x + data->plane.x;
	f->ray[1].y = data->player.dir_y + data->plane.y;
	f->p = y - data->w_data.height / 2;
	f->row_dist = f->pos_z / f->p;
	f->floor_step.x = f->row_dist * (f->ray[1].x
			- f->ray[0].x) / W;
	f->floor_step.y = f->row_dist * (f->ray[1].y
			- f->ray[0].y) / W;
	f->floor.x = data->player.pos_x + f->row_dist * f->ray[0].x;
	f->floor.y = data->player.pos_y + f->row_dist * f->ray[0].y;
}

void	update_floor(t_floor *f)
{
	f->cell.x = (int)(f->floor.x);
	f->cell.y = (int)(f->floor.y);
	f->tex.x = (int)(T_W * (f->floor.x - f->cell.x))
		& (T_W - 1);
	f->tex.y = (int)(T_H * (f->floor.y - f->cell.y))
		& (T_H - 1);
	f->floor.x += f->floor_step.x;
	f->floor.y += f->floor_step.y;
}

//FLOOR & CEILING CASTING
void	floor_casting(t_data *data)
{
	t_floor	f;
	int		y;
	int		x;
	int		color;

	f.pos_z = 0.5 * data->w_data.height;
	y = data->w_data.height / 2;
	while (++y < data->w_data.height)
	{
		init_floor(data, &f, y);
		x = -1;
		while (++x < W)
		{
			update_floor(&f);
			color = data->world.f_color;
			ft_mlx_pixel_put(&data->img_a, x, y, color);
			color = data->world.c_color;
			ft_mlx_pixel_put(&data->img_a, x, H - y - 1, color);
		}
	}
}
