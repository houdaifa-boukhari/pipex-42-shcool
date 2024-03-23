/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_environ_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:50:17 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/23 00:01:55 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	*get_environ(char *cmd, char **envp)
{
	int		i;
	char	**dir;
	char	*full_path;

	i = 0;
	if ((ft_strncmp(cmd, "./", 2) == 0) && (access(cmd, X_OK) == 0))
		return (cmd);
	else if ((ft_strncmp(cmd, "/", 1) == 0) && (access(cmd, X_OK) == 0))
		return (cmd);
	cmd = ft_strjoin("/", cmd);
	while (envp[i])
	{
		full_path = ft_strnstr(envp[i], "PATH", 4);
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
	free_arrays(dir);
	dir = NULL;
	return (path);
}

void	execute_child(t_cmd *cmd, char **envp, t_fd fd)
{
	char	*path;

	path = NULL;
	if (fd.fd_in != 0)
		dup2(fd.fd_in, 0);
	if (cmd->next)
		change_fd_ouput(fd.fd_p[1], fd.fd_p[0]);
	else
		change_fd_ouput(fd.fd_out, fd.fd_p[1]);
	close(fd.fd_p[0]);
	path = get_environ(cmd->str[0], envp);
	if (!path)
	{
		perror(cmd->str[0]);
		exit(127);
	}
	if (execve(path, cmd->str, envp) == -1)
	{
		perror("failed execution");
		exit(EXIT_FAILURE);
	}
}

void	wait_children(int *pids, int size)
{
	int	status;
	int	i;

	i = 0;
	while (i < size)
	{
		if (waitpid(pids[i], &status, 0) == -1)
		{
			perror("waitpid");
			exit(EXIT_FAILURE);
		}
		status = WEXITSTATUS(status);
		if (status == 127 && i == size - 1)
			exit(status);
		i++;
	}
	free(pids);
	unlink("/tmp/herdoc");
}

void	execut_(t_cmd *cmds, char **envp, t_fd fd)
{
	int		*pids;
	int		i;

	i = 0;
	pids = (int *)malloc(sizeof(int) * (ft_lstsize1(cmds)));
	if (!pids)
		return ;
	while (cmds)
	{
		pipe(fd.fd_p);
		fd.pid = fork();
		if (fd.pid == 0)
			execute_child(cmds, envp, fd);
		else 
		{
			pids[i++] = fd.pid; 
			close(fd.fd_p[1]);
			if (!cmds->next)
				break ;
			fd.fd_in = fd.fd_p[0];
			cmds = cmds->next;
		}
	}
	close(fd.fd_in);
	wait_children(pids, i);
}
