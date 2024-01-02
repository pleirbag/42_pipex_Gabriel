/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gabpicci <gabpicci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 17:13:36 by gabpicci          #+#    #+#             */
/*   Updated: 2023/12/26 21:34:28 by gabpicci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <sys/types.h>
# include <sys/wait.h>
# include<sys/types.h>
# include<sys/stat.h>
# include <fcntl.h>  
# include <stdlib.h>
# include <errno.h> 

void error_func(void);
char	*access_path(char **env_path, char *cmd);
char	**ft_split(char const *s, char c);
int	ft_strncmp(const char *s1, const char *s2, size_t n);

#endif