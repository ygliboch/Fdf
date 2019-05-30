/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:09:08 by yhliboch          #+#    #+#             */
/*   Updated: 2019/03/14 17:58:27 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	del_ch_map(char **map, t_head *head)
{
	int	i;

	i = -1;
	while (++i < head->map_y)
		free(map[i]);
	free(map);
}

char	*next_num(char *str)
{
	char	*temp;
	char	*del;
	char	*del1;

	if (ft_strchr(temp, ' '))
	{
		temp = ft_strdup(str);
		del1 = temp;
		temp = temp + (ft_strchr(temp, ' ') - temp);
		while (*temp == ' ')
			temp++;
		free(str);
		str = ft_strdup(temp);
		free(del1);
	}
	else
	{
		temp = ft_strdup(str);
		del1 = temp;
		temp = temp + (ft_strchr(temp, '\0') - temp);
		free(str);
		str = ft_strdup(temp);
		free(del1);
	}
	return (str);
}

int		ind(t_head *head)
{
	int	indent;
	int	indent2;

	indent = WIDTH / (head->map_x + 2);
	indent2 = HEIGHT / (head->map_y + 1);
	return (indent < indent2 ? indent : indent2);
}

void	map_to_int(char **ch_map, t_head *head)
{
	int		i;
	int		j;
	int		indent;

	i = -1;
	head->map_x = ft_num_words(ch_map[0], ' ');
	valid_map(head, ch_map);
	head->map = (t_cor **)malloc(sizeof(t_cor *) * head->map_y);
	indent = ind(head);
	while (++i < head->map_y)
	{
		j = -1;
		head->map[i] = (t_cor *)malloc(sizeof(t_cor) * head->map_x);
		while (++j < head->map_x)
		{
			head->map[i][j].color = which_color(ft_atoi(ch_map[i]));
			head->map[i][j].z = ft_atoi(ch_map[i]) * (indent / 2);
			head->map[i][j].y = (i - (head->map_y / 2)) * indent;
			head->map[i][j].x = (j - (head->map_x / 2)) * indent;
			ch_map[i] = next_num(ch_map[i]);
		}
	}
	del_ch_map(ch_map, head);
}

void	take_map(t_head *head, int fd)
{
	char	*temp;
	char	*del;
	char	*line;

	get_next_line(fd, &line);
	if (line == NULL || line[0] == '\0')
		error("invalid map");
	temp = line;
	while (get_next_line(fd, &line))
	{
		del = temp;
		temp = ft_strjoin(temp, "\n");
		free(del);
		del = temp;
		temp = ft_strjoin(temp, line);
		free(del);
		free(line);
		head->map_y++;
	}
	map_to_int(ft_strsplit(temp, '\n'), head);
	ft_strdel(&temp);
	close(fd);
}
