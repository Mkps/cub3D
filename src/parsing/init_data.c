/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_data.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:10:45 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 12:00:46 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_world(t_data *data)
{
	data->world.is_f_color = 1;
	data->world.is_c_color = 1;
	data->world.n.path = NULL;
	data->world.s.path = NULL;
	data->world.e.path = NULL;
	data->world.w.path = NULL;
	data->world.d.path = NULL;
	data->world.n.img.img = NULL;
	data->world.s.img.img = NULL;
	data->world.w.img.img = NULL;
	data->world.e.img.img = NULL;
	data->world.d.img.img = NULL;
	data->world.c_rgb = 0;
	data->world.f_rgb = 0;
	data->world.c_color = -3;
	data->world.f_color = -3;
	data->map = NULL;
	data->cmap = NULL;
	data->m_data.fd = -1;
	data->m_data.file = NULL;
	data->m_data.has_door = 0;
}

static void	zero_data(t_data *data)
{
	data->mlx = NULL;
	data->w_ptr = NULL;
	data->img_a.img = NULL;
	data->cmap = NULL;
	data->map = NULL;
}

int	ft_data_init_mlx(t_data *data)
{
	zero_data(data);
	data->w_data.width = W;
	data->w_data.height = H;
	data->mlx = mlx_init();
	if (!data->mlx)
		return (output_error("Init", "Error initializing mlx", 1));
	data->w_ptr = mlx_new_window(data->mlx, data->w_data.width,
			data->w_data.height, "cub3d");
	if (!data->w_ptr)
		return (output_error("Init", "Error creating window", 1));
	if (init_img(data, &data->img_a) == EXIT_FAILURE)
		return (output_error("Init", "Error creating image", 1));
	data->is_menu_on = 0;
	ft_bzero(&data->keys, sizeof (data->keys));
	data->z_buffer = ft_calloc(data->w_data.width, sizeof(double));
	if (!data->z_buffer)
		return (output_error("Init", "Error creating z_buffer\n", 1));
	return (EXIT_SUCCESS);
}

void	init_player(t_data *data)
{
	data->player.pos_x = 0;
	data->player.pos_y = 0;
	data->player.dir_x = -3.0;
	data->player.dir_y = 0.0;
	data->plane.x = 0.0;
	data->plane.y = 0.66;
	data->mouselook_on = 0;
}

int	ft_data_init(t_data *data)
{
	if (ft_data_init_mlx(data))
		return (exit_mlx_init(data));
	init_player(data);
	init_world(data);
	return (EXIT_SUCCESS);
}
