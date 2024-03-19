#ifndef PARSING_H
#define PARSING_H

# define WINDOW_WIDTH 1024
# define WINDOW_HEIGHT 1024


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
# include "s_player.h"

/*****************************************/
/*           GENERAL STRUCTURES          */
/*****************************************/

typedef struct s_checklist
{
    int check_no;
    int check_so;
    int check_we;
    int check_ea;
    int floor;
    int ceiling;
    int check_dir;
} t_checklist;

typedef struct s_mapinfo
{
    int width;
    char **map;
    char *file;
    size_t file_size;
    size_t file_nb_lines;

    int height;
    char *no_texture;
    char *so_texture;
    char *we_texture;
    char *ea_texture;
    //door

    uint32_t f_color; //floor
    uint32_t c_color; //ceiling


} t_mapinfo;

typedef struct s_data
{
    char *file;
    size_t file_size;

    int fd;

    t_player  *player;
    t_mapinfo *mapinfo;
    t_checklist checklist;
	void		*mlx;
	void		*win;
	int			width;
	int			height;

    int *floor_col[3]; //           floor's color in RGB
    int *ceiling_col[3]; //         ceiling's color in RGB

} t_data;

/*****************************************/
/*           PARSING STRUCTURE           */
/*****************************************/



int safe_open(char *file_name);
void safe_close(int fd);
int get_map_nb_lines(char **map);
int	get_map_width(char **map, t_data *data);
uint32_t ft_rgb_to_uint32(int red, int green, int blue);
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