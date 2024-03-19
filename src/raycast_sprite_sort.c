/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   raycast_sprite_sort.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/21 18:43:12 by aloubier          #+#    #+#             */
/*   Updated: 2023/12/21 18:43:13 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	compare_pairs(const void *a, const void *b)
{
	t_pair	*p1;
	t_pair	*p2;

	p1 = (t_pair *)a;
	p2 = (t_pair *)b;
	return (p1->first - p2->first);
}

void	sort_sprites(int *order, double *dist, int amount)
{
	t_pair	*sprites;
	int		i;

	sprites = (t_pair *)malloc(amount * sizeof(t_pair));
	i = -1;
	while (++i < amount)
	{
		sprites[i].first = dist[i];
		sprites[i].second = order[i];
	}
	qsort(sprites, amount, sizeof(t_pair), compare_pairs);
	i = -1;
	while (++i < amount)
	{
		dist[i] = sprites[amount - i - 1].first;
		order[i] = sprites[amount - i - 1].second;
	}
	free(sprites);
}
