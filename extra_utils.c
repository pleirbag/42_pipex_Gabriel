/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   extra_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 13:47:23 by gabpicci          #+#    #+#             */
/*   Updated: 2024/03/02 18:17:44 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	print_str(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		write(2, &str[i++], 1);
	write(2, "\n", 1);
}

int	detect_empty_argument(char **av)
{
	int	i;

	i = 0;
	while (i++ <= 3)
	{
		if (av[i][0] == 0 || av[i][0] == 32)
			return (0);
	}
	return (1);
}
