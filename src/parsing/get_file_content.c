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

static int	is_dir(char *arg)
{
	int	fd;
	int	ret;

	ret = 0;
	fd = open(arg, O_DIRECTORY);
	if (fd >= 0)
	{
		close (fd);
		ret = 1;
	}
	return (ret);
}

static int	is_cub(char *arg)
{
	size_t	len;

	len = ft_strlen(arg);
	if (len <= 4)
		return (0);
	if ((arg[len - 4] != '.' || arg[len - 3] != 'c'
			|| arg[len - 2] != 'u'
			|| arg[len - 1] != 'b'))
		return (0);
	return (1);
}

int	init_data_mapinfo(char *file_name, t_data *data)
{
	data->mapinfo.file = ft_strdup("\0");
	data->mapinfo.file_size = 0;
	data->mapinfo.do_texture = NULL;
	data->mapinfo.no_texture = NULL;
	data->mapinfo.so_texture = NULL;
	data->mapinfo.ea_texture = NULL;
	data->mapinfo.we_texture = NULL;
	if (!is_cub(file_name))
		return (output_error(file_name, "not a .cub file", 1));
	if (is_dir(file_name))
		return (output_error(file_name, "is a directory", 1));
	data->fd = safe_open(file_name);
	if (data->fd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	get_file_content(char *file_name, t_data *data)
{
	char	*line;
	int		line_len;

	if (init_data_mapinfo(file_name, data))
		return (EXIT_FAILURE);
	line = get_next_line(data->fd);
	data->mapinfo.width = ft_strlen(line);
	data->mapinfo.height = 0;
	while (line)
	{
		data->mapinfo.file = ft_strjoin_and_free(data->mapinfo.file, line);
		data->mapinfo.file_size += ft_strlen(line);
		if (is_a_map_line(line))
			++data->mapinfo.height;
		free(line);
		line = get_next_line(data->fd);
		line_len = ft_strlen(line);
		if (data->mapinfo.width < line_len)
			data->mapinfo.width = line_len;
	}
	return (safe_close(data->fd));
}
