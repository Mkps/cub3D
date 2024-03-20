/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_free.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 13:56:21 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/20 13:56:51 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

void	ft_free_textures(t_data *data)
{
	if (data->mapinfo.no_texture)
		free(data->mapinfo.no_texture);
	if (data->mapinfo.so_texture)
		free(data->mapinfo.so_texture);
	if (data->mapinfo.ea_texture)
		free(data->mapinfo.ea_texture);
	if (data->mapinfo.we_texture)
		free(data->mapinfo.we_texture);
}

void	ft_free_all(t_data *data)
{
	int	i;

	ft_free_textures(data);
	i = 0;
	if (data->cmap[0])
	{	
		while (i < data->mapinfo.height)
		{
			free(data->cmap[i]);
			++i;
		}
	}
	if (data->cmap)
		free(data->cmap);
	if (data->mapinfo.file)
		free(data->mapinfo.file);
}