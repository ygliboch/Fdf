/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   valid.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yhliboch <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/26 09:37:45 by yhliboch          #+#    #+#             */
/*   Updated: 2019/03/26 09:37:46 by yhliboch         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

void	error(char *str)
{
	ft_printf("%s\n", str);
	exit(0);
}

int		check_color(char *str, size_t *i)
{
	int count;

	count = 0;
	if (!(ft_isdigit(str[*i - 1])) || str[*i += 1] != '0'
					|| (str[*i += 1] != 'x' && str[*i] != 'X'))
		return (0);
	(*i)++;
	while (str[*i] && ft_strchr("abcdefABCDEF0123456789", str[*i]))
	{
		(*i)++;
		count++;
	}
	if (count > 6)
		return (0);
	return (1);
}

int		check_str(char *str)
{
	size_t	i;
	int		count;

	i = -1;
	count = 0;
	while (str[++i])
		if (ft_strchr("0123456789", str[i]))
			count++;
	if (count == 0)
		return (0);
	i = 0;
	while (str[i])
	{
		if (!(ft_strchr("-0123456789 ,", str[i])))
			return (0);
		if (str[i] == ',')
			if (check_color(str, &i) == 0)
				return (0);
		if (str[i])
			i++;
	}
	return (1);
}

void	valid_map(t_head *head, char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		if (check_str(map[i]) == 0)
			error("invalid map");
		i++;
	}
	if (i < head->map_y)
		error("invalid file");
}
