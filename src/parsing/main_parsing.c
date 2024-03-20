/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:27 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/20 14:46:25 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	init_data_mapinfo(char *file_name, t_data *data)
{
	data->fd = safe_open(file_name);
	if (data->fd == -1)
		return (EXIT_FAILURE);
	data->mapinfo.file = ft_strdup("\0");
	data->mapinfo.file_size = 0;
	return (EXIT_SUCCESS);
}

int	get_file_content(char *file_name, t_data *data)
{
	char	*line;
	int		line_len;
	int		max_width;
	int		map_height;

	init_data_mapinfo(file_name, data);
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
	safe_close(data->fd);
	data->mapinfo.width = max_width;
	data->mapinfo.height = map_height;
	return (EXIT_SUCCESS);
}


int	parse_cardinal_pt(int *i, char *file, t_data *data)
{
	if (file[*i] == 'N' && file[*i + 1] && file[*i + 1] == 'O')
	{
		if (data->checklist.check_no)
			return (output_error(NULL, DUPLICATE_ERROR, 1));
		data->checklist.check_no = 1;
		*i += 2;
		if (!file[*i] || !is_whitespace(file[*i]))
			return (output_error(NULL, SYNTAX_ERROR, 1));
		while (is_whitespace(file[*i]))
			++(*i);
		data->mapinfo.no_texture = ft_substr(file + *i, 0,
				ft_strlen_eol(file + *i));
	}
	else if (file[*i] == 'S' && file[*i + 1]
		&& file[*i + 1] == 'O')
	{
		if (data->checklist.check_so)
			return (output_error(NULL, DUPLICATE_ERROR, 1));
		data->checklist.check_so = 1;
		*i += 2;
		if (!file[*i] || !is_whitespace(file[*i]))
			return (output_error(NULL, SYNTAX_ERROR, 1));
		while (is_whitespace(file[*i]))
			++(*i);
		data->mapinfo.so_texture = ft_substr(file + *i, 0,
				ft_strlen_eol(file + *i));
	}
	else if (file[*i] == 'W' && file[*i + 1]
		&& file[*i + 1] == 'E')
	{
		if (data->checklist.check_we)
			return (output_error(NULL, DUPLICATE_ERROR, 1));
		data->checklist.check_we = 1;
		*i += 2;
		if (!file[*i] || !is_whitespace(file[*i]))
			return (output_error(NULL, SYNTAX_ERROR, 1));
		while (is_whitespace(file[*i]))
			++(*i);
		data->mapinfo.we_texture = ft_substr(file + *i,
				0, ft_strlen_eol(file + *i));
	}
	else if (file[*i] == 'E' && file[*i + 1]
		&& file[*i + 1] == 'A')
	{
		if (data->checklist.check_ea)
			return (output_error(NULL, DUPLICATE_ERROR, 1));
		data->checklist.check_ea = 1;
		*i += 2;
		if (!file[*i] || !is_whitespace(file[*i]))
			return (output_error(NULL, SYNTAX_ERROR, 1));
		while (is_whitespace(file[*i]))
			++(*i);
		data->mapinfo.ea_texture = ft_substr(file + *i,
				0, ft_strlen_eol(file + *i));
	}
	return (EXIT_SUCCESS);
}

int	next_line_not_empty(int i, char *file)
{
	while (file[i] && file[i] != '\n')
	{
		if (file[i] == '1')
			return (1);
		++i;
	}
	return (0);
}

void	skip_whitespaces(int *i, char *file)
{
	while (file[*i])
	{
		if (file[*i] == '\n'
			&& next_line_not_empty(*i, file + *i + 1))
			return ;
		else if (is_whitespace(file[*i]))
			++(*i);
	}
}

int	parse_file(char *file_name, t_data *data)
{
	int	i;
	int	j;
	int	nb_whitespaces;
	int	nb_lines;

	get_file_content(file_name, data);
	data->checklist = (t_checklist){0};
	i = 0;
	nb_whitespaces = 0;
	data->cmap = ft_calloc(sizeof(char *), data->mapinfo.height + 1);
	while (data->mapinfo.file[i])
	{
		nb_whitespaces = 0;
		while (data->mapinfo.file[i] && is_whitespace(data->mapinfo.file[i]))
		{
			++nb_whitespaces;
			++i;
		}
		if (data->mapinfo.file[i]
			&& ft_isprint(data->mapinfo.file[i])
			&& !ft_isdigit(data->mapinfo.file[i]))
		{
			if (parse_cardinal_pt(&i, data->mapinfo.file, data))
				return (EXIT_FAILURE);
			if (parse_rgb(&i, data->mapinfo.file, data))
				return (EXIT_FAILURE);
			i += ft_strlen_eol(data->mapinfo.file + i) + 1;
			skip_whitespaces(&i, data->mapinfo.file);
		}
		else if (data->mapinfo.file[i]
			&& ft_isdigit(data->mapinfo.file[i]))
			nb_lines = fill_map_line(nb_whitespaces,
					&i, data->mapinfo.file + i, data);
		else
			++i;
	}
	j = 0;
	while (data->cmap[j])
	{
		printf("%s\n", data->cmap[j]);
		j++;
	}
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
