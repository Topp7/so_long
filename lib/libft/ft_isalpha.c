/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalpha.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: stopp <stopp@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/05 13:05:14 by stopp             #+#    #+#             */
/*   Updated: 2023/10/13 15:17:52 by stopp            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_isalpha(int c)
{
	if ((c < 65 || (c > 90 && c < 97) || c > 122))
		return (0);
	return (1);
}
// #include <stdio.h>
// int	main(void)
// {
// 	char	c;

// 	c = 'k';
// 	printf("%i", ft_isalpha(c));
// 	return (0);
// }