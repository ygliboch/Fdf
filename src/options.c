/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   options.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/15 17:04:21 by yhliboch          #+#    #+#             */
/*   Updated: 2019/03/15 17:04:23 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	key_zm(int keycode, t_head *head)
{
	if (keycode == 19)
		p_map(head);
	if (keycode == 18)
		iso_map(head);
	if (keycode == KEY_PLUS)
		zoom(head, '+');
	if (keycode == KEY_MINUS)
		zoom(head, '-');
	if (keycode == KEY_U)
		move(head, '8');
	if (keycode == KEY_D)
		move(head, '2');
	if (keycode == KEY_L)
		move(head, '4');
	if (keycode == KEY_R)
		move(head, '6');
}

int		key(int keycode, t_head *head)
{
	static t_iso	*iso;

	if (keycode == 53)
		exit(0);
	if (iso == NULL)
	{
		iso = ft_memalloc(sizeof(t_iso));
		iso->x = 0.0;
		iso->y = 0.0;
		iso->z = 0.0;
	}
	ft_bzero(head->init.addr, WIDTH * HEIGHT * 4);
	if (keycode == KEY_RIGHT)
		rotation(head, &iso, 'y');
	if (keycode == KEY_LEFT)
		rotation(head, &iso, 'z');
	if (keycode == KEY_UP)
		rotation(head, &iso, 'x');
	key_zm(keycode, head);
	return (1);
}

int		mause_close(void *mlx_ptr)
{
	(void)mlx_ptr;
	exit(0);
	return (1);
}

int		open_file(char *file)
{
	int	fd;

	if ((fd = open(file, O_DIRECTORY)) > 0)
		error("open directory is invalid");
	if ((fd = open(file, O_RDONLY)) < 0)
		error("invalid file");
	return (fd);
}
