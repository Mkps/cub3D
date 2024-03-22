/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_info_line.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:19:16 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/22 16:01:27 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	parse_cardinal_pt_cont(int *i, char *file, t_data *data)
{
	if (file[*i] == 'W' && file[*i + 1]
		&& file[*i + 1] == 'E')
	{
		if (get_west_texture(i, file, data))
			return (EXIT_FAILURE);
	}
	else if (file[*i] == 'E' && file[*i + 1]
		&& file[*i + 1] == 'A')
	{
		if (get_east_texture(i, file, data))
			return (EXIT_FAILURE);
	}
	else if (file[*i] == 'D' && file[*i + 1]
		&& file[*i + 1] == 'O')
	{
		if (get_door_texture(i, file, data))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_cardinal_pt(int *i, char *file, t_data *data)
{
	if (file[*i] == 'N' && file[*i + 1] && file[*i + 1] == 'O')
	{
		if (get_north_texture(i, file, data))
			return (EXIT_FAILURE);
	}
	else if (file[*i] == 'S' && file[*i + 1]
		&& file[*i + 1] == 'O')
	{
		if (get_south_texture(i, file, data))
			return (EXIT_FAILURE);
	}
	else
	{
		if (parse_cardinal_pt_cont(i, file, data))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	parse_info_line(int *i, char *file, t_data *data)
{
	static int	l = 0;

	if (data->checklist.map != 0)
		return (output_error(NULL, "Character after map", 1));
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
