/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:05:36 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/19 14:05:55 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"


int32_t	main(int32_t argc, char const *argv[])
{
	t_programdata	data;
	
	if (validate_args(argc, argv) == EXIT_FAILURE) {
		return (EXIT_FAILURE);
	}
	if (programdata(argv[1], &data) == EXIT_FAILURE) {
		return (teardown(&data));
	}
	if (bind_hooks(&data) == EXIT_FAILURE) {
		return (teardown(&data));
	}

	mlx_loop(data.mlx);

	return (teardown(&data));
}
