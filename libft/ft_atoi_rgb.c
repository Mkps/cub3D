/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_rgb.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/09 14:38:19 by rraffi-k          #+#    #+#             */
/*   Updated: 2024/03/19 16:06:24 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi_rgb(const char *nptr, int *index)
{
	int	res;
	int	i;
	int	n;

	i = 0;
	n = 1;
	res = 0;
	while (nptr[i] && (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13)))
		i++;
	if (nptr[i] == '+')
		i++;
	else if (nptr[i] == '-')
	{
		n = -n;
		i++;
	}
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		res *= 10;
		res = res + (nptr[i] - '0');
		i++;
	}
	if (i > 0)
		*index += i + 1;
	return (n * res);
}


// int	main(int argc, char **argv)
// {
// 	int red;
// 	int green;
// 	int blue;
// 	char *file = "12341342,0,0123312";
// 	int i = 0;
	
// 	red = ft_atoi_rgb(file + i, &i);
// 	green = ft_atoi_rgb(file + i, &i);
// 	blue = ft_atoi_rgb(file + i, &i);
	

// 	printf("%d %d %d", red, green, blue);
// 	// data->mapinfo->f_color = ft_rgb_to_uint32(red, green, blue);
// }
