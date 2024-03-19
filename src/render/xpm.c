/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   xpm.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:43:55 by aloubier          #+#    #+#             */
/*   Updated: 2023/12/21 18:51:23 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

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
