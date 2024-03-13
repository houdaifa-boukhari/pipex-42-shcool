/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_environ_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:51:17 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/13 15:24:31 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*get_environ(char *cmd)
{
	int		i;
	char	**dir;
	char	*full_path;

	i = 0;
	if (access(cmd, X_OK) == 0)
		return (cmd);
	cmd = ft_strjoin("/", cmd);
	while (environ[i])
	{
		full_path = ft_strnstr(environ[i], "PATH", 4);
		if (full_path)
			break ;
		i++;
	}
	full_path = ft_substr(full_path, 5, ft_strlen(full_path + 5));
	dir = split_(full_path, ':');
	free(full_path);
	return (get_path(dir, cmd));
}

char	*get_path(char **dir, char *cmd)
{
	int		i;
	char	*tmp;
	char	*path;

	i = 0;
	path = NULL;
	while (dir[i])
	{
		tmp = ft_strjoin(dir[i], cmd);
		if (access(tmp, X_OK) == 0)
		{
			path = (ft_substr(tmp, 0, ft_strlen(tmp)));
			break ;
		}
		free(tmp);
		i++;
	}
	free_arrays(dir), dir = NULL;
	free(cmd), cmd = NULL;
	return (path);
}

void	execut_(t_cmd **cmds, int fd_in, int fd_out)
{
	int		fd[2];
	char	*path;
	int		id;

	while (cmds)
	{
		pipe(fd);
		id = fork();
		if (id == 0)
		{
			dup2(fd_in, 0);
			if ((*cmds)->next)
				change_fd_ouput(fd[1], fd[0]);
			else
				change_fd_ouput(fd_out, fd[1]);
			close(fd[0]);
			path = get_environ((*cmds)->str[0]);
			execve(path, (*cmds)->str, environ);
		}
		else 
		{
			if (!(*cmds)->next)
			{
				free_cmd_list(cmds);
				// system("leaks pipex");
				exit(0);
			}
			wait(NULL);
			close(fd[1]);
			fd_in = fd[0];
			(*cmds) = (*cmds)->next;
		}
	}
}
