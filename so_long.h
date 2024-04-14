/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/19 18:10:27 by stopp             #+#    #+#             */
/*   Updated: 2024/03/23 19:19:32 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "lib/ft_printf.h"
# include <stdbool.h>
# include <limits.h>
# include "MLX42/include/MLX42/MLX42.h"

typedef struct s_position
{
	int		x;
	int		y;
}	t_posi;

typedef struct s_map
{
	int		width;
	int		height;
	int		to_collect;
	t_posi	start;
	t_posi	exit;
	char	**data;
}	t_map;

typedef struct s_data
{
	int				collected;
	int				move_counter;
	mlx_t			*mlx_ptr;
	mlx_image_t		*img_ptr[5];
	mlx_texture_t	*textures[5];
	t_map			*map;
	t_posi			current;
}	t_data;

int		int_error(char *message);
void	*null_error(char *message);
void	*chk_map(char *argv);
int		chk_map_values(t_map *map);
int		chk_walls(t_map *map);
void	free_array(char **array);
int		valid_path(t_map *map, t_posi start);
int		render_game(t_data *data);
void	control_keyhook(mlx_key_data_t keydata, void *param);
void	chk_exit(t_data *data, int x, int y);
void	free_game(t_data *data);
void	free_textures(mlx_texture_t **textures);
void	free_map(t_map *map);

#endif
