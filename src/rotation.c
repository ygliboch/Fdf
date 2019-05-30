/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotation.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 12:14:06 by yhliboch          #+#    #+#             */
/*   Updated: 2019/03/20 12:14:07 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	del_map(t_cor **map, t_head *head)
{
	int	i;

	i = 0;
	while (i < head->map_y)
	{
		free(map[i]);
		i++;
	}
	free(map);
}

t_cor	rot_pos(t_iso **iso, t_cor map)
{
	t_iso	new;

	new.y = map.y;
	new.z = map.z;
	if ((*iso)->x != 0.0)
	{
		map.y = (new.y * cos((*iso)->x)) + (new.z * sin((*iso)->x));
		map.z = -(new.y * sin((*iso)->x)) + (new.z * cos((*iso)->x));
	}
	new.x = map.x;
	new.z = map.z;
	if ((*iso)->y != 0.0)
	{
		map.x = (new.x * cos((*iso)->y)) + (new.z * sin((*iso)->y));
		map.z = -(new.x * sin((*iso)->y)) + (new.z * cos((*iso)->y));
	}
	new.x = map.x;
	new.y = map.y;
	if ((*iso)->z != 0.0)
	{
		map.x = (new.x * cos((*iso)->z)) - (new.y * sin((*iso)->z));
		map.y = (new.x * sin((*iso)->z)) + (new.y * cos((*iso)->z));
	}
	return (map);
}

void	rot_exis(t_iso **iso, char exis)
{
	if (exis == 'x')
		(*iso)->x += ANGEL;
	if (exis == 'y')
		(*iso)->y += ANGEL;
	if (exis == 'z')
		(*iso)->z += ANGEL;
}

void	rotation(t_head *head, t_iso **iso, char exis)
{
	int		x;
	int		y;
	t_cor	**iso_map;
	t_cor	**temp;

	if (head->rot_map != NULL)
		del_map(head->rot_map, head);
	y = -1;
	rot_exis(iso, exis);
	temp = head->map;
	iso_map = (t_cor **)malloc(sizeof(t_cor *) * head->map_y);
	while (++y < head->map_y)
	{
		x = -1;
		iso_map[y] = (t_cor *)malloc(sizeof(t_cor) * head->map_x);
		while (++x < head->map_x)
			iso_map[y][x] = rot_pos(iso, temp[y][x]);
	}
	head->fl = 1;
	head->rot_map = iso_map;
	draw_map(head, iso_map);
}
