/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sprite_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 12:48:08 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/22 12:48:09 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

t_sprite	init_sprite(t_data *data, t_coord pos, int frame, char **animpath)
{
	t_sprite	ret;

	ret.pos.x = pos.x;
	ret.pos.y = pos.y;
	ret.animation = ft_calloc(frame, sizeof(t_xpm));
	ret.animation[0] = xpm_load(data, animpath[0]);
	ret.frame_count = frame;
	ret.frame = 0;
	ret.frame_time = 12;
	return (ret);
}

int	init_data_sprite(t_data *data)
{
	char		*sprite_path;
	t_sprite	*sprite;

	sprite_path = ft_strdup("./flameskull.xpm");
	data->sprite_count = 1;
	sprite = ft_calloc(data->sprite_count, sizeof(t_sprite));
	if (!sprite)
		return (output_error(NULL, "Error memalloc for sprite", 1));
	data->sprite = sprite;
	sprite[0] = init_sprite(data, to_coord(data->player.pos_x, \
				data->player.pos_y), 2, &sprite_path);
	if (!sprite[0].animation->path)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
