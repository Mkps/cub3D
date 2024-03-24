/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_island.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:44:10 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/11 14:06:45 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/cub3d.h"

static int	check_remainder(char **map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (!map || !map[i] || !map[i][j])
		return (EXIT_FAILURE);
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '0'
				|| map[i][j] == '1'
				|| map[i][j] == 'D')
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

static char	**ft_strsndup(char **tab, int n)
{
	char	**tmp;
	int		i;

	tmp = malloc(sizeof(char *) * (n + 1));
	if (!tmp)
		return (NULL);
	i = 0;
	while (i < n)
	{
		tmp[i] = ft_strdup(tab[i]);
		i++;
	}
	tmp[i] = NULL;
	return (tmp);
}

static void	ft_flood(t_data *data, char **map, int x, int y)
{
	if (x < 0 || y < 0 || x >= data->mapinfo.height
		|| (size_t)y >= ft_strlen(map[x]))
		return ;
	if (!map || !map[x] || !map[x][y])
		return ;
	if (map[x][y] == ' ')
		return ;
	if (!valid_mapchr(data, map[x][y]))
		return ;
	map[x][y] = 'X';
	if (x + 1 < data->mapinfo.height)
		ft_flood(data, map, x + 1, y);
	if (x > 0)
		ft_flood(data, map, x - 1, y);
	if (y + 1 < data->mapinfo.width)
		ft_flood(data, map, x, y + 1);
	if (y > 0)
		ft_flood(data, map, x, y - 1);
}

int	has_island(t_data *data)
{
	char	**dup;
	int		ret;
	int		i;
	int		j;

	ret = 0;
	dup = ft_strsndup(data->cmap, data->mapinfo.height);
	if (!dup)
		return (EXIT_FAILURE);
	i = 0;
	while (dup[++i])
	{
		j = 0;
		while (dup[i][++j])
		{
			if (!ft_isws(dup[i][j]))
				ft_flood(data, dup, i, j);
		}
		if (!ft_isws(dup[i][j]))
			break ;
	}
	if (!ret && check_remainder(dup) == EXIT_FAILURE)
		ret = 1;
	ft_free_tab(dup);
	return (ret);
}
