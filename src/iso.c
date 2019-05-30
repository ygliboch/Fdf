/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   iso.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 19:06:39 by yhliboch          #+#    #+#             */
/*   Updated: 2019/03/20 19:06:45 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cor	iso_pos(t_cor map)
{
	int previous_x;
	int previous_y;

	previous_x = map.x;
	previous_y = map.y;
	map.x = (previous_x - previous_y) * cos(0.523599);
	map.y = -map.z + (previous_x + previous_y) * sin(0.523599);
	return (map);
}

void	iso_map(t_head *head)
{
	int		x;
	int		y;
	t_cor	**temp;
	t_cor	**iso;

	if (head->iso_map != NULL)
	{
		head->fl = 2;
		draw_map(head, head->iso_map);
		return ;
	}
	y = -1;
	temp = head->map;
	iso = (t_cor **)malloc(sizeof(t_cor *) * head->map_y);
	while (++y < head->map_y)
	{
		x = -1;
		iso[y] = (t_cor *)malloc(sizeof(t_cor) * head->map_x);
		while (++x < head->map_x)
			iso[y][x] = iso_pos(temp[y][x]);
	}
	head->iso_map = iso;
	head->fl = 2;
	draw_map(head, iso);
}
