#ifndef PARSING_H
#define PARSING_H

# define ARG_ERROR "Error : Invalid arguments"
# define OPEN_FD_ERROR "Error : Could not open file"
# define CLOSE_FD_ERROR "Error : Could not close file"
# define DUPLICATE_ERROR "Error : Duplicate detected in file"
# define SYNTAX_ERROR "Error : Wrong syntax"
# define MAP_ERROR "Error : Map isn't valid"
# define NO_PLAYER_ERROR "Error : There is no player"

# define EAST 0
# define NORTH 90
# define WEST 180
# define SOUTH 270
# define FLOOR 1
# define CEILING 2

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <X11/X.h>
# include <X11/keysym.h>
# include <math.h>
# include <sys/stat.h>
# include <fcntl.h>
# include <aio.h>

/*****************************************/
/*           GENERAL STRUCTURES          */
/*****************************************/

// typedef struct s_checklist
// {
//     int check_no;
//     int check_so;
//     int check_we;
//     int check_ea;
//     int floor;
//     int ceiling;
//     int check_dir;
// } t_checklist;

// typedef struct s_mapinfo
// {
//     int width;
//     int height;

//     char **map;
//     char *file;
//     size_t file_size;
//     size_t file_nb_lines;

//     char *no_texture;
//     char *so_texture;
//     char *we_texture;
//     char *ea_texture;
//     //door

//     int f_color; //floor
//     int c_color; //ceiling


// } t_mapinfo;

// typedef struct s_data
// {
//     char *file;
//     size_t file_size;

//     int fd;

//     // t_thing  player;
//     // t_coord		plane;

//     // t_mapinfo *mapinfo;
//     // t_checklist checklist;

// 	// int			width;
// 	// int			height;

// } t_data;

/*****************************************/
/*           PARSING STRUCTURE           */
/*****************************************/



int safe_open(char *file_name);
void safe_close(int fd);
// int get_map_nb_lines(char **map);
int	get_map_width(char **map, t_data *data);
int ft_rgb_to_int(int red, int green, int blue);
int parse_and_get_rgb(int *i, int flag, t_data *data);
int check_rgb_syntax(char *str);
int check_rgb_values(int red, int green, int blue);
int	check_map_is_closed(char **map, t_data *data);

int check_paths(t_mapinfo *mapinfo);
int check_rgb_values(int red, int green, int blue);
int check_rgb_syntax(char *str);
int ft_strlen_eol(char *str);
// int ft_strlen_char(char *str, char c);
void	print_info(t_data data);

#endif