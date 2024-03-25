/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:27 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/21 14:37:53 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdlib.h>

int	parse_cardinal_pt(int *i, char *f, t_data *data)
{
	if (f[*i] == 'N' && f[*i + 1] && f[*i + 1] == 'O')
		return (get_north_texture(i, f, data));
	if (f[*i] == 'S' && f[*i + 1] && f[*i + 1] == 'O')
		return (get_south_texture(i, f, data));
	if (f[*i] == 'W' && f[*i + 1] && f[*i + 1] == 'E')
		return (get_west_texture(i, f, data));
	if (f[*i] == 'E' && f[*i + 1] && f[*i + 1] == 'A')
		return (get_east_texture(i, f, data));
	if (f[*i] == 'D' && f[*i + 1] && f[*i + 1] == 'O')
		return (get_door_texture(i, f, data));
	return (EXIT_SUCCESS);
}

int	parse_info_line(int *i, char *file, t_data *data)
{
	static int	l = 0;

	++l;
	if (parse_cardinal_pt(i, file, data))
		return (EXIT_FAILURE);
	if (parse_rgb(i, file, data))
		return (EXIT_FAILURE);
	*i += ft_strlen_eol(file + *i);
	if (file[*i])
	{
		*i += 1;
		skip_whitespaces(i, file);
	}
	return (EXIT_SUCCESS);
}

int	init_parsing(t_data *data, char *file_name)
{
	if (get_file_content(file_name, data))
		return (EXIT_FAILURE);
	if (data->mapinfo.file_size < 1)
		return (output_error(NULL, E_EMPTY_FILE, 1));
	data->checklist = (t_checklist){0};
	data->cmap = ft_calloc(sizeof(char *), data->mapinfo.height + 1);
	if (!data->cmap)
		return (output_error(NULL, E_MALLOC_CMAP, 1));
	return (EXIT_SUCCESS);
}

int	map_handler(t_data *data, int *i, int nb_whitespaces)
{
	if (data->mapinfo.file[*i] && ft_isprint(data->mapinfo.file[*i])
		&& !ft_isdigit(data->mapinfo.file[*i]))
	{
		if (data->checklist.map != 0)
			return (output_error(NULL, E_MAP_NE, 1));
		if (parse_info_line(i, data->mapinfo.file, data))
			return (EXIT_FAILURE);
	}
	else if (data->mapinfo.file[*i]
		&& ft_isdigit(data->mapinfo.file[*i]))
	{
		if (data->checklist.map > 1)
			return (output_error(NULL, E_MAP_NE, 1));
		if (fill_map_line(nb_whitespaces, i, data->mapinfo.file + *i, data))
			return (output_error(NULL, E_INIT_CMAPL, 1));
		if (data->checklist.map && data->mapinfo.file[*i] \
				&& !next_line_not_empty(((*i) + 1), data->mapinfo.file))
			data->checklist.map = 2;
	}
	else
		*i += 1;
	return (EXIT_SUCCESS);
}

int	parse_file(char *file_name, t_data *data)
{
	int	i;
	int	nb_whitespaces;

	if (init_parsing(data, file_name))
		return (EXIT_FAILURE);
	i = 0;
	while (i < data->mapinfo.file_size && data->mapinfo.file[i])
	{
		nb_whitespaces = skip_first_whitespaces(&i, data);
		if (map_handler(data, &i, nb_whitespaces))
			return (EXIT_FAILURE);
	}
	return (checklist_ok(data));
}

// int main(int argc, char **argv)
// {
// 	t_data	data;
// 	data.mapinfo.path = argv[1];
// 	if (parse_file(argv[1], &data))
// 		return (EXIT_FAILURE);
// 	if (check_paths(&data.mapinfo))
// 		return (EXIT_FAILURE);
// 	if (check_map_is_valid(data.cmap, &data))
// 		return (EXIT_FAILURE);
// 	if (search_player(data.cmap, &data))
// 		return (EXIT_FAILURE);
// 	print_info(&data);
// 	ft_free_all(&data);
// }
// int	main(int argc, char **argv)
// {
// 	t_data data;
// 	int fd;
// 	size_t file_size;
// 	// (void) argv;
// 	// (void) argc;
	// if (parse_args(argc, argv) != 0)
	// 	return (EXIT_FAILURE);
// 	fd = safe_open(argv[1]);
// 	char *line;
// 	file_size = get_file_size(fd);
// 	fd = safe_open(argv[1]);
// 	line = get_next_line(fd);
// 	data.file = ft_strjoin("\0", line);
// 	while (line)
// 	{
// 		free(line);
// 		line = get_next_line(fd);
// 		data.file = ft_strjoin_and_free(data.file, line);
// 	}
// 	printf("%s\n", data.file);
// 	// free(line);
// 	free(data.file);
// 	safe_close(fd);
// 	return (0);
// }
// int	main(int argc, char **argv)
// {
// 	t_general general;
// 	(void) argc;
// 	(void) argv;
// 	// initiate_general(&general, fd);
// 	general.height = 100;
// 	general.width = 100;
// 	open_window(&general);
// 	mlx_loop_hook(general.mlx, &render, &general);
// 	mlx_hook(general.win, KeyPress, KeyPressMask, &deal_key, &general);
// 	mlx_hook(general.win, 17, 0L, &close_win, &general);
// 	mlx_loop(general.mlx);
// 	mlx_destroy_image(general.mlx, general.img.mlx);
// 	mlx_destroy_display(general.mlx);
// 	free(general.mlx);
// 	return (0);
// }
