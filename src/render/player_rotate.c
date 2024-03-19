/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:42:59 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 12:20:47 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_right(t_data *data)
{
	float	old_plane;
	float	old_dir;

	old_dir = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(-RS * data->keys.r)
		- data->player.dir_y * sin(-RS * data->keys.r);
	data->player.dir_y = old_dir * sin(-RS * data->keys.r)
		+ data->player.dir_y * cos(-RS * data->keys.r);
	old_plane = data->plane.x;
	data->plane.x = data->plane.x * cos(-RS * data->keys.r)
		- data->plane.y * sin(-RS * data->keys.r);
	data->plane.y = old_plane * sin(-RS * data->keys.r)
		+ data->plane.y * cos(-RS * data->keys.r);
}

void	rotate_left(t_data *data)
{
	float	old_plane;
	float	old_dir;

	old_dir = data->player.dir_x;
	data->player.dir_x = data->player.dir_x * cos(data->keys.l * RS)
		- data->player.dir_y * sin(data->keys.l * RS);
	data->player.dir_y = old_dir * sin(data->keys.l * RS)
		+ data->player.dir_y * cos(data->keys.l * RS);
	old_plane = data->plane.x;
	data->plane.x = data->plane.x * cos(data->keys.l * RS)
		- data->plane.y * sin(data->keys.l * RS);
	data->plane.y = old_plane * sin(data->keys.l * RS)
		+ data->plane.y * cos(data->keys.l * RS);
}
