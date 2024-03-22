/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/22 14:18:09 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/22 16:08:13 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	skip_first_whitespaces(int *i, t_data *data)
{
	int	nb_whitespaces;

	nb_whitespaces = 0;
	while (data->mapinfo.file[*i]
		&& is_whitespace(data->mapinfo.file[*i])
		&& next_line_not_empty(*i, data->mapinfo.file))
	{
		++(*i);
		++nb_whitespaces;
	}
	return (nb_whitespaces);
}

int	checklist_ok(t_data *d)
{
	if (!d->checklist.floor || !d->checklist.ceiling)
		return (output_error(NULL, "Missing color information", 1));
	return (EXIT_SUCCESS);
}
