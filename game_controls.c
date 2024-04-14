/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   game_controls.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/15 18:02:27 by stopp             #+#    #+#             */
/*   Updated: 2024/03/22 18:20:32 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

static void	move_player_up(t_data *data)
{
	int	x;
	int	y;

	x = data->current.x;
	y = data->current.y;
	if (data->map->data[x - 1][y] != '1')
	{
		ft_printf("Moves: %i\n", ++(data->move_counter));
		chk_exit(data, x, y);
		if (data->map->data[--x][y] == 'C')
			data->collected++;
		if (data->map->data[x][y] != 'E')
			mlx_image_to_window(data->mlx_ptr, data->img_ptr[0],
				y * 32, x * 32);
		else if (data->collected == data->map->to_collect)
		{
			ft_printf("Congrats! Won in %i moves\n", data->move_counter);
			mlx_close_window(data->mlx_ptr);
		}
		else
			ft_printf("You're missing Collectables!\n");
		mlx_image_to_window(data->mlx_ptr, data->img_ptr[4], y * 32, x * 32);
	}
	data->current.x = x;
	data->current.y = y;
}

static void	move_player_down(t_data *data)
{
	int	x;
	int	y;

	x = data->current.x;
	y = data->current.y;
	if (data->map->data[x + 1][y] != '1')
	{
		ft_printf("Moves: %i\n", ++(data->move_counter));
		chk_exit(data, x, y);
		if (data->map->data[++x][y] == 'C')
			data->collected++;
		if (data->map->data[x][y] != 'E')
			mlx_image_to_window(data->mlx_ptr, data->img_ptr[0],
				y * 32, x * 32);
		else if (data->collected == data->map->to_collect)
		{
			ft_printf("Congrats! Won in %i moves\n", data->move_counter);
			mlx_close_window(data->mlx_ptr);
		}
		else
			ft_printf("You're missing Collectables!\n");
		mlx_image_to_window(data->mlx_ptr, data->img_ptr[4], y * 32, x * 32);
	}
	data->current.x = x;
	data->current.y = y;
}

static void	move_player_left(t_data *data)
{
	int	x;
	int	y;

	x = data->current.x;
	y = data->current.y;
	if (data->map->data[x][y - 1] != '1')
	{
		ft_printf("Moves: %i\n", ++(data->move_counter));
		chk_exit(data, x, y);
		if (data->map->data[x][--y] == 'C')
			data->collected++;
		if (data->map->data[x][y] != 'E')
			mlx_image_to_window(data->mlx_ptr, data->img_ptr[0],
				y * 32, x * 32);
		else if (data->collected == data->map->to_collect)
		{
			ft_printf("Congrats! Won in %i moves\n", data->move_counter);
			mlx_close_window(data->mlx_ptr);
		}
		else
			ft_printf("You're missing Collectables!\n");
		mlx_image_to_window(data->mlx_ptr, data->img_ptr[4], y * 32, x * 32);
	}
	data->current.x = x;
	data->current.y = y;
}

static void	move_player_right(t_data *data)
{
	int	x;
	int	y;

	x = data->current.x;
	y = data->current.y;
	if (data->map->data[x][y + 1] != '1')
	{
		ft_printf("Moves: %i\n", ++(data->move_counter));
		chk_exit(data, x, y);
		if (data->map->data[x][++y] == 'C')
			data->collected++;
		if (data->map->data[x][y] != 'E')
			mlx_image_to_window(data->mlx_ptr, data->img_ptr[0],
				y * 32, x * 32);
		else if (data->collected == data->map->to_collect)
		{
			ft_printf("Congrats! Won in %i moves\n", data->move_counter);
			mlx_close_window(data->mlx_ptr);
		}
		else
			ft_printf("You're missing Collectables!\n");
		mlx_image_to_window(data->mlx_ptr, data->img_ptr[4], y * 32, x * 32);
	}
	data->current.x = x;
	data->current.y = y;
}

void	control_keyhook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = param;
	if (keydata.action == MLX_RELEASE)
	{
		if (keydata.key == MLX_KEY_ESCAPE)
		{
			mlx_close_window(data->mlx_ptr);
			ft_printf("you gave up :(\n");
		}
		else if (keydata.key == MLX_KEY_W)
			move_player_up(data);
		else if (keydata.key == MLX_KEY_A)
			move_player_left(data);
		else if (keydata.key == MLX_KEY_S)
			move_player_down(data);
		else if (keydata.key == MLX_KEY_D)
			move_player_right(data);
	}
}
