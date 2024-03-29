/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   safe_fd_functions.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 13:58:15 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/21 12:22:23 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

int	safe_open(char *file_name)
{
	int	fd;

	fd = open(file_name, O_RDONLY);
	if (fd == -1)
		return (-1);
	return (fd);
}

int	safe_close(int fd)
{
	if (close(fd) == -1)
	{
		printf(CLOSE_FD_ERROR);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
