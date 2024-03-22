/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:30:43 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/22 14:21:15 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	upper_elem_not_surrounded(int i, int j, char **map)
{
	if ((map[i][j]
		&& (map[i][j] != ' ' && map[i][j] != '1'))
		|| ((map[i][j] && map[i][j] != '1'
			&& map[i][j + 1] && map[i][j + 1] != '1'
			&& map[i][j + 1] != ' ')
		|| (map[i][j] && map[i][j] != '1' && j > 1 && map[i][j - 1]
			&& map[i][j - 1] != '1' && map[i][j - 1] != ' ')))
		return (1);
	return (0);
}

int	bottom_elem_not_surrounded(int i, int j, char **map)
{
	if ((map[i][j]
		&& (map[i][j] != ' ' && map[i][j] != '1'))
		|| ((map[i][j] && map[i][j] != '1'
			&& map[i][j + 1] && map[i][j + 1] != '1'
			&& map[i][j + 1] != ' ')
		|| (map[i][j] && map[i][j] != '1' && j > 1
			&& map[i][j - 1] && map[i][j - 1] != '1'
			&& map[i][j - 1] != ' ')))
		return (1);
	return (0);
}

int	left_elem_not_surrounded(int i, int j, char **map, int height)
{
	if ((map[i][j] != ' ' && map[i][j] != '1')
		|| ((map[i][j] && map[i][j] != '1'
			&& i > 0 && map[i - 1][j]
			&& map[i - 1][j] != '1'
			&& map[i - 1][j] != ' ')
		|| (map[i][j] && map[i][j] != '1'
			&& i < height - 1 && map[i + 1][j]
			&& map[i + 1][j] != '1'
			&& map[i + 1][j] != ' ')))
		return (1);
	return (0);
}

int	right_elem_not_surrounded(int i, int j, char **map, int height)
{
	if ((map[i][j] != ' ' && map[i][j] != '1')
		|| ((map[i][j] && map[i][j] != '1'
			&& i > 0 && map[i - 1][j]
			&& map[i - 1][j] != '1'
			&& map[i - 1][j] != ' ')
		|| (map[i][j] && map[i][j] != '1'
			&& i < height - 1 && map[i + 1][j]
			&& map[i + 1][j] != '1'
			&& map[i + 1][j] != ' ')))
		return (1);
	return (0);
}
