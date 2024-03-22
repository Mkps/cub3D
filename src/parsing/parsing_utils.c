/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 16:11:43 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/22 14:21:35 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	is_whitespace(char c)
{
	if (c == '\f' || c == '\n'
		|| c == '\r' || c == '\t'
		|| c == '\v' || c == ' ')
		return (1);
	return (0);
}

int	ft_strlen_eol(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	if (!str[i])
		i--;
	return (i);
}

int	next_line_not_empty(int i, char *file)
{
	while (file[i] && file[i] != '\n')
	{
		if (file[i] == '1')
			return (1);
		++i;
	}
	return (0);
}

void	skip_whitespaces(int *i, char *file)
{
	while (file[*i] && is_whitespace(file[*i]))
	{
		if (file[*i] == '\n'
			&& next_line_not_empty(*i + 1, file))
			return ;
		++(*i);
	}
}

int	checklist_ok(t_data *d)
{
	if (!d->checklist.floor || !d->checklist.ceiling)
		return (output_error(NULL, "Missing color information", 1));
	return (EXIT_SUCCESS);
}

// void	print_info(t_data *data)
// {
// 	printf("%s\n", data->mapinfo.no_texture);
// 	printf("%s\n", data->mapinfo.so_texture);
// 	printf("%s\n", data->mapinfo.ea_texture);
// 	printf("%s\n", data->mapinfo.we_texture);
// 	printf("\n");
// 	printf("%d\n", data->mapinfo.c_color);
// 	printf("%d\n", data->mapinfo.f_color);
// 	printf("\n");
// 	// int i = 0;
// 	// while (data.cmap[i])
// 	// {
// 	// 	printf("%s\n", data.cmap[i]);
// 	// 	i++;
// 	// }
// 	printf("%f\n", data->player.dir_x);
// 	printf("%f\n", data->player.dir_y);
// }
