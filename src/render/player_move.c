/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:42:54 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 12:20:47 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	rotate_right(t_data *data);
void	rotate_left(t_data *data);

static void	move_forward(t_data *data)
{
	double	m_x;
	double	m_y;
	t_point	map;

	m_x = data->player.pos_x + data->player.dir_x * 3 * MS;
	m_y = data->player.pos_y + data->player.dir_y * 3 * MS;
	if (m_x < 0.25 || m_x > data->m_data.height - 0.25
		|| m_y < 0.25 || m_y > data->m_data.width - 0.25)
		return ;
	map.x = data->map[(int)m_x][(int)(data->player.pos_y)];
	map.y = data->map[(int)(data->player.pos_x)][(int)m_y];
	if (map.x == 0 || (!BONUS && map.x == 1) || (BONUS && map.x == e_o))
		data->player.pos_x += data->player.dir_x * MS;
	if (map.y == 0 || (!BONUS && map.y == 1) || (BONUS && map.y == e_o))
		data->player.pos_y += data->player.dir_y * MS;
}

static void	move_backward(t_data *data)
{
	double	m_x;
	double	m_y;
	t_point	map;

	m_x = data->player.pos_x - data->player.dir_x * 3 * MS;
	m_y = data->player.pos_y - data->player.dir_y * 3 * MS;
	if (m_x < 0.25 || m_x > data->m_data.height - 0.25
		|| m_y < 0.25 || m_y > data->m_data.width - 0.25)
		return ;
	map.x = data->map[(int)m_x][(int)(data->player.pos_y)];
	map.y = data->map[(int)(data->player.pos_x)][(int)m_y];
	if (map.x == 0 || (!BONUS && map.x == 1) || (BONUS && map.x == e_o))
		data->player.pos_x -= data->player.dir_x * MS;
	if (map.y == 0 || (!BONUS && map.y == 1) || (BONUS && map.y == e_o))
		data->player.pos_y -= data->player.dir_y * MS;
}

static void	move_right(t_data *data)
{
	double	m_x;
	double	m_y;
	t_point	map;

	m_x = data->player.pos_x + data->plane.x * 3 * MS;
	m_y = data->player.pos_y + data->plane.y * 3 * MS;
	if (m_x < 0.25 || m_x > data->m_data.height - 0.25
		|| m_y < 0.25 || m_y > data->m_data.width - 0.25)
		return ;
	map.x = data->map[(int)m_x][(int)(data->player.pos_y)];
	map.y = data->map[(int)(data->player.pos_x)][(int)m_y];
	if (map.x == 0 || (!BONUS && map.x == 1) || (BONUS && map.x == e_o))
		data->player.pos_x += data->plane.x * MS;
	if (map.y == 0 || (!BONUS && map.y == 1) || (BONUS && map.y == e_o))
		data->player.pos_y += data->plane.y * MS;
}

static void	move_left(t_data *data)
{
	double	m_x;
	double	m_y;
	t_point	map;

	m_x = data->player.pos_x - data->plane.x * 3 * MS;
	m_y = data->player.pos_y - data->plane.y * 3 * MS;
	if (m_x < 0.25 || m_x > data->m_data.height - 0.25
		|| m_y < 0.25 || m_y > data->m_data.width - 0.25)
		return ;
	map.x = data->map[(int)m_x][(int)(data->player.pos_y)];
	map.y = data->map[(int)(data->player.pos_x)][(int)m_y];
	if (map.x == 0 || (!BONUS && map.x == 1) || (BONUS && map.x == e_o))
		data->player.pos_x -= data->plane.x * MS;
	if (map.y == 0 || (!BONUS && map.y == 1) || (BONUS && map.y == e_o))
		data->player.pos_y -= data->plane.y * MS;
}

void	move_player(t_data *data)
{
	if (data->keys.w)
		move_forward(data);
	if (data->keys.s)
		move_backward(data);
	if (data->keys.a)
		move_left(data);
	if (data->keys.d)
		move_right(data);
	if (data->keys.l)
		rotate_left(data);
	if (data->keys.r)
		rotate_right(data);
	if (data->keys.l != 1)
		data->keys.l = 0;
	if (data->keys.r != 1)
		data->keys.r = 0;
}