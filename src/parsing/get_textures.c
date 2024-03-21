/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_textures.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 14:56:36 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/21 11:47:46 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	get_north_texture(int *i, char *file, t_data *data)
{
	if (data->checklist.check_no)
		return (output_error(NULL, DUPLICATE_ERROR, 1));
	data->checklist.check_no = 1;
	*i += 2;
	if (!file[*i] || !is_whitespace(file[*i]))
		return (output_error(NULL, E_ITXT, 1));
	while (is_whitespace(file[*i]))
		++(*i);
	data->mapinfo.no_texture = ft_substr(file + *i, 0,
			ft_strlen_eol(file + *i));
	return (EXIT_SUCCESS);
}

int	get_south_texture(int *i, char *file, t_data *data)
{
	if (data->checklist.check_so)
		return (output_error(NULL, DUPLICATE_ERROR, 1));
	data->checklist.check_so = 1;
	*i += 2;
	if (!file[*i] || !is_whitespace(file[*i]))
		return (output_error(NULL, E_ITXT, 1));
	while (is_whitespace(file[*i]))
		++(*i);
	data->mapinfo.so_texture = ft_substr(file + *i, 0,
			ft_strlen_eol(file + *i));
	return (EXIT_SUCCESS);
}

int	get_east_texture(int *i, char *file, t_data *data)
{
	if (data->checklist.check_ea)
		return (output_error(NULL, DUPLICATE_ERROR, 1));
	data->checklist.check_ea = 1;
	*i += 2;
	if (!file[*i] || !is_whitespace(file[*i]))
		return (output_error(NULL, E_ITXT, 1));
	while (is_whitespace(file[*i]))
		++(*i);
	data->mapinfo.ea_texture = ft_substr(file + *i,
			0, ft_strlen_eol(file + *i));
	return (EXIT_SUCCESS);
}

int	get_west_texture(int *i, char *file, t_data *data)
{
	if (data->checklist.check_we)
		return (output_error(NULL, DUPLICATE_ERROR, 1));
	data->checklist.check_we = 1;
	*i += 2;
	if (!file[*i] || !is_whitespace(file[*i]))
		return (output_error(NULL, E_ITXT, 1));
	while (is_whitespace(file[*i]))
		++(*i);
	data->mapinfo.we_texture = ft_substr(file + *i,
			0, ft_strlen_eol(file + *i));
	return (EXIT_SUCCESS);
}
