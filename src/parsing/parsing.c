/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 18:06:05 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/19 11:44:14 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "main_parsing.h"


// # include <stdio.h>
// # include <stdlib.h>
// # include <unistd.h>
// # include <X11/X.h>
// # include <X11/keysym.h>
// # include <math.h>
// # include <sys/stat.h>
// # include <fcntl.h>

#include "../../include/parsing.h"
#include "../../libft/libft.h"

// int get_map_nb_lines(char **map)
// {
// 	int i;

// 	i = 0;
// 	while (map[i])
// 		i++;
// 	return (i);
// }

int	get_map_width(char **map, t_data *data)
{
	int	i;
	int	j;
	int height;
	int	width;

	i = 0;
	width = 0;
	height = data->mapinfo->height;
	while (i < height)
	{
		j = 0;
		while (map[i][j])
			j++;
		if (j > width)
			width = j;
		++i;
	}
	return (width);
}

int check_upper_wall(char **map, t_data *data)
{
	int i;
	int j;
	int height;

	j = 0;
	height = data->mapinfo->height;
	while (map[0][j])
	{
		if (map[0][j] != '1' && map[0][j] != ' ')
			return (-1);

		i = 0;
		while (i < height && map[i][j] && map[i][j] == ' ')
		{				
			++i;
			if (i < height)
			{
				if (map[i][j] 
					&& (map[i][j] != ' ' && map[i][j] != '1')
					|| ((map[i][j] && map[i][j] != '1' && map[i][j + 1] && map[i][j + 1] != '1' && map[i][j + 1] != ' ')
					|| (map[i][j] && map[i][j] != '1' && map[i][j - 1] && map[i][j - 1] != '1' && map[i][j - 1] != ' ')))
						return (-1);
			}

		}
		++j;
	}
	return (EXIT_SUCCESS);
}

int check_bottom_wall(char **map, t_data *data)
{
	int i;
	int j;
	int end;

	end = data->mapinfo->height - 1;
	j = 0;
	while (map[end][j])
	{
		i = end;
		
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (-1);

		while (i >= 0 && map[i][j] && map[i][j] == ' ')
		{				
			--i;
			if (i >= 0)
			{
				//CHECK SEGFAULT DANS LE CAS OU MAP[I][J - 1] OU MAP[I][J + 1] N'EXISTENT PAS
				if (map[i][j] 
					&& (map[i][j] != ' ' && map[i][j] != '1')
					|| ((map[i][j] && map[i][j] != '1' && map[i][j + 1] && map[i][j + 1] != '1' && map[i][j + 1] != ' ')
					|| (map[i][j] && map[i][j] != '1' && map[i][j - 1] && map[i][j - 1] != '1' && map[i][j - 1] != ' ')))
						return (-1);
			}

		}
		++j;
	}
	return (EXIT_SUCCESS);
}

