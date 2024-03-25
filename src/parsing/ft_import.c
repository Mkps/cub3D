/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:06:47 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/20 15:49:25 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdlib.h>

int	chr_convert(char c)
{
	if (c == '0')
		return (0);
	if (c == '1')
		return (1);
	if (c == 'O')
		return (e_o);
	if (c == 'D')
		return (e_d);
	return (-42);
}

static void	free_map(t_data *data, int current_index)
{
	int	x;

	x = -1;
	if (data->map)
	{
		while (++x < current_index)
		{
			free(data->map[x]);
		}
		free(data->map);
		data->map = NULL;
	}
}

/**
static void	print_map(t_data *data)
{
	int	i;
	int	j;

	i = -1;
	while (++i < data->mapinfo.height)
	{
		j = -1;
		while (++j < data->mapinfo.width)
		{
			if (data->map[i][j] == -42)
				printf("|x|");
			else
				printf("|%i|",data->map[i][j]);
		}
		printf("\n");
	}
}
*/

int	map_alloc(t_data *data)
{
	int	i;

	i = -1;
	data->map = malloc(sizeof (int *) * data->mapinfo.height);
	if (!data->map)
		return (output_error(NULL, "Failed to malloc int map", 1));
	while (++i < data->mapinfo.height)
	{
		data->map[i] = malloc(sizeof(int) * data->mapinfo.width);
		if (!data->map[i])
		{
			free_map(data, i);
			return (output_error(NULL, "Failed to malloc int tab", 1));
		}
	}
	return (EXIT_SUCCESS);
}

int	map_convert(t_data *data)
{
	int	i;
	int	j;

	if (map_alloc(data) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	spacehandler(data);
	i = -1;
	while (data->cmap[++i])
	{
		j = -1;
		while (data->cmap[i][++j])
		{
			if (data->cmap[i][j] == 'D')
				data->mapinfo.has_door = 1;
			data->map[i][j] = chr_convert(data->cmap[i][j]);
		}
		while (j < data->mapinfo.width)
		{
			data->map[i][j] = -42;
			j++;
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_import(char **argv, t_data *data)
{
	if (parse_file(argv[1], data) == EXIT_FAILURE)
		ft_mlx_exit(data, EXIT_FAILURE);
	if (check_paths(&data->mapinfo) == EXIT_FAILURE)
		return (ft_exit_cleanup(data, EXIT_FAILURE));
	if (check_map_is_valid(data->cmap, data) == EXIT_FAILURE)
		return (ft_exit_cleanup(data, EXIT_FAILURE));
	if (search_player(data->cmap, data))
		return (ft_exit_cleanup(data, EXIT_FAILURE));
	if (BONUS)
	{
		if (init_data_sprite(data))
			return (ft_exit_cleanup(data, EXIT_FAILURE));
	}
	if (map_convert(data) == EXIT_FAILURE)
		return (ft_exit_cleanup(data, EXIT_FAILURE));
	if (load_textures(data))
		return (ft_exit_cleanup(data, EXIT_FAILURE));
	return (0);
}
