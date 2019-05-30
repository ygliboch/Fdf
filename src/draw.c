/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/14 17:58:33 by yhliboch          #+#    #+#             */
/*   Updated: 2019/03/14 17:58:36 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	ft_pixel_put(t_head *head, int x, int y, int color)
{
	int	i;

	x += WIDTH / 2;
	y += HEIGHT / 2;
	if (x >= 0 && x < WIDTH && y >= 0 && y < HEIGHT)
	{
		i = (x * head->bpp / 8) + (y * head->size_line);
		head->init.addr[i] = color;
		head->init.addr[++i] = color >> 8;
		head->init.addr[++i] = color >> 16;
	}
}

void	ft_put_line(t_cor f, t_cor first, t_cor second, t_head *head)
{
	t_cor	delta;
	t_cor	sign;
	t_cor	error;

	delta.x = abs(second.x - first.x);
	delta.y = abs(second.y - first.y);
	sign.x = first.x < second.x ? 1 : -1;
	sign.y = first.y < second.y ? 1 : -1;
	error.x = delta.x - delta.y;
	ft_pixel_put(head, second.x, second.y, color(first, f, second, delta));
	while (first.x != second.x || first.y != second.y)
	{
		ft_pixel_put(head, first.x, first.y, color(first, f, second, delta));
		error.y = error.x * 2;
		if (error.y > -delta.y)
		{
			error.x -= delta.y;
			first.x += sign.x;
		}
		if (error.y < delta.x)
		{
			error.x += delta.x;
			first.y += sign.y;
		}
	}
}

void	draw_map(t_head *head, t_cor **map)
{
	int	x;
	int	y;

	y = -1;
	if (head->map_x == 1 && head->map_y == 1)
		ft_pixel_put(head, map[0][0].x, map[0][0].y, map[0][0].color);
	while (++y < head->map_y)
	{
		x = -1;
		while (++x < head->map_x)
		{
			if (x + 1 != head->map_x)
				ft_put_line(map[y][x], map[y][x], map[y][x + 1], head);
			if (y + 1 != head->map_y)
				ft_put_line(map[y][x], map[y][x], map[y + 1][x], head);
		}
	}
	mlx_put_image_to_window(head->init.mlx_ptr, head->init.win_ptr,
										head->init.img_ptr, 0, 0);
}
