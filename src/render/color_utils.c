/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aloubier <aloubier@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 18:12:07 by aloubier          #+#    #+#             */
/*   Updated: 2024/03/09 13:44:17 by aloubier         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/cub3d.h"

int	ft_color_argb(t_argb argb)
{
	return (argb.a << 24 | argb.r << 16 | argb.g << 8 | argb.b);
}

int	ft_color_int(int a, int r, int g, int b)
{
	return (a << 24 | r << 16 | g << 8 | b);
}

static t_hsv	ft_hsv(double h, double s, double v)
{
	t_hsv	ret;

	ret.h = h;
	ret.s = s;
	ret.v = v;
	return (ret);
}

int	ft_color_hsv(double h, double s, double v)
{
	t_hsv	t2;
	t_hsv	ret;
	t_argb	rgb;

	t2.h = v * s;
	t2.s = v - t2.h;
	t2.v = t2.h * (1 - fabs(fmod((h / 60), 2)) - 1);
	if (H >= 0 && H < 60)
		ret = ft_hsv(t2.h, t2.v, 0);
	else if (H >= 60 && H < 120)
		ret = ft_hsv(t2.v, t2.h, 0);
	else if (H >= 120 && H < 180)
		ret = ft_hsv(0, t2.h, t2.v);
	else if (H >= 180 && H < 240)
		ret = ft_hsv(0, t2.v, t2.h);
	else if (H >= 240 && H < 300)
		ret = ft_hsv(t2.v, 0, t2.h);
	else
		ret = ft_hsv(t2.h, 0, t2.v);
	rgb.a = 255;
	rgb.r = floor((ret.h + t2.s) * 255);
	rgb.g = floor((ret.s + t2.s) * 255);
	rgb.b = floor((ret.v + t2.s) * 255);
	return (ft_color_argb(rgb));
}

int	ft_color_shade(int color)
{
	return (color);
}
