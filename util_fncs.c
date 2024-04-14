/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util_fncs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 16:03:08 by stopp             #+#    #+#             */
/*   Updated: 2024/03/23 19:18:02 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	free_array(char **array)
{
	int	i;

	i = 0;
	while (array[i])
		free(array[i++]);
	free(array);
}

void	free_map(t_map *map)
{
	free_array(map->data);
	free(map);
}

void	free_textures(mlx_texture_t **textures)
{
	int	i;

	i = 0;
	while (i < 5)
		mlx_delete_texture(textures[i++]);
}

void	free_game(t_data *data)
{
	free_array(data->map->data);
	free(data->map);
	free(data);
}

void	chk_exit(t_data *data, int x, int y)
{
	if (data->map->data[x][y] != 'E')
	{
		data->map->data[x][y] = '0';
		mlx_image_to_window(data->mlx_ptr, data->img_ptr[0],
			y * 32, x * 32);
	}
	else
	{
		mlx_image_to_window(data->mlx_ptr, data->img_ptr[0],
			y * 32, x * 32);
		mlx_image_to_window(data->mlx_ptr, data->img_ptr[2],
			y * 32, x * 32);
	}
}
