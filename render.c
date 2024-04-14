/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 15:41:47 by stopp             #+#    #+#             */
/*   Updated: 2024/04/11 18:07:24 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static int	put_textures(t_data *data)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		data->img_ptr[i] = mlx_texture_to_image(data->mlx_ptr,
				data->textures[i]);
		if (!data->img_ptr[i])
			return (0);
		i++;
	}
	return (1);
}

static void	put_images(t_data *data, char c, int x, int y)
{
	mlx_image_to_window(data->mlx_ptr, data->img_ptr[0], y * 32, x * 32);
	if (c == '1')
		mlx_image_to_window(data->mlx_ptr,
			data->img_ptr[1], y * 32, x * 32);
	if (c == 'P')
		mlx_image_to_window(data->mlx_ptr,
			data->img_ptr[4], y * 32, x * 32);
	if (c == 'E')
		mlx_image_to_window(data->mlx_ptr,
			data->img_ptr[2], y * 32, x * 32);
	if (c == 'C')
		mlx_image_to_window(data->mlx_ptr,
			data->img_ptr[3], y * 32, x * 32);
}

static void	render_backround(t_data *data)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	put_textures(data);
	while (data->map->data[x])
	{
		y = 0;
		while (data->map->data[x][y])
		{
			put_images(data, data->map->data[x][y], x, y);
			y++;
		}
		x++;
	}
}

static int	init_data(t_data *data)
{
	data->mlx_ptr = mlx_init(data->map->width * 32,
			data->map->height * 32, "Test", true);
	if (!data->mlx_ptr)
		return (0);
	data->textures[0] = &mlx_load_xpm42("assets/ground.xpm42")->texture;
	if (!data->textures[0])
		return (0);
	data->textures[1] = &mlx_load_xpm42("assets/wall.xpm42")->texture;
	if (!data->textures[1])
		return (0);
	data->textures[2] = &mlx_load_xpm42("assets/exit.xpm42")->texture;
	if (!data->textures[2])
		return (0);
	data->textures[3] = &mlx_load_xpm42("assets/collectable.xpm42")->texture;
	if (!data->textures[3])
		return (0);
	data->textures[4] = &mlx_load_xpm42("assets/player.xpm42")->texture;
	if (!data->textures[4])
		return (0);
	return (1);
}

int	render_game(t_data *data)
{
	init_data(data);
	if (!data)
		return (0);
	render_backround(data);
	data->move_counter = 0;
	data->current.x = data->map->start.x;
	data->current.y = data->map->start.y;
	mlx_key_hook(data->mlx_ptr, control_keyhook, data);
	mlx_loop(data->mlx_ptr);
	free_textures(data->textures);
	mlx_terminate(data->mlx_ptr);
	return (1);
}
