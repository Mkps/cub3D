/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:43:51 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/11 11:16:37 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	init_img(t_data *data, t_img *current_img)
{
	int	bpp;
	int	line_length;
	int	endian;

	if (!data->mlx)
		return (EXIT_FAILURE);
	current_img->img = mlx_new_image(data->mlx,
			data->w_data.width, data->w_data.height);
	if (!current_img->img)
		return (EXIT_FAILURE);
	current_img->addr = mlx_get_data_addr(current_img->img,
			&bpp, &line_length, &endian);
	if (!current_img->addr)
		return (EXIT_FAILURE);
	current_img->line_length = line_length;
	current_img->bits_per_pixel = bpp;
	current_img->endian = endian;
	return (EXIT_SUCCESS);
}

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
