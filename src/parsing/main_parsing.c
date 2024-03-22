/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:27 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/22 14:19:48 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"
#include <stdlib.h>

int	parse_map_line(int nb_whitespaces, t_data *data)
{
	if (data->checklist.map > 1)
		return (EXIT_FAILURE);
	fill_map_line(nb_whitespaces, &i,
		data->mapinfo.file + i, data);
	if (data->checklist.map && data->mapinfo.file[i]
		&& !next_line_not_empty(i + 1, data->mapinfo.file))
		data->checklist.map = 2;
	return (EXIT_SUCCESS);
}

static int	is_an_info_line(int i, t_data *data)
{
	if (data->mapinfo.file[i]
		&& ft_isprint(data->mapinfo.file[i])
		&& !ft_isdigit(data->mapinfo.file[i]))
		return (1);
	return (0);
}

static int	is_map(int i, t_data *data)
{
	if (data->mapinfo.file[i]
		&& ft_isdigit(data->mapinfo.file[i]))
		return (1);
	return (0);
}

int	parse_file(char *file_name, t_data *data)
{
	int	i;
	int	nb_whitespaces;

	if (get_file_content(file_name, data))
		return (output_error(NULL, OPEN_FD_ERROR, 1));
	if (data->mapinfo.file_size < 1)
		return (output_error(NULL, E_EMPTY_FILE, 1));
	data->checklist = (t_checklist){0};
	i = 0;
	data->cmap = ft_calloc(sizeof(char *), data->mapinfo.height + 1);
	while (i < data->mapinfo.file_size && data->mapinfo.file[i])
	{
		nb_whitespaces = skip_first_whitespaces(&i, data);
		if (is_an_info_line(i, data)
			&& parse_info_line(&i, data->mapinfo.file, data))
			return (EXIT_FAILURE);
		else if (is_map(i, data)
			&& parse_map_line(nb_whitespaces, data))
			return (output_error(NULL, "Character after map end", 1));
		else
			++i;
	}
	if (checklist_ok(data))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
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
