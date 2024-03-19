/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:11:43 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/19 11:44:10 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/parsing.h"
#include "../../libft/libft.h"


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

void	print_info(t_data data)
{
	printf("%s\n", data.mapinfo->no_texture);
	printf("%s\n", data.mapinfo->so_texture);
	printf("%s\n", data.mapinfo->ea_texture);
	printf("%s\n", data.mapinfo->we_texture);


	printf("\n");


	printf("%d\n", data.mapinfo->c_color);
	printf("%d\n", data.mapinfo->f_color);


	printf("\n");

	// int i = 0;
	// while (data.mapinfo->map[i])
	// {
	// 	printf("%s\n", data.mapinfo->map[i]);
	// 	i++;
	// }


	printf("%f\n", data.player->dir);
	printf("%f\n", data.player->x);
	printf("%f\n", data.player->y);	
}