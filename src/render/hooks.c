/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:12:17 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/11 11:29:29 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_mlx_destroy_hook(t_data *data)
{
	ft_mlx_exit(data, EXIT_SUCCESS);
	return (0);
}

int	ft_mlx_key_hook(int keycode, t_data *data)
{
	if (keycode == 65307 || keycode == 27)
		ft_mlx_exit(data, EXIT_SUCCESS);
	ft_key_movement(keycode, data);
	return (0);
}

int	ft_mlx_mouse_hook(int keycode, int x, int y, t_data *data)
{
	(void)y;
	(void)x;
	if (keycode == 1 && BONUS != 0)
	{
		if (data->mouselook_on == 0)
		{
			mlx_mouse_hide(data->mlx, data->w_ptr);
			data->mouselook_on = 1;
		}
		else if (data->mouselook_on == 1)
		{
			mlx_mouse_show(data->mlx, data->w_ptr);
			data->mouselook_on = 0;
		}
	}
	return (0);
}

int	ft_mlx_mouse_move(int x, int y, t_data *data)
{
	(void)y;
	if (!data->mouselook_on)
		return (0);
	if (x > data->w_data.width / 2 + 5 && x <= data->w_data.width - 1)
	{
		data->keys.l = 0;
		data->keys.r = 0.5;
	}
	else if (x < data->w_data.width / 2 - 5 && x >= 1)
	{
		data->keys.l = 0.5;
		data->keys.r = 0;
	}
	else
	{
		data->keys.l = 0;
		data->keys.r = 0;
	}
	return (0);
}

int	ft_mlx_mouse_exit(t_data *data)
{
	(void)data;
	return (EXIT_SUCCESS);
}
