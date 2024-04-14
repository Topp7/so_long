/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   errors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/06 17:25:30 by stopp             #+#    #+#             */
/*   Updated: 2024/03/08 15:37:38 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	int_error(char *message)
{
	ft_printf("Error\n%s", message);
	return (0);
}

void	*null_error(char *message)
{
	ft_printf("Error\n%s", message);
	return (NULL);
}
