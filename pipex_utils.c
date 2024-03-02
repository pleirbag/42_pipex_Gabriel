/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:21:51 by gabpicci          #+#    #+#             */
/*   Updated: 2024/03/02 18:33:02 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

void	error_func(int e)
{
	if (e == 0)
		print_str("Incorrect number of parameters");
	if (e == 1)
		print_str("Invalid FD or error loading file");
	if (e == 2)
		perror("Error at command execution time");
	if (e == 3)
		print_str("Error at fork time");
	if (e == 4)
		print_str("Error: Couldnt find the command");
	exit(EXIT_FAILURE);
}

char	*str_concat(char *s1, char *s2)
{
	int		i;
	int		j;
	char	*dest;

	i = -1;
	j = 0;
	dest = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!dest)
		return (NULL);
	while (s1[++i])
		dest[i] = s1[i];
	while (s2[j])
		dest[i++] = s2[j++];
	dest[i] = 0;
	return (dest);
}

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (0);
	while (s1[i] == s2[i] && s1[i] && i < n)
	{
		i++;
		if (i == n)
			return (0);
	}
	return ((unsigned char)s1[i] - (unsigned char)s2[i]);
}

char	*access_path(char **env_path, char *cmd)
{
	int		i;
	char	*temp;
	char	*cmd_path;

	i = -1;
	while (env_path[++i])
	{
		temp = str_concat(env_path[i], "/");
		cmd_path = str_concat(temp, cmd);
		free(temp);
		if (access(cmd_path, F_OK) != -1)
			return (cmd_path);
		free(cmd_path);
	}
	error_func(4);
	exit(127);
}
