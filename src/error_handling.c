/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 14:07:07 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/08 16:56:23 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	output_error(char *type, char *str, int code)
{
	ft_putstr_fd("Error\n", 2);
	ft_putstr_fd("cub3D: ", 2);
	if (type)
		ft_putstr_fd(type, 2);
	if (str && !type)
		ft_putstr_fd(str, 2);
	else if (str && type)
	{
		ft_putstr_fd(": ", 2);
		ft_putstr_fd(str, 2);
	}
	ft_putstr_fd("\n", 2);
	return (code);
}
