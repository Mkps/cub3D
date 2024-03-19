/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:43:42 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 14:06:23 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


t_point	to_point(int x, int y)
{
	t_point	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}

t_coord	to_coord(float x, float y)
{
	t_coord	ret;

	ret.x = x;
	ret.y = y;
	return (ret);
}
