/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_file_content.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 15:18:01 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/21 12:19:52 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_data_mapinfo(char *file_name, t_data *data)
{
	data->mapinfo.file = ft_strdup("\0");
	data->mapinfo.file_size = 0;
	data->mapinfo.do_texture = NULL;
	data->mapinfo.no_texture = NULL;
	data->mapinfo.so_texture = NULL;
	data->mapinfo.ea_texture = NULL;
	data->mapinfo.we_texture = NULL;
	data->fd = safe_open(file_name);
	if (data->fd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_file_content(char *file_name, t_data *data)
{
	char	*line;
	int		line_len;
	int		max_width;
	int		map_height;

	if (init_data_mapinfo(file_name, data))
		return (EXIT_FAILURE);
	line = get_next_line(data->fd);
	max_width = ft_strlen(line);
	map_height = 0;
	while (line)
	{
		data->mapinfo.file = ft_strjoin_and_free(data->mapinfo.file, line);
		data->mapinfo.file_size += ft_strlen(line);
		if (is_a_map_line(line))
			++map_height;
		free(line);
		line = get_next_line(data->fd);
		line_len = ft_strlen(line);
		if (max_width < line_len)
			max_width = line_len;
	}
	if (safe_close(data->fd))
		return (EXIT_FAILURE);
	data->mapinfo.width = max_width;
	data->mapinfo.height = map_height;
	return (EXIT_SUCCESS);
}
