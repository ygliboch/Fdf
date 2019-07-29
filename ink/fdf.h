/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/04 11:44:05 by yhliboch          #+#    #+#             */
/*   Updated: 2019/07/29 13:36:43 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft.h"
# include <mlx.h>
# include <math.h>
# define WIDTH 1000
# define HEIGHT 1000
# define KEY_LEFT 123
# define KEY_RIGHT 124
# define KEY_UP 126
# define KEY_PLUS 69
# define KEY_MINUS 78
# define DEFOLT_COLOR 0xffffff
# define COLOR1 0x00ff7f
# define COLOR2 0xff8c00
# define COLOR3 0xff0000
# define COLOR4 0x8b0000
# define ANGEL 0.05
# define KEY_U 91
# define KEY_D 84
# define KEY_L 86
# define KEY_R 88

typedef struct	s_cor
{
	int			x;
	int			y;
	int			z;
	int			color;
}				t_cor;

typedef struct	s_iso
{
	double		x;
	double		y;
	double		z;
}				t_iso;

typedef struct	s_init
{
	void		*mlx_ptr;
	void		*win_ptr;
	void		*img_ptr;
	char		*addr;
}				t_init;

typedef struct	s_head
{
	t_init		init;
	t_cor		**map;
	t_cor		**iso_map;
	t_cor		**rot_map;
	t_cor		**p_map;
	int			map_x;
	int			map_y;
	int			bpp;
	int			endian;
	int			size_line;
	int			fl;
}				t_head;

void			take_map(t_head *head, int fd);
void			draw(t_head *head);
void			draw_map(t_head *head, t_cor **map);
t_cor			new_cor(int x, int y);
void			rotation(t_head *head, t_iso **iso, char exis);
int				key(int keycode, t_head *head);
int				mause_close(void *mlx_ptr);
void			zoom(t_head *head, char exis);
void			move(t_head *head, char exis);
void			iso_map(t_head *head);
void			del_map(t_cor **map, t_head *head);
int				color(t_cor current, t_cor start, t_cor end, t_cor delta);
int				which_color(int z);
void			valid_map(t_head *head, char **map);
void			error(char *str);
void			p_map(t_head *head);
int				open_file(char *file);

#endif