int check_left_wall(char **map, t_data *data)
{
	int i;
	int j;
	int	height;

	i = 0;
	j = 0;
	height = data->mapinfo->height;
	while (i < height && map[i][j])
	{
		j = 0;
		
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (-1);

		while (i < height && map[i][j] && map[i][j] == ' ')
		{				
			++j;
			if (map[i][j])
			{
				if ((map[i][j] != ' ' && map[i][j] != '1')
					|| ((map[i][j] && map[i][j] != '1' && i > 0 && map[i - 1][j] && map[i - 1][j] != '1' && map[i - 1][j] != ' ')
					|| (map[i][j] && map[i][j] != '1' && i < height - 1 && map[i + 1][j] && map[i + 1][j] != '1' && map[i + 1][j] != ' ')))
						return (-1);
			}

		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int check_right_wall(char **map, t_data *data)
{
	int i;
	int j;
	int	height;
	int	width;

	width = data->mapinfo->width;
	height = data->mapinfo->height;
	i = 0;
	j = width - 2;

	while (i < height && map[i][j])
	{
		j = width - 2;
		
		if (map[i][j] != '1' && map[i][j] != ' ')
			return (-1);

		while (i < height && map[i][j] && map[i][j] == ' ')
		{				
			--j;
			if (map[i][j])
			{
				if ((map[i][j] != ' ' && map[i][j] != '1')
					|| ((map[i][j] && map[i][j] != '1' && i > 0 && map[i - 1][j] && map[i - 1][j] != '1' && map[i - 1][j] != ' ')
					|| (map[i][j] && map[i][j] != '1' && i < height - 1 && map[i + 1][j] && map[i + 1][j] != '1' && map[i + 1][j] != ' ')))
						return (-1);
			}

		}
		++i;
	}
	return (EXIT_SUCCESS);
}

int	check_map_is_closed(char **map, t_data *data)
{
	// int i1 = check_bottom_wall(map) ;
	// int i2 = check_upper_wall(map);
	// int i3 = check_left_wall(map);
	// int i4 = check_right_wall(map);

	// printf("%d\n%d\n%d\n%d\n", i1, i2, i3, i4);

	if (check_bottom_wall(map, data) == -1
		|| check_upper_wall(map, data) == - 1
		|| check_left_wall(map, data) == -1
		|| check_right_wall(map, data) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}



// int main()
// {
// 	char **map;

// 	map = (char**)malloc(14 * sizeof(char*));

//     // Assigning values to each element in the array
//     map[0] =  "        1111111111111111111111111";
//     map[1] =  "        1000000000110000000000001";
//     map[2] =  "    11111011000001110000000000001";
//     map[3] =  "        1001000000000000000000001";
//     map[4] =  "111111111011000001110000000000001";
//     map[5] =  "100000000011000001110111111111111";
//     map[6] =  "10110111111111011100000010001    ";
//     map[7] =  "10110111111111011101010010001    ";
//     map[8] =  "11000000110111011100000010001    ";
//     map[9] =  "100000000000   01100000010001    ";
//     map[10] = "10000000000000001101010010001    ";
// 	map[11] = "1100000111010101111101111000111  ";
//     map[12] = "11110111 1110101 101111010001    ";
//     map[13] = "11111111 1111111 111111111111    ";




// 	// printf("yo\n");
// 	printf("RESULTAT = %d\n", check_map_is_closed(map));

// 	return (0);
// }

// int check_valid_map(char **map)
// {
// 	int i;
// 	int i_tmp;
// 	int j;

// 	j = 0;

// 	//ON PARSE LA PREMIERE LIGNE DE LA MAP



// }

//ft_map
// {
	//POUR CHAQUE LIGNE
	//check que 1ere et derniere ligne ne sont que des 1

	
// }

// int parse_file(int fd)
// {
// 	//POUR CHAQUE LIGNE
// 	//if les 2 premiers caracteres sont NO ou SO ou WE ou EA et le 3e est ' '
// 		//avancer jusqu'a ce qu'il n'y ait plus d'espaces
// 		//if le reste de la ligne (jusqu'au 1er \n) est un path valide
// 			//enregistrer le path dans le pt cardinal correspondant
	
// 	//else if le 1er est F ou C et le 3e un ' '
// 		//avancer jusqu'a ce qu'il n'y ait plus d'espaces
// 		//if le reste de la ligne jusqu'a la prochaine virgule est 
// 		//un ft_atoi valide, qu'il y a une virgule, et ainsi de suite jusqu'a \n
// 		//enregistrer le RGB dans le F ou C correspondant
	
// 	//else if ligne vide : passer au prochain \n 

// 	//else :
// 		//if ft_map pas valide : return error
	
// 	return (EXIT_SUCCESS);
// }

/*

1. 1er ligne : regarder s'il y a un espace, 
descendre jusqu'a ce qu'on trouve un 1

derniere ligne : pareil, vers le haut


2. trouver le width le plus grand et le height le plus grand
faire un char ** de cette taille-la

3. verifier les doublons pour NO SO etc


*/