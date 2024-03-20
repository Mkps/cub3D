/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_player_info.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:52:56 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/20 13:56:54 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	get_player_info_cont(int i, int j, char **map, t_data *data)
{
	if (map[i][j] == 'E')
	{
		data->player.dir_x = 0.0;
		data->player.dir_y = 1.0;
		data->plane.x = 0.66;
		data->plane.y = 0.0;
	}
	else if (map[i][j] == 'W')
	{
		data->player.dir_x = 0.0;
		data->player.dir_y = -1.0;
		data->plane.x = -0.66;
		data->plane.y = 0.0;
	}	
}

int	get_player_info(int i, int j, char **map, t_data *data)
{
	if (data->checklist.check_dir == 1)
		return (print_error(DUPLICATE_ERROR));
	data->checklist.check_dir = 1;
	data->player.pos_x = i + 0.5;
	data->player.pos_y = j + 0.5;
	if (map[i][j] == 'N')
	{
		data->player.dir_x = -1.0;
		data->player.dir_y = 0.0;
		data->plane.x = 0.0;
		data->plane.y = 0.66;
	}
	else if (map[i][j] == 'S')
	{
		data->player.dir_x = 1.0;
		data->player.dir_y = 0.0;
		data->plane.x = 0.0;
		data->plane.y = -0.66;
	}
	else
		get_player_info_cont(i, j, map, data);
	return (EXIT_SUCCESS);
}

int	search_player(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->checklist = (t_checklist){0};
	while (i < data->mapinfo.height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N' || map[i][j] == 'S'
				|| map[i][j] == 'E' || map[i][j] == 'W')
			{
				if (get_player_info(i, j, map, data))
					return (EXIT_FAILURE);
			}
			++j;
		}
		++i;
	}
	if (!data->checklist.check_dir)
		return (print_error(NO_PLAYER_ERROR));
	return (EXIT_SUCCESS);
}
