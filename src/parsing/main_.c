/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emcnab <emcnab@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 11:05:36 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/03 14:13:16 by emcnab           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stdlib.h>

#include "mlx.h"
#include "validate_args.h"
#include "programdata.h"
#include "bind_hooks.h"
#include "teardown.h"

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
