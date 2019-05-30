/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   zoom_move.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 15:21:51 by yhliboch          #+#    #+#             */
/*   Updated: 2019/03/20 15:21:52 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_cor	**which_map(t_head *head)
{
	if (head->fl == 1)
		return (head->rot_map);
	else if (head->fl == 2)
		return (head->iso_map);
	else if (head->fl == 3)
		return (head->p_map);
	else
		return (head->map);
}

void	zoom(t_head *head, char exis)
{
	int		y;
	int		x;
	t_cor	**map;

	map = which_map(head);
	y = -1;
	if ((exis == '-' && (map[0][1].x / 2) - (map[0][0].x / 2) <= 1)
	|| (exis == '+' && (map[0][1].x * 2) - (map[0][0].x * 2) >= 450))
		return ;
	while (++y < head->map_y)
	{
		x = -1;
		while (++x < head->map_x)
		{
			map[y][x].z = (exis == '+' ? map[y][x].z * 2
											: map[y][x].z / 2);
			map[y][x].y = (exis == '+' ? map[y][x].y * 2
										: map[y][x].y / 2);
			map[y][x].x = (exis == '+' ? map[y][x].x * 2
											: map[y][x].x / 2);
		}
	}
	draw_map(head, map);
}

void	move(t_head *head, char exis)
{
	int		i;
	int		j;
	t_cor	**map;

	map = which_map(head);
	i = -1;
	while (++i < head->map_y)
	{
		j = -1;
		while (++j < head->map_x)
		{
			if (exis == '4')
				map[i][j].x -= 6;
			if (exis == '6')
				map[i][j].x += 6;
			if (exis == '8')
				map[i][j].y -= 6;
			if (exis == '2')
				map[i][j].y += 6;
		}
	}
	draw_map(head, map);
}
