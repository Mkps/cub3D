/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_data_validity.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:13:22 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/20 15:18:58 by rraffi-k         ###   ########.fr       */
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

int	all_set(t_mapinfo *mapinfo)
{
	if (!mapinfo->no_texture || !mapinfo->so_texture
		|| !mapinfo->ea_texture || !mapinfo->we_texture
		|| (BONUS && mapinfo->has_door && !mapinfo->do_texture))
		return (output_error(NULL, E_MISSTXT, 1));
	return (EXIT_SUCCESS);
}

int	check_paths(t_mapinfo *mapinfo)
{
	if (all_set(mapinfo))
		return (EXIT_FAILURE);
	if (ft_strlen(mapinfo->no_texture) < 5
		|| ft_strlen(mapinfo->so_texture) < 5
		|| ft_strlen(mapinfo->ea_texture) < 5
		|| ft_strlen(mapinfo->we_texture) < 5)
		return (output_error(NULL, E_ITXT, 1));
	if (access(mapinfo->no_texture, F_OK)
		|| access(mapinfo->so_texture, F_OK)
		|| access(mapinfo->ea_texture, F_OK)
		|| access(mapinfo->we_texture, F_OK))
		return (output_error(NULL, E_TEX_NOACC, 1));
	if (check_xpm(mapinfo->no_texture)
		|| check_xpm(mapinfo->so_texture)
		|| check_xpm(mapinfo->ea_texture)
		|| check_xpm(mapinfo->we_texture))
		return (output_error(NULL, E_TEX_NOTXPM, 1));
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
	int	count;

	i = 0;
	count = 0;
	while (str[i] && str[i] != '\n')
	{
		while (ft_isws(str[i]) && str[i] != '\n')
			i++;
		if (!ft_isdigit(str[i]) && str[i] != ',')
			return (1);
		if (ft_isdigit(str[i]))
		{
			while (ft_isdigit(str[i]))
				i++;
			count ++;
		}
		else
			i++;
	}
	if (count != 3)
		return (1);
	return (0);
}
