/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_parsing.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:27 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/19 11:44:04 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"
#include "../../libft/libft.h"

uint32_t ft_rgb_to_uint32(int red, int green, int blue)
{
    return ((uint32_t)red << 16) | ((uint32_t)green << 8) | blue;
}

int get_file_content(char *file_name, t_data *data)
{
	char *line;
	int		max_width;
	int		line_len;
	int		map_height;

	data->fd = safe_open(file_name);
	if (data->fd == -1)
		return (EXIT_FAILURE);
	data->mapinfo->file = ft_strdup("\0");
	data->mapinfo->file_size = 0;
	data->mapinfo->file_nb_lines = 0;
	line = get_next_line(data->fd);
	max_width = ft_strlen(line);
	map_height = 0;
	while (line)
	{
		data->mapinfo->file = ft_strjoin_and_free(data->mapinfo->file, line);
		data->mapinfo->file_size += ft_strlen(line);
		if (ft_isdigit(line[0]))
			++map_height;
		free(line);
		line = get_next_line(data->fd);
		line_len = ft_strlen(line);
		if (max_width < line_len)
			max_width = line_len;
	}
	safe_close(data->fd);
	data->mapinfo->width = max_width;
	data->mapinfo->height = map_height;
	// printf("WIDTH = %d\nHEIGHT = %d\n", max_width, nb_lines);
	return (EXIT_SUCCESS);
}

int	print_error(char *error_message)
{
	printf("%s\n", error_message);
	return (EXIT_FAILURE);
}

int parse_cardinal_pt(int *i, char *file, t_data *data)
{
	if (file[*i] == 'N' && file[*i + 1] && file[*i + 1] == 'O')
	{
		if (data->checklist.check_no)
			return (print_error(DUPLICATE_ERROR));
		data->checklist.check_no = 1;
		*i += 2;
		if (!file[*i] || file[*i] != ' ')
			return (print_error(SYNTAX_ERROR));
		while (file[*i] == ' ')
			++(*i);
		data->mapinfo->no_texture = ft_substr(file + *i, 0, ft_strlen_eol(file + *i));
	}

	else if (file[*i] == 'S' && file[*i + 1] && file[*i + 1] == 'O')
	{
		if (data->checklist.check_so)
			return (print_error(DUPLICATE_ERROR));
		data->checklist.check_so = 1;
		*i += 2;
		if (!file[*i] || file[*i] != ' ')
			return (print_error(SYNTAX_ERROR));
		while (file[*i] == ' ')
			++(*i);
		data->mapinfo->so_texture = ft_substr(file + *i, 0, ft_strlen_eol(file + *i));
	}

	else if (file[*i] == 'W' && file[*i + 1] && file[*i + 1] == 'E')
	{
		if (data->checklist.check_we)
			return (print_error(DUPLICATE_ERROR));
		data->checklist.check_we = 1;
		*i += 2;
		if (!file[*i] || file[*i] != ' ')
			return (print_error(SYNTAX_ERROR));
		
		while (file[*i] == ' ')
			++(*i);
		
		data->mapinfo->we_texture = ft_substr(file + *i, 0, ft_strlen_eol(file + *i));
		
	}

	else if (file[*i] == 'E' && file[*i + 1] && file[*i + 1] == 'A')
	{
		if (data->checklist.check_ea)
			return (print_error(DUPLICATE_ERROR));
		data->checklist.check_ea = 1;
		*i += 2;
		if (!file[*i] || file[*i] != ' ')
			return (print_error(SYNTAX_ERROR));
		while (file[*i] == ' ')
			++(*i);
		data->mapinfo->ea_texture = ft_substr(file + *i, 0, ft_strlen_eol(file + *i));
		
	}

	return (EXIT_SUCCESS);	
}

int parse_rgb(int *i, char *file, t_data *data)
{
	if (file[*i] == 'F')
	{
		if (data->checklist.floor)
			return (print_error(DUPLICATE_ERROR));
		data->checklist.floor = 1;
		if (parse_and_get_rgb(i, FLOOR, data))
			return (EXIT_FAILURE);
		// *i += ft_strlen_eol(data->mapinfo->file + *i) + 1;
		

	}

	else if (file[*i] == 'C')
	{
		if (data->checklist.ceiling)
			return (print_error(DUPLICATE_ERROR));
		data->checklist.ceiling = 1;
		if (parse_and_get_rgb(i, CEILING, data))
			return (EXIT_FAILURE);
		// *i += ft_strlen_eol(data->mapinfo->file + *i) + 1;
		
	}
	return (EXIT_SUCCESS);
}

int	fill_map_line(int *i, char *file, t_data *data)
{
	static int line = 0;

	data->mapinfo->map[line] = malloc(sizeof(char) * data->mapinfo->width + 1);
	
	int j = 0;
	while (file[j] && file[j] != '\n')
	{
		data->mapinfo->map[line][j] = file[j];
		++j;
	}
	while (j < data->mapinfo->width)
	{
		data->mapinfo->map[line][j] = ' ';
		++j;
	}
	data->mapinfo->map[line][j] = '\0';
	*i += ft_strlen_eol(file) + 1;
	line++;
	return (line);
}

