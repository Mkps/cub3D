/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_player.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rraffi-k <rraffi-k@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/02 15:06:21 by emcnab            #+#    #+#             */
/*   Updated: 2024/03/13 16:15:44 by rraffi-k         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef S_PLAYER_H
# define S_PLAYER_H

# include <stdint.h>

typedef struct s_player {
	float	x;
	float	y;
	float		dir; //EAST = 0, NORTH = 90, WEST = 180, SOUTH = 270
}	t_player;

#endif