/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_init.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:43:51 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 17:43:35 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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

t_xpm	xpm_load(t_data *data, char *path)
{
	t_xpm	t;

	t.path = ft_strdup(path);
	free(path);
	t.img.img = mlx_xpm_file_to_image(data->mlx, t.path, &t.w, &t.h);
	if (!t.img.img)
	{
		free(t.path);
		t.path = NULL;
		ft_putstr_fd("Error\n", 2);
		perror("cub3D: failed to load xpm");
		return (t);
	}
	t.img.addr = mlx_get_data_addr(t.img.img, &t.img.bits_per_pixel, \
		&t.img.line_length, &t.img.endian);
	return (t);
}

int	load_textures(t_data *data)
{
	data->world.n = xpm_load(data, data->mapinfo.no_texture);
	data->mapinfo.no_texture = NULL;
	if (!data->world.n.path)
		return (EXIT_FAILURE);
	data->world.s = xpm_load(data, data->mapinfo.so_texture);
	data->mapinfo.so_texture = NULL;
	if (!data->world.s.path)
		return (EXIT_FAILURE);
	data->world.e = xpm_load(data, data->mapinfo.ea_texture);
	data->mapinfo.ea_texture = NULL;
	if (!data->world.e.path)
		return (EXIT_FAILURE);
	data->world.w = xpm_load(data, data->mapinfo.we_texture);
	data->mapinfo.we_texture = NULL;
	if (!data->world.w.path)
		return (EXIT_FAILURE);
	data->world.f_color = data->mapinfo.f_color;
	data->world.c_color = data->mapinfo.c_color;
	if (BONUS > 0 && data->world.d.path)
	{
		data->world.d = xpm_load(data, data->world.d.path);
		if (!data->world.d.path && BONUS > 0)
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
