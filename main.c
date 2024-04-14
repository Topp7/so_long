/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 15:45:01 by stopp             #+#    #+#             */
/*   Updated: 2024/03/24 17:02:51 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	main(int argc, char **argv)
{
	t_data	*data;
	int		i;

	i = 0;
	if (argc != 2)
		return (int_error("Invalid Arguments\n"));
	if (ft_strncmp(&argv[1][ft_strlen(argv[1]) - 4], ".ber", 4) != 0)
		return (int_error("wrong filetype\n"));
	data = malloc(sizeof(t_data));
	if (!data)
		return (0);
	data->map = chk_map(argv[1]);
	if (!data->map)
		return (free(data), 0);
	render_game(data);
	free_game(data);
	return (0);
}
