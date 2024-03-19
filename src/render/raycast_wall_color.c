/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall_color.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 19:11:48 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 12:20:47 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

uint32_t	w_color_side(t_data *data, t_wall *t, t_ray_data *ray)
{
	uint32_t	color;

	color = 0xFF00FF;
	if (ray->raydir.x < 0 && t->tex_num != e_d)
		color = ft_mlx_pixel_get(&data->world.n.img, t->tex.x, t->tex.y);
	else if (t->tex_num != e_d)
		color = ft_mlx_pixel_get(&data->world.s.img, t->tex.x, t->tex.y);
	else if (t->tex_num == e_d && BONUS > 0)
		color = ft_mlx_pixel_get(&data->world.d.img, t->tex.x, t->tex.y);
	color = ft_color_shade(color);
	return (color);
}

uint32_t	w_color(t_data *data, t_wall *t, t_ray_data *ray)
{
	uint32_t	color;

	color = 0xFF00FF;
	t->tex.y = (int)t->tex_pos & (int)(t->tex_h - 1);
	t->tex_pos += t->step;
	t->tex.x = roundl(t->tex.x);
	if (ray->side == 1)
		color = w_color_side(data, t, ray);
	else if (ray->side == 0)
	{
		if (ray->raydir.y < 0 && t->tex_num != e_d)
			color = ft_mlx_pixel_get(&data->world.w.img, t->tex.x, t->tex.y);
		else if (t->tex_num != e_d)
			color = ft_mlx_pixel_get(&data->world.e.img, t->tex.x, t->tex.y);
		else if (t->tex_num == e_d && BONUS > 0)
			color = ft_mlx_pixel_get(&data->world.d.img, t->tex.x, t->tex.y);
	}
	return (color);
}
