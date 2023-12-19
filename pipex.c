/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:10:40 by gabpicci          #+#    #+#             */
/*   Updated: 2023/12/19 22:24:15 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "PIPEX.H"

void	parent_cmd2()
{
	int fd;

	fd = open(av[1], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if	(fd < 0)
		error_func();
	close(pipefd[0]);
	dup2(pipefd[0], STDIN_FILENO);
	dup2(fd, STDOUT_FILENO);
	close(fd);
	prcss(av[2], env);
}

void	child_cmd1()
{
	int fd;

	fd = open(av[4], O_RDONLY);
	if	(fd < 0)
		error_func();
	close(pipefd[0]);
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(fd);
	prcss(av[2], env);
}	

int	main(int ac, char **av, char **env)
{
	int pipefd[2];
	int pid;

	pid = fork();
	if (ac != 5)
		error_func() /*change message*/
	if (pid < 0)
		error_func();
	if (pipe(pipefd) == -1)
		return (-1);
	if (!pid)
	{ 
		child_cmd1(av, env, pipefd);
	}
	parent_cmd2(av, env, pipefd);
}