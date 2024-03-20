/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:43:29 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 17:01:52 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	w_color(t_data *data, t_wall *t, t_ray_data *ray);
void		init_w_tex(t_data *data, t_ray_data ray, t_wall *t);

void	init_wall(t_data *data, t_ray_data ray, t_wall *t)
{
	t->h = data->w_data.height;
	t->line_h = (int)((double)t->h / ray.pwall_dist);
	t->draw.x = -(double)t->line_h / 2 + (double)t->h / 2;
	if (t->draw.x < 0)
		t->draw.x = 0;
	t->draw.y = (double)t->line_h / 2 + (double)t->h / 2;
	if (t->draw.y >= t->h)
		t->draw.y = t->h - 1;
	if (ray.map.x < 0 || ray.map.x >= data->mapinfo.height
		|| ray.map.y < 0 || ray.map.y >= data->mapinfo.width)
		t->tex_num = 0;
	else
		t->tex_num = data->map[(int)ray.map.x][(int)ray.map.y];
	init_w_tex(data, ray, t);
}

void	draw_vertline(t_data *data, t_ray_data ray, int x)
{
	t_wall	t;
	int		y;

	init_wall(data, ray, &t);
	if (ray.side == 1)
		t.wall_x = data->player.pos_y + ray.pwall_dist * ray.raydir.y;
	else
		t.wall_x = data->player.pos_x + ray.pwall_dist * ray.raydir.x;
	t.wall_x -= floor(t.wall_x);
	t.tex.x = (double)(t.wall_x * t.tex_h);
	if (ray.side == 1 && ray.raydir.x > 0)
		t.tex.x = t.tex_w - t.tex.x - 1;
	if (ray.side == 0 && ray.raydir.y < 0)
		t.tex.x = t.tex_w - t.tex.x - 1;
	t.step = (double)t.tex_h / t.line_h;
	t.tex_pos = (t.draw.x - (double)t.h / 2 + (double)t.line_h / 2) * t.step;
	y = t.draw.x - 1;
	while (++y < t.draw.y)
		ft_mlx_pixel_put(&data->img_a, x, y, w_color(data, &t, &ray));
	data->z_buffer[x] = ray.pwall_dist;
}

static int	is_oob(t_ray_data *r, t_data *data)
{
	if (r->map.y < 0.25
		|| r->map.x < 0.25
		|| r->map.y > data->mapinfo.width - 0.25
		|| r->map.x > data->mapinfo.height - 0.25)
		return (1);
	return (0);
}

void	perform_dda(t_data *data, t_ray_data *r)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (r->side_dist.x < r->side_dist.y)
		{
			r->side_dist.x += r->delta_dist.x;
			r->map.x += r->step.x;
			r->side = 1;
		}
		else
		{
			r->side_dist.y += r->delta_dist.y;
			r->map.y += r->step.y;
			r->side = 0;
		}
		if (is_oob(r, data))
			return ;
		if ((data->map[(int)r->map.x][(int)r->map.y] > 0
			|| data->map[(int)r->map.x][(int)r->map.y] == -42)
			&& data->map[(int)r->map.x][(int)r->map.y] != e_o)
			hit = 1;
	}
}

void	wall_casting(t_data *data)
{
	t_ray_data	ray;
	int			x;

	x = -1;
	while (++x < data->w_data.width)
	{
		ray = init_ray(data, x);
		perform_dda(data, &ray);
		ray.pwall_dist = ray.side * (ray.side_dist.x - ray.delta_dist.x)
			+ !ray.side * (ray.side_dist.y - ray.delta_dist.y);
		draw_vertline(data, ray, x);
	}
}
