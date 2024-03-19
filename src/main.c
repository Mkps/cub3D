/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:12:26 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/08 14:36:53 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

/**
int	init_data_sprite(t_data *data)
{
	char	*light_path[1];
	char	*light_anim[2];
	char	*pillar[1];
	char	*barrel[1];

	light_path[0] = "./greenlight.xpm";
	light_anim[0] = "./flameskull.xpm";
	pillar[0] = "./pillar.xpm";
	barrel[0] = "./barrel.xpm";

	data->sprite_count = 17;
	t_sprite *sprite = ft_calloc(data->sprite_count, sizeof(t_sprite));
	if (!sprite)
		return (ft_putstr_fd("allocating\n", 2), EXIT_FAILURE);
	//lights
	sprite[0] = init_sprite(data, to_coord(20.5, 11.5), 1, light_path);
	sprite[1] = init_sprite(data, to_coord(18.5, 4.5), 1, light_path);
	sprite[2] = init_sprite(data, to_coord(10.0, 4.5), 1, light_path);
	sprite[3] = init_sprite(data, to_coord(10.0, 12.5), 1, light_path);
	sprite[4] = init_sprite(data, to_coord(3.5, 6.5), 1, light_path);
	sprite[5] = init_sprite(data, to_coord(3.5, 20.5), 1, light_path);
	sprite[6] = init_sprite(data, to_coord(3.5, 14.5), 1, light_path);
	sprite[7] = init_sprite(data, to_coord(14.5, 20.5), 1, light_path);
	//animated sprite
	sprite[8] = init_sprite(data, to_coord(8.0, 11.5), 2, light_anim);
	sprite[16] = init_sprite(data, to_coord(8.5, 12.5), 2, light_anim);
	//pillars
	sprite[9] = init_sprite(data, to_coord(10.5, 18.5), 1, pillar);
	sprite[10] = init_sprite(data, to_coord(10.5, 19.5), 1, pillar);
	sprite[11] = init_sprite(data, to_coord(10.5, 17.5), 1, pillar);
	//barrels
	sprite[12] = init_sprite(data, to_coord(22.5, 21.5), 1, barrel);
	sprite[13] = init_sprite(data, to_coord(22.0, 21), 1, barrel);
	sprite[14] = init_sprite(data, to_coord(22.5, 20.5), 1, barrel);
	sprite[15] = init_sprite(data, to_coord(16.2, 1.2), 1, barrel);
	//set sprite array to data
	data->sprite = sprite;
	return (EXIT_SUCCESS);
}
**/

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
	mlx_hook(data.w_ptr, 8, 1L << 5, ft_mlx_mouse_exit, &data);
	mlx_mouse_hook(data.w_ptr, ft_mlx_mouse_hook, &data);
	mlx_hook(data.w_ptr, 2, 1L << 0, ft_mlx_key_hook, &data);
	mlx_key_hook(data.w_ptr, ft_keyup, &data);
	mlx_hook(data.w_ptr, 17, 0, ft_mlx_destroy_hook, &data);
	mlx_loop_hook(data.mlx, ft_mlx_render, &data);
	mlx_loop(data.mlx);
	return (0);
}
