/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parallel.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/27 17:21:20 by yhliboch          #+#    #+#             */
/*   Updated: 2019/03/27 17:21:28 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cor	p_pos(t_cor map)
{
	t_iso	new;

	new.y = map.y;
	new.z = map.z;
	map.y = (new.y * cos(5.2) + (new.z * sin(5.2)));
	map.z = -(new.y * sin(5.2) + (new.z * cos(5.2)));
	return (map);
}

void	p_map(t_head *head)
{
	int		x;
	int		y;
	t_cor	**temp;
	t_cor	**p;

	if (head->p_map != NULL)
	{
		head->fl = 3;
		draw_map(head, head->p_map);
		return ;
	}
	y = -1;
	temp = head->map;
	p = (t_cor **)malloc(sizeof(t_cor *) * head->map_y);
	while (++y < head->map_y)
	{
		x = -1;
		p[y] = (t_cor *)malloc(sizeof(t_cor) * head->map_x);
		while (++x < head->map_x)
			p[y][x] = p_pos(temp[y][x]);
	}
	head->p_map = p;
	head->fl = 3;
	draw_map(head, p);
}
