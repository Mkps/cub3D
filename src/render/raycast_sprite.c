/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprite.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:43:20 by aloubier          #+#    #+#             */
/*   Updated: 2023/12/21 18:43:20 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

void	init_sprite_data(t_data *data, t_sdata *s);
void	init_sprite_tex(t_data *data, t_stex *t);
void	free_sprite_data(t_sdata *s);

int	get_current_frame(t_sprite *sprite, int texX, int texY)
{
	void	*img;
	int		current_frame;
	int		offsetx;
	int		offsety;

	current_frame = sprite->frame / sprite->frame_time;
	if (current_frame >= sprite->frame_count)
		current_frame = sprite->frame_count - 1;
	img = &sprite->animation[0].img;
	offsetx = current_frame % 8 * 64;
	offsety = current_frame / 8 * 64;
	return (ft_mlx_pixel_get(img, texX + offsetx, texY + offsety));
}

int	show_stripe(t_data *data, t_stex *t)
{
	if (t->transform.y > 0 && t->c_stripe > 0
		&& t->c_stripe < data->w_data.width
		&& t->transform.y < data->z_buffer[t->c_stripe])
		return (1);
	return (0);
}

void	get_stripe(t_data *data, t_sdata *s, t_stex *t, int i)
{
	int		y;
	int		d;
	int		color;

	t->c_stripe = t->draw[0].x - 1;
	while (++t->c_stripe < t->draw[1].x)
	{
		t->tex.x = (int)(256 * (t->c_stripe - (-t->sprite_w / 2
						+ t->sprite_screen_x)) * T_W / t->sprite_w) / 256;
		if (show_stripe(data, t))
		{
			y = t->draw[0].y - 1;
			while (++y < t->draw[1].y)
			{
				d = y * 256 - data->w_data.height * 128 + t->sprite_h * 128;
				t->tex.y = ((d * T_H) / t->sprite_h) / 256;
				color = get_current_frame(&data->sprite[s->sprite_order[i]],
						t->tex.x, t->tex.y);
				if ((color & 0x0000FF00) != 0)
					ft_mlx_pixel_put(&data->img_a, t->c_stripe, y, color);
			}
		}
	}
}

void	sprite_casting(t_data *data)
{
	t_sdata	s;
	int		i;
	t_stex	t;

	init_sprite_data(data, &s);
	i = -1;
	while (++i < data->sprite_count)
	{
		t.sprite.x = data->sprite[s.sprite_order[i]].pos.x - data->player.pos_x;
		t.sprite.y = data->sprite[s.sprite_order[i]].pos.y - data->player.pos_y;
		init_sprite_tex(data, &t);
		get_stripe(data, &s, &t, i);
	}
	free_sprite_data(&s);
}
