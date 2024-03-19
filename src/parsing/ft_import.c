/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_import.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:06:47 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 14:05:20 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

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
	while (++i < data->m_data.height)
	{
		j = -1;
		while (++j < data->m_data.width)
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
	data->map = malloc(sizeof (int *) * data->m_data.height);
	if (!data->map)
		return (output_error(NULL, "Failed to malloc int map", 1));
	while (++i < data->m_data.height)
	{
		data->map[i] = malloc(sizeof(int) * data->m_data.width);
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
	i = -1;
	while (data->cmap[++i])
	{
		j = -1;
		while (data->cmap[i][++j])
			data->map[i][j] = chr_convert(data->cmap[i][j]);
		while (j < data->m_data.width)
		{
			data->map[i][j] = -42;
			j++;
		}
	}
	return (EXIT_SUCCESS);
}

int	ft_import(char **argv, t_data *data)
{
	if (check_file(argv[1], 1) == EXIT_FAILURE)
		ft_mlx_exit(data, EXIT_FAILURE);
	if (parse_data(argv[1], data) == EXIT_FAILURE)
		ft_mlx_exit(data, EXIT_FAILURE);
	if (get_file_data(data, data->m_data.file) == EXIT_FAILURE)
		return (ft_exit_cleanup(data, EXIT_FAILURE));
	if (check_map_validity(data, data->cmap) == EXIT_FAILURE)
		return (ft_exit_cleanup(data, EXIT_FAILURE));
	if (check_textures_validity(data, &data->world) == EXIT_FAILURE)
		return (ft_exit_cleanup(data, EXIT_FAILURE));
	if (map_convert(data) == EXIT_FAILURE)
		return (ft_exit_cleanup(data, EXIT_FAILURE));
	return (0);
}
