/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:08:35 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 15:41:58 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	destroy_walls(t_data *data)
{
	if (data->world.n.path)
	{
		free(data->world.n.path);
		if (data->world.n.img.img)
			mlx_destroy_image(data->mlx, data->world.n.img.img);
	}
	if (data->world.s.path)
	{
		free(data->world.s.path);
		if (data->world.s.img.img)
			mlx_destroy_image(data->mlx, data->world.s.img.img);
	}
	if (data->world.e.path)
	{
		free(data->world.e.path);
		if (data->world.e.img.img)
			mlx_destroy_image(data->mlx, data->world.e.img.img);
	}
	if (data->world.w.path)
	{
		free(data->world.w.path);
		if (data->world.w.img.img)
			mlx_destroy_image(data->mlx, data->world.w.img.img);
	}
}

void	destroy_mapinfo(t_data *data)
{
	if (data->mapinfo.no_texture)
		free(data->mapinfo.no_texture);
	if (data->mapinfo.so_texture)
		free(data->mapinfo.so_texture);
	if (data->mapinfo.ea_texture)
		free(data->mapinfo.ea_texture);
	if (data->mapinfo.we_texture)
		free(data->mapinfo.we_texture);
	if (data->mapinfo.do_texture)
		free(data->mapinfo.do_texture);
}

void	destroy_sprite(t_data *data)
{
	int	x;

	x = -1;
	if (!data->sprite)
		return ;
	while (++x < data->sprite_count)
	{
		if (data->sprite[x].animation)
		{
			if (data->sprite[x].animation[0].path)
			{
				mlx_destroy_image(data->mlx, \
					data->sprite[x].animation[0].img.img);
				free(data->sprite[x].animation[0].path);
			}
			free(data->sprite[x].animation);
		}
	}
	free(data->sprite);
}

void	destroy_world(t_data *data)
{
	if (BONUS)
		destroy_sprite(data);
	destroy_walls(data);
	destroy_mapinfo(data);
	destroy_door(data);
	if (!data->world.is_f_color)
		mlx_destroy_image(data->mlx, data->world.f.img.img);
	if (!data->world.is_c_color)
		mlx_destroy_image(data->mlx, data->world.c.img.img);
}

int	exit_mlx_init(t_data *data)
{
	int	errcode;

	errcode = 0;
	if (data->mlx && data->img_a.img)
		mlx_destroy_image(data->mlx, data->img_a.img);
	else
		errcode++;
	if (data->mlx && data->w_ptr)
		mlx_destroy_window(data->mlx, data->w_ptr);
	else
		errcode++;
	if (data->mlx)
	{
		mlx_destroy_display(data->mlx);
		mlx_loop_end(data->mlx);
		free(data->mlx);
	}
	exit(EXIT_FAILURE);
	return (EXIT_FAILURE);
}
