/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_wall_init.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:43:25 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/09 13:41:10 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_w_tex(t_data *data, t_ray_data ray, t_wall *t)
{
	if (t->tex_num == e_d && BONUS)
	{
		t->tex_w = data->world.d.w;
		t->tex_h = data->world.d.h;
	}
	else if (ray.side == 1 && ray.raydir.x < 0)
	{
		t->tex_w = data->world.n.w;
		t->tex_h = data->world.n.h;
	}
	else if (ray.side == 1 && ray.raydir.x >= 0)
	{
		t->tex_w = data->world.s.w;
		t->tex_h = data->world.s.h;
	}
	else if (ray.side == 0 && ray.raydir.y >= 0)
	{
		t->tex_w = data->world.e.w;
		t->tex_h = data->world.e.h;
	}
	else if (ray.side == 0 && ray.raydir.y < 0)
	{
		t->tex_w = data->world.w.w;
		t->tex_h = data->world.w.h;
	}
}

double	get_camera(t_data *data, int x)
{
	return (2 * x / (double)data->w_data.width - 1);
}

void	set_delta(t_ray_data *ray)
{
	if (ray->raydir.x == 0)
		ray->delta_dist.x = 1e30;
	else
		ray->delta_dist.x = fabs(1 / ray->raydir.x);
	if (ray->raydir.y == 0)
		ray->delta_dist.y = 1e30;
	else
		ray->delta_dist.y = fabs(1 / ray->raydir.y);
}

void	set_dist(t_data *data, t_ray_data *ray)
{
	if (ray->raydir.x < 0)
	{
		ray->step.x = -1;
		ray->side_dist.x = (data->player.pos_x - ray->map.x) \
		* ray->delta_dist.x;
	}
	else
	{
		ray->step.x = 1;
		ray->side_dist.x = (ray->map.x + 1.0 - data->player.pos_x)
			* ray->delta_dist.x;
	}
	if (ray->raydir.y < 0)
	{
		ray->step.y = -1;
		ray->side_dist.y = (data->player.pos_y - ray->map.y) \
		* ray->delta_dist.y;
	}
	else
	{
		ray->step.y = 1;
		ray->side_dist.y = (ray->map.y + 1.0 - data->player.pos_y)
			* ray->delta_dist.y;
	}
}

t_ray_data	init_ray(t_data *data, int x)
{
	t_ray_data	ray;

	ray.raydir.x = data->player.dir_x + data->plane.x * get_camera(data, x);
	ray.raydir.y = data->player.dir_y + data->plane.y * get_camera(data, x);
	ray.map.x = (int)data->player.pos_x;
	ray.map.y = (int)data->player.pos_y;
	set_delta(&ray);
	set_dist(data, &ray);
	return (ray);
}
