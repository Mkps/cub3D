/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map_walls.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:06:05 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/20 15:32:06 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_map_width(char **map, t_data *data)
{
	int	i;
	int	j;
	int	height;
	int	width;

	i = 0;
	width = 0;
	height = data->mapinfo.height;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > width)
			width = j;
		++i;
	}
	return (width);
}

int	check_upper_wall(char **map, t_data *data)
{
	int	i;
	int	j;
	int	height;

	j = 0;
	height = data->mapinfo.height;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
			return (-1);
		i = 0;
		while (i < height && map[i][j] && map[i][j] == ' ')
		{				
			++i;
			if (i < height)
			{
				if (upper_elem_not_surrounded(i, j, map))
					return (-1);
			}
		}
		++j;
	}
	return (EXIT_SUCCESS);
}

int	check_bottom_wall(char **map, t_data *data)
{
	int	i;
	int	j;
	int	end;

	end = data->mapinfo.height - 1;
	j = 0;
	while (map[end][j])
	{
		i = end;
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (-1);
		while (i >= 0 && map[i][j] && map[i][j] == ' ')
		{				
			--i;
			if (i >= 0)
			{
				if (bottom_elem_not_surrounded(i, j, map))
					return (-1);
			}
		}
		++j;
	}
	return (EXIT_SUCCESS);
}

int	check_left_wall(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (i < data->mapinfo.height && map[i][j])
	{
		j = 0;
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (-1);
		while (i < data->mapinfo.height && map[i][j] && map[i][j] == ' ')
		{				
			++j;
			if (map[i][j])
			{
				if (left_elem_not_surrounded(i, j, map))
					return (-1);
			}
		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int	check_right_wall(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	j = data->mapinfo.width - 2;
	while (i < data->mapinfo.height && map[i][j])
	{
		j = data->mapinfo.width - 2;
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (-1);
		while (i < data->mapinfo.height && map[i][j] && map[i][j] == ' ')
		{				
			--j;
			if (map[i][j])
			{
				if (right_elem_not_surrounded(i, j, map))
					return (-1);
			}
		}
		++i;
	}
	return (EXIT_SUCCESS);
}
