/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   color.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/25 16:02:29 by yhliboch          #+#    #+#             */
/*   Updated: 2019/03/25 16:02:31 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

int		which_color(int z)
{
	if (z == 0)
		return (DEFOLT_COLOR);
	else if (z > 0 && z <= 5)
		return (COLOR1);
	else if (z > 5 && z <= 10)
		return (COLOR2);
	else if (z > 10 && z <= 15)
		return (COLOR3);
	else
		return (COLOR4);
}

double	per(int start, int end, int current)
{
	double placement;
	double distance;

	placement = current - start;
	distance = end - start;
	return ((distance == 0) ? 1.0 : (placement / distance));
}

int		get_light(int start, int end, double percentage)
{
	return ((int)((1 - percentage) * start + percentage * end));
}

int		color(t_cor current, t_cor start, t_cor end, t_cor delta)
{
	int		red;
	int		green;
	int		blue;
	double	percentage;

	if (current.color == end.color)
		return (current.color);
	if (delta.x > delta.y)
		percentage = per(start.x, end.x, current.x);
	else
		percentage = per(start.y, end.y, current.y);
	red = get_light((start.color >> 16) & 0xFF,
				(end.color >> 16) & 0xFF, percentage);
	green = get_light((start.color >> 8) & 0xFF,
				(end.color >> 8) & 0xFF, percentage);
	blue = get_light(start.color & 0xFF, end.color & 0xFF, percentage);
	return ((red << 16) | (green << 8) | blue);
}
