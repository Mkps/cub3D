/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:11:43 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/20 12:20:58 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"



int ft_strlen_eol(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

// int ft_strlen_comma(char *str)
// {
// 	int	i;

// 	i = 0;
// 	while (str[i] && str[i] != ',')
// 		i++;
// 	return (i);
// }

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
