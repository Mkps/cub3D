/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:34:15 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/19 17:24:53 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int parse_and_get_rgb(int *i, int flag, t_data *data)
{
	int red;
	int green;
	int blue;
	int index;

	++(*i);
	if (!data->mapinfo.file[*i] || data->mapinfo.file[*i] != ' ')
		printf("%s", SYNTAX_ERROR);

	while (data->mapinfo.file[*i] && data->mapinfo.file[*i] == ' ')
		++(*i);
			
	if (check_rgb_syntax(data->mapinfo.file + *i))
	{
		printf("%s", SYNTAX_ERROR);
		return (EXIT_FAILURE);					
	}

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