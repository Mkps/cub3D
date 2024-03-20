/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:11:43 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/20 13:52:20 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	print_error(char *error_message)
{
	printf("%s\n", error_message);
	return (EXIT_FAILURE);
}

int	is_whitespace(char c)
{
	if (c == '\f' || c == '\n'
		|| c == '\r' || c == '\t'
		|| c == '\v' || c == ' ')
		return (1);
	return (0);
}

int ft_strlen_eol(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

void	print_info(t_data *data)
{
	printf("%s\n", data->mapinfo.no_texture);
	printf("%s\n", data->mapinfo.so_texture);
	printf("%s\n", data->mapinfo.ea_texture);
	printf("%s\n", data->mapinfo.we_texture);


	printf("\n");


	printf("%d\n", data->mapinfo.c_color);
	printf("%d\n", data->mapinfo.f_color);


	printf("\n");

	// int i = 0;
	// while (data.cmap[i])
	// {
	// 	printf("%s\n", data.cmap[i]);
	// 	i++;
	// }
	

	printf("%f\n", data->player.dir_x);
	printf("%f\n", data->player.dir_y);
}
