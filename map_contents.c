/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_contents.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/09 19:13:47 by stopp             #+#    #+#             */
/*   Updated: 2024/04/10 18:18:45 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	chk_start_exit(char value)
{
	static int	p;
	static int	e;

	if (value == 'P')
		p++;
	if (value == 'E')
		e++;
	if (e != 1 || p != 1)
		return (0);
	else
		return (1);
}

static void	save_start_exit(t_map *map, int i, int j, char c)
{
	if (c == 'P')
	{
		map->start.x = i;
		map->start.y = j;
	}
	if (c == 'E')
	{
		map->exit.x = i;
		map->exit.y = j;
	}
}

static void	c_counter(t_map *map, char c)
{
	if (c == 'C')
		map->to_collect++;
}

int	chk_map_values(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if (map->data[i][j] != '1' && map->data[i][j] != '0' &&
				map->data[i][j] != 'P' && map->data[i][j] != 'E' &&
				map->data[i][j] != 'C')
				return (int_error("Map invalid\n"));
			chk_start_exit(map->data[i][j]);
			save_start_exit(map, i, j, map->data[i][j]);
			c_counter(map, map->data[i][j++]);
		}
		i++;
	}
	if (!chk_start_exit('0'))
		return (int_error("Not exactly 1 Start or Exit\n"));
	if (map->to_collect < 1)
		return (int_error("No collectable in Map\n"));
	return (1);
}

int	chk_walls(t_map *map)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map->data[i])
	{
		j = 0;
		while (map->data[i][j])
		{
			if ((i == 0 && map->data[i][j] != '1')
				|| (j == 0 && map->data[i][j] != '1'))
				return (0);
			if ((i == (map->height - 1) && map->data[i][j] != '1')
				|| (j == (map->width - 1) && map->data[i][j] != '1'))
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
