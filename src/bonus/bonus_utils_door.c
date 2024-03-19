/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus_utils_door.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 14:36:00 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 17:01:52 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	valid_mapchr(t_data *data, char c)
{
	if (BONUS == 0)
	{
		if (!(ft_strchr("10NSEW", c)))
			return (0);
		return (1);
	}
	if (BONUS == 1)
	{
		if (!(ft_strchr("D", c)))
			data->mapinfo.has_door = 1;
		if (!(ft_strchr("10NSEWD", c)))
			return (0);
		return (1);
	}
}

void	destroy_door(t_data *data)
{
	if (data->world.d.path)
	{
		free(data->world.d.path);
		if (data->world.d.img.img)
			mlx_destroy_image(data->mlx, data->world.d.img.img);
	}
}

void	door_check(t_data *data, char c)
{
	if (c != '\0' && ft_strchr("D", c) && !data->mapinfo.has_door \
		&& BONUS > 0)
		data->mapinfo.has_door = 1;
}

void	close_door(t_data *d, int map_x, int map_y)
{
	if (map_x == e_o || map_y == e_o)
	{
		if (map_x == e_o && d->map[(int)(d->player.pos_x)][\
		(int)(d->player.pos_y)] != e_o)
			d->map[(int)(d->player.pos_x + d->player.dir_x * 16 * MS)] \
			[(int)(d->player.pos_y)] = e_d;
		else if (map_y == e_o && d->map[(int)(d->player.pos_x)] \
		[(int)(d->player.pos_y)] != e_o)
			d->map[(int)(d->player.pos_x)][(int)(d->player.pos_y + \
			d->player.dir_y * 16 * MS)] = e_d;
	}
}

void	open_door(t_data *d)
{
	int	map_x;
	int	map_y;

	map_x = d->map[(int)(d->player.pos_x + d->player.dir_x * 16 * MS)] \
	[(int)(d->player.pos_y)];
	map_y = d->map[(int)(d->player.pos_x)][(int)(d->player.pos_y + \
	d->player.dir_y * 16 * MS)];
	if (map_x == e_d || map_y == e_d)
	{
		if (map_x == e_d)
			d->map[(int)(d->player.pos_x + d->player.dir_x * 16 * MS)] \
		[(int)(d->player.pos_y)] = e_o;
		else if (map_y == e_d)
			d->map[(int)(d->player.pos_x)][(int)(d->player.pos_y + \
		d->player.dir_y * 16 * MS)] = e_o;
	}
	else
		close_door(d, map_x, map_y);
}
