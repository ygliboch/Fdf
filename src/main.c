/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/11 12:13:42 by yhliboch          #+#    #+#             */
/*   Updated: 2019/03/11 12:13:43 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	start(t_head *head)
{
	head->iso_map = NULL;
	head->map = NULL;
	head->rot_map = NULL;
	head->p_map = NULL;
	head->init.mlx_ptr = mlx_init();
	head->init.win_ptr = mlx_new_window(head->init.mlx_ptr,
										WIDTH, HEIGHT, "Fdf");
	head->init.img_ptr = mlx_new_image(head->init.mlx_ptr, WIDTH, HEIGHT);
	head->init.addr = mlx_get_data_addr(head->init.img_ptr, &head->bpp,
									&head->size_line, &head->endian);
	head->map_y = 1;
}

int		main(int argc, char **argv)
{
	t_head	head;
	int		x;

	if (argc != 2 || !(ft_strstr(argv[1], ".fdf")))
		error("usage: ./fdf source_file.fdf");
	start(&head);
	take_map(&head, open_file(argv[1]));
	mlx_hook(head.init.win_ptr, 2, 0, key, &head);
	mlx_hook(head.init.win_ptr, 17, 0, mause_close, head.init.mlx_ptr);
	draw_map(&head, head.map);
	mlx_loop(head.init.mlx_ptr);
	return (0);
}
