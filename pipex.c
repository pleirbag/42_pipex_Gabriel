/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:10:40 by gabpicci          #+#    #+#             */
/*   Updated: 2024/03/02 18:21:54 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*ft_path(char *cmd, char **env)
{
	int		i;
	char	**env_path;
	char	*cmd_path;

	i = 0;
	while (ft_strncmp(env[i], "PATH=", 5))
		i++;
	env_path = ft_split(&env[i][5], ':');
	cmd_path = access_path(env_path, cmd);
	return (cmd_path);
}

void	prcss(char *cmd, char **env)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmd, 32);
	path = ft_path(split_cmd[0], env);
	if (execve(path, split_cmd, env) == -1)
		error_func(2);
}

void	child_cmd1(char **av, char **env, int *pipefd)
{
	int	fd;

	fd = open(av[1], O_RDONLY);
	if (fd < 0)
		error_func(1);
	dup2(fd, STDIN_FILENO);
	dup2(pipefd[1], STDOUT_FILENO);
	close(pipefd[0]);
	close(fd);
	prcss(av[2], env);
}

void	parent_cmd2(char **av, char **env, int *pipefd)
{
	int	fd;

	fd = open(av[4], O_TRUNC | O_CREAT | O_WRONLY, 0644);
	if (fd < 0)
		error_func(1);
	dup2(fd, STDOUT_FILENO);
	dup2(pipefd[0], STDIN_FILENO);
	close(pipefd[1]);
	close(fd);
	prcss(av[3], env);
}

int	main(int ac, char **av, char **env)
{
	int	pipefd[2];
	int	pid;
	int	pid2;

	if (ac != 5 || detect_empty_argument(av) == 0)
		error_func(0);
	if (pipe(pipefd) == -1)
		return (-1);
	pid = fork();
	if (pid < 0)
		error_func(3);
	if (!pid)
		child_cmd1(av, env, pipefd);
	pid2 = fork();
	close(pipefd[1]);
	if (pid2 < 0)
		error_func(3);
	if (!pid2)
		parent_cmd2(av, env, pipefd);
}
