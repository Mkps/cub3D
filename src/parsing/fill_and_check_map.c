/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fill_and_check_map.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:57:08 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/20 16:07:42 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_map_is_closed(char **map, t_data *data)
{
	if (check_bottom_wall(map, data) == -1
		|| check_upper_wall(map, data) == -1
		|| check_left_wall(map, data) == -1
		|| check_right_wall(map, data) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_map_is_valid(char **map, t_data *data)
{
	(void)map;
	if (data->mapinfo.width < 3 || data->mapinfo.height < 3
		|| check_map_is_closed(data->cmap, data))
	{
		output_error(data->mapinfo.path, MAP_ERROR, EXIT_FAILURE);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	fill_map_line(int nb_whitespaces, int *i, char *file, t_data *data)
{
	static int	line = 0;
	int			j;
	int			l;

	data->cmap[line] = ft_calloc(sizeof(char), data->mapinfo.width + 1);
	j = 0;
	while (j < nb_whitespaces)
	{
		data->cmap[line][j] = ' ';
		++j;
	}
	l = -1;
	while (file[++l] && file[l] != '\n')
		data->cmap[line][j + l] = file[l];
	while (j + l < data->mapinfo.width)
	{
		data->cmap[line][j + l] = ' ';
		++l;
	}
	data->cmap[line][j + l] = '\0';
	*i += ft_strlen_eol(file) + 1;
	line++;
}

int	is_a_map_line(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 0;
	while (str[i])
	{
		if (str[i] == '1' || str[i] == '0')
			flag = 1;
		if (str[i] != '1' && str[i] != '0'
			&& str[i] != 'N' && str[i] != 'S'
			&& str[i] != 'W' && str[i] != 'E'
			&& !is_whitespace(str[i]))
			return (0);
		++i;
	}
	if (flag)
		return (1);
	return (0);
}
