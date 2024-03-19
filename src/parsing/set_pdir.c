/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_pdir.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:10:17 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 12:15:26 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


// static void	set_pdir_cont(t_data *data, char tab)
// {
// 	if (tab == 'S')
// 	{
// 		data->player.dir_y = 0.0;
// 		data->player.dir_x = 1.0;
// 		data->plane.x = 0.0;
// 		data->plane.y = -0.66;
// 	}
// 	if (tab == 'N')
// 	{
// 		data->player.dir_y = 0.0;
// 		data->player.dir_x = -1.0;
// 		data->plane.x = 0;
// 		data->plane.y = 0.66;
// 	}
// }

// void	set_pdir(t_data *data, char tab)
// {
// 	if (tab == 'E')
// 	{
// 		data->player.dir_y = 1.0;
// 		data->player.dir_x = 0.0;
// 		data->plane.x = 0.66;
// 		data->plane.y = 0;
// 	}
// 	else if (tab == 'W')
// 	{
// 		data->player.dir_y = -1.0;
// 		data->player.dir_x = 0.0;
// 		data->plane.x = -0.66;
// 		data->plane.y = 0;
// 	}
// 	else
// 		set_pdir_cont(data, tab);
// }

// int	pdir_check(t_data *data, char c)
// {
// 	if (c == 0)
// 		return (0);
// 	if (ft_strchr("NSEW", c) && data->player.dir_x != -3)
// 		return (1);
// 	if (ft_strchr("NSEW", c) && data->player.dir_x == -3)
// 		set_pdir(data, c);
// 	return (0);
// }
