/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:12:13 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 12:20:47 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	draw_rect(t_data *data, t_coord pos, t_coord size, int color)
{
	int	y;
	int	x;

	y = -1;
	while (++y < size.y)
	{
		x = -1;
		while (++x < size.x)
			ft_mlx_pixel_put(&data->img_a, pos.x + x, pos.y + y, color);
	}
}

int	ft_abs(int number)
{
	if (number >= 0)
		return (number);
	number *= -1;
	return (number);
}

int	steep_handler(t_point *a, t_point *b)
{
	int	steep;

	steep = 0;
	if (ft_abs(a->x - b->x) < ft_abs(a->y - b->y))
	{
		steep = 1;
		ft_swap(&a->x, &a->y);
		ft_swap(&b->x, &b->y);
	}
	if (a->x > b->x)
	{
		ft_swap(&a->x, &b->x);
		ft_swap(&a->y, &b->y);
	}
	return (steep);
}

void	ft_draw_line(t_data	*data, t_point a, t_point b, int color)
{
	t_point	c;
	float	slope;
	int		steep;
	t_img	img;

	img = data->img_a;
	steep = steep_handler(&a, &b);
	c.x = a.x;
	c.y = a.y;
	slope = 0;
	while (c.x < b.x)
	{
		slope = (c.x - a.x) / (float)(b.x - a.x);
		c.y = a.y + (b.y - a.y) * slope;
		if (steep)
			ft_mlx_pixel_put(&img, c.y, c.x, color);
		else
			ft_mlx_pixel_put(&img, c.x, c.y, color);
		c.x++;
	}
}

void	ft_draw_line_thick(t_data *data, t_point *p, int color, int thickness)
{
	float	slope;
	t_point	c;
	t_point	d;

	slope = (p[1].y - p[0].y) / (float)p[1].x - p[0].x;
	c.x = p[0].x;
	c.y = p[0].y;
	d.x = p[1].x;
	d.y = p[1].y;
	while (thickness--)
	{
		ft_draw_line(data, c, d, color);
		c.x += 1;
		c.y = p[0].y + (-1 / slope) * (c.x - p[0].x);
		d.x += 1;
		d.y = p[1].y + (-1 / slope) * (d.x - p[1].x);
	}
}
