/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:43:34 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 15:41:49 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	cast_ray(t_data *data)
{
	floor_casting(data);
	wall_casting(data);
}

int	ft_mlx_render(t_data *data)
{
	t_img	img;

	if (data->mouselook_on)
		mlx_mouse_move(data->mlx, data->w_ptr, \
		data->w_data.width / 2, data->w_data.height / 2);
	img = data->img_a;
	move_player(data);
	cast_ray(data);
	if (BONUS)
		draw_minimap(data);
	mlx_put_image_to_window(data->mlx, data->w_ptr, img.img, 0, 0);
	return (0);
}
