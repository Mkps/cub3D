/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_rgb.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 14:34:15 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/19 11:44:07 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"
#include "../../libft/libft.h"


int parse_and_get_rgb(int *i, int flag, t_data *data)
{
	int red;
	int green;
	int blue;
	int index;

	++(*i);
	if (!data->mapinfo->file[*i] || data->mapinfo->file[*i] != ' ')
		printf("%s", SYNTAX_ERROR);

	while (data->mapinfo->file[*i] && data->mapinfo->file[*i] == ' ')
		++(*i);
			
	if (check_rgb_syntax(data->mapinfo->file + *i))
	{
		printf("%s", SYNTAX_ERROR);
		return (EXIT_FAILURE);					
	}

	index = *i;
	red = ft_atoi_rgb(data->mapinfo->file + index, &index);
	green = ft_atoi_rgb(data->mapinfo->file + index, &index);
	blue = ft_atoi_rgb(data->mapinfo->file + index, &index);
			
	if (check_rgb_values(red, green, blue))
	{
		printf("Error : wrong RGB values for the floor\n");
		return (EXIT_FAILURE);						
	}
	if (flag == FLOOR)
		data->mapinfo->f_color = ft_rgb_to_uint32(red, green, blue);
	else if (flag == CEILING)
		data->mapinfo->c_color = ft_rgb_to_uint32(red, green, blue);
	
	return (EXIT_SUCCESS);
}