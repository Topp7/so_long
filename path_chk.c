/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   path_chk.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 15:00:07 by stopp             #+#    #+#             */
/*   Updated: 2024/03/22 18:28:56 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static char	**init_visited(t_map *map, char **visited)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	while (map->data[i])
	{
		j = 0;
		visited[i] = malloc(map->width * sizeof(char));
		if (!visited)
			return (NULL);
		while (map->data[i][j])
		{
			if (map->data[i][j] == '1')
				visited[i][j] = 'W';
			else if (map->data[i][j] == 'P')
				visited[i][j] = 'y';
			else
				visited [i][j] = 'n';
			j++;
		}
		i++;
	}
	visited[map->height] = NULL;
	return (visited);
}

static void	init_directions(int *d, char xy)
{
	if (xy == 'x')
	{
		d[0] = 0;
		d[1] = 1;
		d[2] = 0;
		d[3] = -1;
	}
	if (xy == 'y')
	{
		d[0] = 1;
		d[1] = 0;
		d[2] = -1;
		d[3] = 0;
	}
}

int	add_to_queue(t_posi *queue, char **visited, t_posi current, int rear)
{
	int	dx[4];
	int	dy[4];
	int	i;

	init_directions(dx, 'x');
	init_directions(dy, 'y');
	i = 0;
	while (i < 4)
	{
		if (visited[current.x + dx[i]][current.y + dy[i]] == 'n')
		{
			queue[rear].x = current.x + dx[i];
			queue[rear].y = current.y + dy[i];
			visited[queue[rear].x][queue[rear].y] = 'y';
			rear++;
		}
		i++;
	}
	return (rear);
}

static int	search_path(t_posi *queue, char **visited, t_map *map)
{
	int		front;
	int		rear;
	int		collectables;
	int		exit;
	t_posi	current;

	front = 0;
	rear = 1;
	collectables = 0;
	exit = 0;
	while (front < rear)
	{
		current = queue[front++];
		if (map->data[current.x][current.y] == 'E')
			exit++;
		if (map->data[current.x][current.y] == 'C')
			collectables++;
		if (exit == 1 && collectables == map->to_collect)
			return (1);
		rear = add_to_queue(queue, visited, current, rear);
	}
	return (0);
}

int	valid_path(t_map *map, t_posi start)
{
	char	**visited;
	t_posi	*queue;

	queue = malloc((map->width * map->height) * sizeof(t_posi));
	if (!queue)
		return (0);
	visited = malloc((map->height + 1) * sizeof(char *));
	if (!visited)
		return (free (queue), 0);
	visited = init_visited(map, visited);
	if (!visited)
		return (free (queue), 0);
	visited[map->height] = NULL;
	queue[0] = start;
	if (!search_path(queue, visited, map))
	{
		free(queue);
		free_array(visited);
		return (0);
	}
	free(queue);
	free_array(visited);
	return (1);
}
