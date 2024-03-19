/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:44:10 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/19 10:38:55 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "struct.h"
# include "../minilibx/mlx.h"
# include "../libft/libft.h"
# include <stdint.h>
# include <stdio.h>
# include <sys/types.h>
# include <unistd.h>
# include <math.h>
# include <errno.h>
# include <time.h>

typedef void (*	t_function_ptr)(t_data *data);

int			pdir_check(t_data *data, char c);
int			has_island(t_data *data);
void		door_check(t_data *data, char c);
void		destroy_door(t_data *data);
int			valid_mapchr(t_data *data, char c);
void		open_door(t_data *d);
int			ft_atorgb(char *str);
int			exit_mlx_init(t_data *data);
int			ft_isws(char c);
void		set_pdir(t_data *data, char tab);
int			ft_data_init(t_data *data);
int			ft_mlx_mouse_move(int x, int y, t_data *data);
int			ft_mlx_mouse_exit(t_data *data);
void		destroy_world(t_data *data);
void		destroy_sprite(t_data *data);
int			ft_import(char **argv, t_data *data);
int			is_valid_rgb(int *rgb);
int			is_skipped(char c);
t_xpm		xpm_load(t_data *data, char *path);
int			get_file_data(t_data *data, char **map);
int			create_map(t_data *data, char **cub_map, int c_line);
int			import_colors(t_data *data, t_world *w, char *l, int j);
void		free_tab(void **tab);
int			check_file(char *arg, int cub);
int			parse_data(char *path, t_data *data);
int			border_check(t_data *data);
int			init_map(t_data *data, char **map, int c_line);
void		sprite_casting(t_data *data);
void		floor_casting(t_data *data);
void		draw_minimap(t_data *data);
int			ft_color_shade(int color);
void		sort_sprites(int *order, double *dist, int amount);
void		draw_rect(t_data *data, t_coord pos, t_coord size, int color);
void		move_player(t_data *data);
void		draw_img(t_data *data, t_coord pos, t_coord size, t_img *sprite);
uint		ft_mlx_pixel_get(t_img *img, int x, int y);
int			ft_mlx_close_window(int keycode, t_data *data);
int			ft_mlx_destroy_hook(t_data *data);
void		ft_mlx_fill(t_img img, int size_x, int size_y, int color);
void		ft_mlx_pixel_put(t_img *img, int x, int y, int color);
int			ft_mlx_key_hook(int keycode, t_data *data);
int			ft_mlx_mouse_hook(int keycode, int x, int y, t_data *data);
int			ft_mlx_render(t_data *data);
int			init_img(t_data *data, t_img *current_img);
int			ft_color_hsv(double h, double s, double v);
int			ft_color_argb(t_argb argb);
void		ft_color(int iter, double x, double y, t_data *data);
void		ft_menu(t_data *data);
void		ft_swap(int *a, int *b);
int			ft_abs(int number);
double		ft_lerp(double a, double b, double t);
double		ft_atof(char *str);
int			color_up(int c1, int c2, double s);
int			color_dn(int c1, int c2, double s);
int			ft_color_int(int a, int r, int g, int b);
void		ft_mlx_exit(t_data *data, int errcode);
void		ft_fractal_picker(int keycode, t_data *data);
void		ft_key_movement(int keycode, t_data *data);
void		ft_window_controls(int keycode, t_data *data);
void		ft_pos_zoom(int x, int y, t_data *data);
int			ft_keyup(int key, t_data *data);
t_ray_data	init_ray(t_data *data, int x);
void		wall_casting(t_data *data);
t_point		to_point(int x, int y);
t_coord		to_coord(float x, float y);
void		ft_draw_line(t_data *data, t_point a, t_point b, int color);
void		ft_draw_line_thick(t_data *data, t_point *p, int color, int thick);
t_sprite	init_sprite(t_data *data, t_coord pos, int frame, char **animpath);
int			output_error(char *detail, char *str, int code);
int			ft_exit_cleanup(t_data *data, int exit_code);
int			check_map_validity(t_data *data, char **map_tab);
int			check_textures_validity(t_data *data, t_world *w);

#endif