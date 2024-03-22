/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprite_init.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:43:08 by aloubier          #+#    #+#             */
/*   Updated: 2023/12/21 18:43:08 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	init_sprite_data(t_data *data, t_sdata *s)
{
	int	i;

	s->sprite_order = (int *)malloc(sizeof(int) * data->sprite_count);
	s->sprite_distance = (double *)malloc(sizeof(double) * data->sprite_count);
	i = -1;
	while (++i < data->sprite_count)
	{
		s->sprite_order[i] = i;
		s->sprite_distance[i] = ((data->player.pos_x - data->sprite[i].pos.x)
				* (data->player.pos_x - data->sprite[i].pos.x)
				+ (data->player.pos_y - data->sprite[i].pos.y)
				* (data->player.pos_y - data->sprite[i].pos.y));
	}
	sort_sprites(s->sprite_order, s->sprite_distance, data->sprite_count);
}

void	free_sprite_data(t_sdata *s)
{
	free(s->sprite_order);
	free(s->sprite_distance);
}

void	init_sprite_tex(t_data *data, t_stex *t)
{
	t->inv_det = 1.0 / (data->plane.x * data->player.dir_y - data->player.dir_x
			* data->plane.y);
	t->transform.x = t->inv_det * (data->player.dir_y * t->sprite.x
			- data->player.dir_x * t->sprite.y);
	t->transform.y = t->inv_det * (-data->plane.y * t->sprite.x + data->plane.x
			* t->sprite.y);
	t->sprite_screen_x = (int)((data->w_data.width / (float)2) * (1
				+ t->transform.x / t->transform.y));
	t->sprite_h = abs((int)(data->w_data.height / (t->transform.y)));
	t->draw[0].y = -t->sprite_h / 2 + data->w_data.height / 2;
	if (t->draw[0].y < 0)
		t->draw[0].y = 0;
	t->draw[1].y = t->sprite_h / 2 + data->w_data.height / 2;
	if (t->draw[1].y >= data->w_data.height)
		t->draw[1].y = data->w_data.height - 1;
	t->sprite_w = abs((int)(data->w_data.height / (t->transform.y)));
	t->draw[0].x = -t->sprite_w / 2 + t->sprite_screen_x;
	if (t->draw[0].x < 0)
		t->draw[0].x = 0;
	t->draw[1].x = t->sprite_w / 2 + t->sprite_screen_x;
	if (t->draw[1].x >= data->w_data.width)
		t->draw[1].x = data->w_data.width - 1;
}
