/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:34:15 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/20 13:52:32 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	ft_rgb_to_int(int red, int green, int blue)
{
	return (((int)red << 16) | ((int)green << 8) | blue);
}

int parse_and_get_rgb(int *i, int flag, t_data *data)
{
	int red;
	int green;
	int blue;
	int index;

	++(*i);
	if (!data->mapinfo.file[*i] || !is_whitespace(data->mapinfo.file[*i]))
        return (output_error(data->mapinfo.file, SYNTAX_ERROR, 1)); 

	while (data->mapinfo.file[*i] && is_whitespace(data->mapinfo.file[*i]))
		++(*i);
			
	if (check_rgb_syntax(data->mapinfo.file + *i))
        return (output_error(data->mapinfo.file, SYNTAX_ERROR, 1)); 
	index = *i;
	red = ft_atoi_rgb(data->mapinfo.file + index, &index);
	green = ft_atoi_rgb(data->mapinfo.file + index, &index);
	blue = ft_atoi_rgb(data->mapinfo.file + index, &index);


	if (check_rgb_values(red, green, blue))
		return(print_error(RGB_VALUE_ERROR));
	if (flag == FLOOR)
		data->mapinfo.f_color = ft_rgb_to_int(red, green, blue);
	else if (flag == CEILING)
		data->mapinfo.c_color = ft_rgb_to_int(red, green, blue);
	return (EXIT_SUCCESS);
}

int	parse_rgb(int *i, char *file, t_data *data)
{
	if (file[*i] == 'F')
	{
		if (data->checklist.floor)
			return (output_error(NULL, DUPLICATE_ERROR, 1));
		data->checklist.floor = 1;
		if (parse_and_get_rgb(i, FLOOR, data))
			return (EXIT_FAILURE);
	}
	else if (file[*i] == 'C')
	{
		if (data->checklist.ceiling)
			return (output_error(NULL, DUPLICATE_ERROR, 1));
		data->checklist.ceiling = 1;
		if (parse_and_get_rgb(i, CEILING, data))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}