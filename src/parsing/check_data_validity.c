/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_validity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:13:22 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/20 13:44:05 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	check_xpm(char *str)
{
	int	i;

	i = ft_strlen(str) - 4;
	if (str[i] != '.' || str[i + 1] != 'x'
		|| str[i + 2] != 'p' || str[i + 3] != 'm')
		return (1);
	return (0);
}

int	check_paths(t_mapinfo *mapinfo)
{
	if (ft_strlen(mapinfo->no_texture) < 5
		|| ft_strlen(mapinfo->so_texture) < 5
		|| ft_strlen(mapinfo->ea_texture) < 5
		|| ft_strlen(mapinfo->we_texture) < 5)
		return (EXIT_FAILURE);
	if (!access(mapinfo->no_texture, F_OK)
		|| !access(mapinfo->so_texture, F_OK)
		|| !access(mapinfo->ea_texture, F_OK)
		|| !access(mapinfo->we_texture, F_OK))
		return (EXIT_FAILURE);
	if (check_xpm(mapinfo->no_texture)
		|| check_xpm(mapinfo->so_texture)
		|| check_xpm(mapinfo->ea_texture)
		|| check_xpm(mapinfo->we_texture))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

int	check_rgb_values(int red, int green, int blue)
{
	if (red < 0 || red > 255 || green < 0
		|| green > 255 || blue < 0 || blue > 255)
		return (1);
	return (0);
}

int	check_rgb_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
	{
		if (!ft_isdigit(str[i]) && str[i] != ',')
			return (1);
		i++;
	}
	return (0);
}
