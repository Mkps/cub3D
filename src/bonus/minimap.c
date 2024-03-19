/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:42:45 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/11 11:22:50 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	draw_player_widget(t_data *data, int color, t_coord s)
{
	t_point	point_array[5];
	t_point	target;

	point_array[0] = to_point(s.x, s.y);
	point_array[1] = to_point(s.x + 2, s.y - 2);
	point_array[2] = to_point(s.x - 2, s.y - 2);
	point_array[3] = to_point(s.x + 2, s.y + 2);
	point_array[4] = to_point(s.x - 2, s.y + 2);
	target = to_point(s.y + (data->player.dir_y * 6), \
			s.x + (data->player.dir_x * 6));
	if (target.x < 0)
		target.x = 0;
	if (target.x > data->w_data.height)
		target.x = data->w_data.height;
	if (target.y < 0)
		target.y = 0;
	if (target.y > data->w_data.width)
		target.y = data->w_data.width;
	ft_draw_line(data, point_array[0], target, color);
	ft_draw_line(data, point_array[1], target, color);
	ft_draw_line(data, point_array[2], target, color);
	ft_draw_line(data, point_array[3], target, color);
	ft_draw_line(data, point_array[4], target, color);
}

void	draw_player(t_data *d, t_coord s)
{
	int		c;
	int		x;
	int		y;

	c = 0xFFFF00;
	x = -3;
	while (++x < 2)
	{
		y = -3;
		while (++y < 2)
		{
			if (s.x + x > 0 && s.x + x < d->w_data.height
				&& s.y + y > 0 && s.y + y < d->w_data.width)
			{
				ft_mlx_pixel_put(&d->img_a, s.x + x, s.y + y, c);
			}
		}
	}
	draw_player_widget(d, c, s);
}

int	get_mmap_color(t_data *data, int x, int y)
{
	int		color;

	if (x < 0 || x >= data->m_data.height || y < 0 || y >= data->m_data.width)
		return (0xFF00FF);
	if (data->map[x][y] == -42)
		color = 0xFF00FF;
	else if (data->map[x][y] > 0
			&& data->map[x][y] < e_o)
		color = 0xFFFFFF;
	else if (data->map[x][y] == e_o)
		color = 0x0000FF;
	else if (data->map[x][y] == e_d)
		color = 0xFF0000;
	else
		color = 0x000000;
	return (color);
}

void	draw_map(t_data *data, t_coord size)
{
	t_coord	pos;
	t_point	itr;

	pos.y = 25;
	itr.x = (int)data->player.pos_x - 5;
	while (++itr.x < (int)data->player.pos_x + 5)
	{
		pos.x = 25;
		itr.y = (int)data->player.pos_y - 5;
		while (++itr.y < (int)data->player.pos_y + 5)
		{
			draw_rect(data, pos, size, get_mmap_color(data, itr.x, itr.y));
			pos.x += size.y;
		}
		pos.y += size.x;
	}
	pos.y = (25 - (size.x / 2)) + (size.x * 5);
	pos.x = (25 - (size.y / 2)) + (size.y * 5);
	draw_player(data, pos);
}

void	draw_minimap(t_data *data)
{
	t_coord	size;

	size.y = (float)data->w_data.width / 32;
	size.x = (float)data->w_data.height / 32;
	if (size.y > size.x)
		size.y = size.x;
	else
		size.x = size.y;
	draw_map(data, size);
}
