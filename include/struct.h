/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:44:06 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/21 12:15:05 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# ifndef BONUS
#  define BONUS 0
# endif
# define T_W 64
# define T_H 64
# define MS 0.06f
# define RS 0.08f
# define PI 3.14159265359f
# define DR 0.0174533f
# define C_RST "\e[0m"
# define C_RED "\e[31m"
# define C_GRN "\e[32m"
# define C_BLU "\e[34m"
# define W 1200
# define H 800
# define E_ITXT "Invalid texture"
# define E_MISSTXT "Missing texture"
# define E_IMPTXT "Error importing texture"
# define E_ICHAR "Invalid character"
# define E_TMP	"Too many players"
# define E_MISFC "Missing RGB color for Floor or Ceiling"
# define E_INVC "Invalid color format"
# define E_INVRGVC "Invalid RGB color for ceiling"
# define E_INVRGVF "Invalid RGB color for floor"
# define E_DUPTXT "Duplicate texture"
# define E_MALLOC_SP "Error allocating memory for sprite"
# define E_MALLOC_CMAP "Error allocating memory for cmap"
# define E_INIT_CMAPL "An error occured while retrieving map line"
# define E_IS_RGB "Invalid RGB syntax"
# define E_TEX_NOTXPM "Invalid texture: Texture is not a .xpm texture"
# define E_TEX_NOACC "Invalid texture: Texture could not be accessed" 
# define ARG_ERROR "Invalid arguments"
# define E_EMPTY_FILE "Empty file"
# define OPEN_FD_ERROR "Could not open file"
# define CLOSE_FD_ERROR "Could not close file"
# define DUPLICATE_ERROR "Duplicate detected in file"
# define SYNTAX_ERROR "Wrong syntax"
# define MAP_ERROR "Map is invalid"
# define E_MAP_NE "Invalid map: Character found after map end"
# define NO_PLAYER_ERROR "There is no player"
# define RGB_VALUE_ERROR "Invalid RGB value"
# define FLOOR 1
# define CEILING 2
# include <stddef.h>

typedef struct s_checklist
{
	int			map;
	int			check_do;
	int			check_no;
	int			check_so;
	int			check_we;
	int			check_ea;
	int			floor;
	int			ceiling;
	int			check_dir;
}	t_checklist;

typedef struct s_mapinfo
{
	int			width;
	int			height;
	char		**map;
	char		*file;
	int			file_size;
	size_t		file_nb_lines;
	char		*no_texture;
	char		*do_texture;
	char		*so_texture;
	char		*we_texture;
	char		*ea_texture;
	int			f_color;
	int			c_color;
	int			fd;
	int			line_count;
	char		*path;
	int			eom;
	int			has_door;
}	t_mapinfo;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}				t_img;

typedef struct s_xpm
{
	t_img	img;
	char	*path;
	int		w;
	int		h;
}	t_xpm;

typedef struct s_coord
{
	float	x;
	float	y;
}				t_coord;

typedef struct s_dcoord
{
	double	x;
	double	y;
}				t_dcoord;

typedef struct s_point
{
	int	x;
	int	y;
}	t_point;

typedef struct s_window
{
	int	width;
	int	height;
}	t_window;

typedef struct s_mdata
{
	int			fd;
	int			line_count;
	char		*path;
	char		**file;
	int			height;
	int			width;
	int			eom;
	int			has_door;
}	t_mdata;

typedef struct s_thing
{
	float	pos_x;
	float	pos_y;
	float	dir_x;
	float	dir_y;
}	t_thing;

typedef struct s_sheet
{
	t_img	img;
	char	*path;
	int		w_t;
	int		h_t;
	int		w;
	int		h;
	int		img_per_line;
}	t_sheet;

typedef struct s_sprite
{
	t_coord	pos;
	int		frame_time;
	int		frame_count;
	int		frame;
	t_xpm	*animation;
}	t_sprite;

typedef struct s_keys
{
	int		w;
	int		a;
	int		s;
	int		d;
	float	l;
	float	r;
}	t_keys;

typedef struct s_ray_data
{
	t_dcoord	map;
	t_dcoord	step;
	t_dcoord	raydir;
	t_dcoord	side_dist;
	t_dcoord	delta_dist;
	int			side;
	int			color;
	double		pwall_dist;
	int			x;
}	t_ray_data;

typedef struct s_world
{
	t_xpm	n;
	t_xpm	s;
	t_xpm	e;
	t_xpm	w;
	t_xpm	d;
	int		is_f_color;
	int		is_c_color;
	int		f_color;
	int		c_color;
	int		*f_rgb;
	int		*c_rgb;
	t_xpm	f;
	t_xpm	c;
}	t_world;

typedef struct s_data
{
	char		*file;
	size_t		file_size;
	int			fd;
	t_mapinfo	mapinfo;
	t_checklist	checklist;
	void		*mlx;
	t_world		world;
	char		**cmap;
	int			**map;
	void		*w_ptr;
	int			**texture;
	char		current_img;
	t_img		img_a;
	t_img		img_b;
	int			is_menu_on;
	t_coord		plane;
	int			smooth;
	double		zoom;
	double		resolution;
	t_keys		keys;
	t_thing		player;
	t_window	w_data;
	double		*z_buffer;
	int			mouselook_on;
	int			sprite_count;
	t_sprite	*sprite;
}	t_data;

typedef struct s_argb
{
	int	a;
	int	r;
	int	g;
	int	b;
}	t_argb;

typedef struct s_hsv
{
	double	h;
	double	s;
	double	v;
}	t_hsv;

typedef struct s_pair
{
	double	first;
	int		second;
}	t_pair;

typedef struct s_wall
{
	int			h;
	int			line_h;
	t_dcoord	draw;
	double		wall_x;
	int			tex_num;
	double		tex_pos;
	double		step;
	t_point		tex;
	double		tex_w;
	double		tex_h;
}	t_wall;

typedef struct s_floor
{
	t_coord	ray[2];
	t_coord	floor;
	t_coord	floor_step;
	t_point	cell;
	t_point	tex;
	int		p;
	float	row_dist;
	float	pos_z;
}	t_floor;

typedef struct s_sdata
{
	int		*sprite_order;
	double	*sprite_distance;
}	t_sdata;

typedef struct s_stex
{
	t_coord	sprite;
	float	inv_det;
	t_coord	transform;
	int		sprite_screen_x;
	t_point	draw[2];
	int		sprite_h;
	int		sprite_w;
	int		c_stripe;
	t_point	tex;
}	t_stex;

enum	e_door
{
	e_p = 11,
	e_b = 12,
	e_l = 13,
	e_s = 14,
	e_o = 15,
	e_d = 16
};
#endif