int	parse_file(char *file_name, t_data *data)
{
	int	i;
	int nb_lines;
		
	get_file_content(file_name, data);

	data->checklist = (t_checklist){0};
	// data->mapinfo->map = (char **){0};
	i = 0;

	data->mapinfo->map = malloc(sizeof(char *) * data->mapinfo->height + 1);
	data->mapinfo->map[0] = NULL;
	
	while (data->mapinfo->file[i])
	{
		if (ft_isprint(data->mapinfo->file[i]) && !ft_isdigit(data->mapinfo->file[i]))
		{
			if (parse_cardinal_pt(&i, data->mapinfo->file, data))
				return (EXIT_FAILURE);

			if (parse_rgb(&i, data->mapinfo->file, data))
				return (EXIT_FAILURE);
				
			i += ft_strlen_eol(data->mapinfo->file + i) + 1;
		}
		else if (ft_isdigit(data->mapinfo->file[i]))
			nb_lines = fill_map_line(&i, data->mapinfo->file + i, data);
		else
			i++;
	}
	return (EXIT_SUCCESS);
}



int	get_player_info(char **map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	data->checklist = (t_checklist){0};
	while (i < data->mapinfo->height)
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'N')
			{
				if (data->checklist.check_dir == 1)
					return (print_error(DUPLICATE_ERROR));
				data->checklist.check_dir = 1;
				data->player->dir = NORTH;
				data->player->x = i + 0.5;
				data->player->y = j + 0.5;
			}
			else if (map[i][j] == 'S')
			{
				if (data->checklist.check_dir == 1)
					return (print_error(DUPLICATE_ERROR));
				data->checklist.check_dir = 1;
				data->player->dir = SOUTH;
				data->player->x = i + 0.5;
				data->player->y = j + 0.5;
			}
			else if (map[i][j] == 'E')
			{
				if (data->checklist.check_dir == 1)
					return (print_error(DUPLICATE_ERROR));
				data->checklist.check_dir = 1;
				data->player->dir = EAST;
				data->player->x = i + 0.5;
				data->player->y = j + 0.5;
			}
			else if (map[i][j] == 'W')
			{
				if (data->checklist.check_dir == 1)
					return (print_error(DUPLICATE_ERROR));
				data->checklist.check_dir = 1;
				data->player->dir = WEST;
				data->player->x = i + 0.5;
				data->player->y = j + 0.5;
			}
			j++;
		}
		i++;
	}
	if (!data->checklist.check_dir)
		return (print_error(NO_PLAYER_ERROR));
	return (EXIT_SUCCESS);
}


int	parse_args(int argc, char **argv)
{
	if (argc != 2)
	{
		printf("%s", ARG_ERROR);
		return (EXIT_FAILURE);		
	}
	return (EXIT_SUCCESS);
}

int check_map_is_valid(char **map, t_data *data)
{
	if (data->mapinfo->width < 3 || data->mapinfo->height < 3
		|| check_map_is_closed(data->mapinfo->map, data))
	{
		printf("%s", MAP_ERROR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ft_free_textures(t_data *data)
{
	if (data->mapinfo->no_texture)
		free(data->mapinfo->no_texture);
	if (data->mapinfo->so_texture)
		free(data->mapinfo->so_texture);
	if (data->mapinfo->ea_texture)
		free(data->mapinfo->ea_texture);
	if (data->mapinfo->we_texture)
		free(data->mapinfo->we_texture);	
}

void	ft_free_all(t_data *data)
{
	int i;

	ft_free_textures(data);

	i = 0;
	if (data->mapinfo->map[0])
	{	
		while (i < data->mapinfo->height)
		{
			free(data->mapinfo->map[i]);
			++i;
		}
	}
	if (data->mapinfo->map)
		free(data->mapinfo->map);
	if (data->mapinfo->file)
		free(data->mapinfo->file);
	free(data->mapinfo);
	free(data->player);	
}

int main(int argc, char **argv)
{
	t_data data;

	data = (t_data){0};
	
	data.mapinfo = (t_mapinfo *){0};

	data.mapinfo = malloc(sizeof(t_mapinfo));
	data.player = malloc(sizeof(t_player));
	

	if (parse_args(argc, argv))
	{
		ft_free_all(&data);
		return (EXIT_FAILURE);
	}

	if (parse_file(argv[1], &data))
	{
		ft_free_all(&data);
		return (EXIT_FAILURE);
	}

	if (check_paths(data.mapinfo))
	{
		ft_free_all(&data);
		return (EXIT_FAILURE);
	}
	

	if (check_map_is_valid(data.mapinfo->map, &data))
	{
		ft_free_all(&data);
		return (EXIT_FAILURE);
	}

	if (get_player_info(data.mapinfo->map, &data))
	{
		ft_free_all(&data);
		return (EXIT_FAILURE);
	}
	
	print_info(data);

	ft_free_all(&data);

}

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