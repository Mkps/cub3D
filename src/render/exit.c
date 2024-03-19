/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:43:51 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 12:20:09 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_exit_cleanup(t_data *data, int exit_code)
{
	ft_mlx_exit(data, exit_code);
	if (BONUS == 2)
		destroy_sprite(data);
	return (exit_code);
}

void	destroy_map(t_data *data)
{
	int	x;

	x = -1;
	if (data->map)
	{
		while (++x < data->m_data.height)
		{
			free(data->map[x]);
		}
	}
	x = -1;
	if (data->cmap)
	{
		while (data->cmap[++x])
			free(data->cmap[x]);
		free(data->cmap);
	}
	if (data->m_data.fd > 0)
		close(data->m_data.fd);
	if (data->m_data.file)
		free_tab((void **)data->m_data.file);
	if (data->map)
		free(data->map);
}

void	ft_mlx_exit(t_data *data, int errcode)
{
	destroy_map(data);
	free(data->z_buffer);
	if (data->world.c_rgb)
		free(data->world.c_rgb);
	if (data->world.f_rgb)
		free(data->world.f_rgb);
	destroy_world(data);
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
	exit(errcode != 0);
}
