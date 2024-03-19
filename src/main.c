/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:12:26 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 17:13:10 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/cub3d.h"

int	main(int argc, char **argv)
{
	t_data	data;

	if (argc != 2)
		return (output_error(NULL, "Incorrect argument count", 1));
	if (ft_data_init(&data) != EXIT_SUCCESS)
		ft_mlx_exit(&data, EXIT_FAILURE);
	if (ft_import(argv, &data) == EXIT_FAILURE)
	{
		return (EXIT_FAILURE);
	}
	mlx_hook(data.w_ptr, 6, 1L << 6, ft_mlx_mouse_move, &data);
	mlx_mouse_hook(data.w_ptr, ft_mlx_mouse_hook, &data);
	mlx_hook(data.w_ptr, 2, 1L << 0, ft_mlx_key_hook, &data);
	mlx_key_hook(data.w_ptr, ft_keyup, &data);
	mlx_hook(data.w_ptr, 17, 0, ft_mlx_destroy_hook, &data);
	mlx_loop_hook(data.mlx, ft_mlx_render, &data);
	mlx_loop(data.mlx);
	return (0);
}
