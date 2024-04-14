/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_chk.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:12:20 by stopp             #+#    #+#             */
/*   Updated: 2024/03/23 19:21:26 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <fcntl.h>

static int	linecount(char *file)
{
	int		lines;
	int		fd;
	char	*buf;

	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (0);
	lines = 0;
	buf = get_next_line(fd);
	while (buf)
	{
		free (buf);
		lines++;
		buf = get_next_line(fd);
	}
	close (fd);
	return (lines);
}

static void	replace_newlines(char *str)
{
	while (*str)
	{
		if (*str == '\n')
			*str = 0;
		str++;
	}
}

static void	*alloc_lines(int lines, char *file)
{
	int		fd;
	char	**map;
	int		i;

	if (lines <= 0)
		return (null_error("Mapfile Problem\n"));
	map = (char **)malloc((lines + 1) * (sizeof(char *)));
	if (!map)
		return (NULL);
	fd = open(file, O_RDONLY);
	if (fd <= 0)
		return (0);
	i = 0;
	map[lines] = NULL;
	while (lines > 0)
	{
		map[i] = get_next_line(fd);
		replace_newlines(map[i++]);
		lines--;
	}
	close (fd);
	return (map);
}

static int	chk_rectangular(t_map *map)
{
	int				i;
	unsigned long	len;

	i = 0;
	len = ft_strlen(map->data[0]);
	while (map->data[++i])
	{
		if (ft_strlen(map->data[i]) != len)
			return (0);
	}
	map->width = len;
	return (1);
}

void	*chk_map(char *file)
{
	t_map	*map;

	map = malloc(sizeof(t_map));
	if (!map)
		return (NULL);
	map->height = linecount(file);
	map->data = alloc_lines(map->height, file);
	if (!map->data)
		return (NULL);
	if (!chk_rectangular(map))
		return (free_map(map), null_error("map not rectangular\n"));
	map->to_collect = 0;
	if (!chk_map_values(map))
		return (free_map(map), NULL);
	if (!chk_walls(map))
		return (free_map(map),
			null_error("Walls are not surrounding the map\n"));
	if (!valid_path(map, map->start))
		return (free_map(map),
			null_error("No valid Path to the Exit or Collectable\n"));
	return (map);
}
