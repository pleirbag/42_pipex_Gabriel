/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:10:40 by gabpicci          #+#    #+#             */
/*   Updated: 2023/12/26 22:26:00 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(char *cmd, char **env)
{
	int		i;
	char	**env_path;
	char	*cmd_path;

	i = 0;
	while(ft_strncmp(env[i], "PATH=", 5))
		i++;
	env_path = ft_split(&env[i][5], ':');
	cmd_path = access_path(env_path, cmd);
	return (cmd_path);
}

void	prcss(char *cmd, char **env)
{
	char **split_cmd;
	char *path;

	split_cmd = ft_split(cmd, 32);
	path = ft_path(split_cmd[0], env);
	if (execve(path, split_cmd, env) == -1)
		error_func();
}

void	child_cmd1(char **av, char **env, int *pipefd)
{
	int fd;

	fd = open(av[1], O_RDONLY);
	if	(fd < 0)
		error_func();
	dup2(pipefd[1], STDOUT_FILENO);
	dup2(fd, STDIN_FILENO);
	close(pipefd[1]);
	prcss(av[2], env);
	// close(fd);
}

void	parent_cmd2(char **av, char **env, int *pipefd)
{
	int fd;

	fd = open(av[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if	(fd < 0)
		error_func();
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[0]);
	prcss(av[3], env);
	// close(fd);
}	

int	main(int ac, char **av, char **env)
{
	int pipefd[2];
	int pid;

	pid = fork();
	if (ac != 5)
		error_func(); /*change message*/
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