/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:21:51 by gabpicci          #+#    #+#             */
/*   Updated: 2023/12/19 18:06:15 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PIPEX.H"

void error_func(void)
{
	perror("error");
	exit(EXIT_FAILURE);
}

int child(int ac, char **av, int *pipefd)
{
}