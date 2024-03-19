/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:43:55 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/11 14:00:28 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"
#include <stdint.h>

void	ft_key_movement(int key, t_data *data)
{
	if (key == 'd')
		data->keys.d = 1;
	if (key == 'a')
		data->keys.a = 1;
	if (key == 'w' || key == 65362)
		data->keys.w = 1;
	if (key == 's' || key == 65364)
		data->keys.s = 1;
	if (key == 65361)
		data->keys.l = 1;
	if (key == 65363)
		data->keys.r = 1;
	if (key == 'e' && BONUS >= 1)
		open_door(data);
}

int	ft_keyup(int key, t_data *data)
{
	if (key == 'd')
		data->keys.d = 0;
	if (key == 'a')
		data->keys.a = 0;
	if (key == 'w' || key == 65362)
		data->keys.w = 0;
	if (key == 's' || key == 65364)
		data->keys.s = 0;
	if (key == 65361)
		data->keys.l = 0;
	if (key == 65363)
		data->keys.r = 0;
	return (0);
}
