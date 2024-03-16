/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:28:50 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/16 17:58:22 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	change_fd_ouput(int fd, int cfd)
{
	if (dup2(fd, STDOUT_FILENO) < 0)
		perror("dup2 failed");
	close(cfd);
}

int	open_file(char *name, char c)
{
	int	fd;

	if (c == 'i')
		fd = open(name, O_RDWR);
	else
		fd = open(name, O_CREAT | O_RDWR, 0777);
	if (fd < 0)
	{
		perror(name);
		exit(EXIT_FAILURE);
	}
	return (fd);
}

void	handle_input(char **argv, int *i, t_fd *fd)
{
	if (ft_strncmp("here_doc", argv[1], ft_strlen(argv[1])) == 0)
	{
		*i = 3;
		managing_heredoc(argv[2]);
		fd->fd_in = STDIN_FILENO;
	}
	else
	{
		fd->fd_in = open_file(argv[1], 'i');
		*i = 2;
	}
}

int	main(int argc, char **argv, char **envp)
{
	t_fd	fd;
	t_cmd	*cmds;
	int		i;

	cmds = NULL;
	if (argc >= 5)
	{
		handle_input(argv, &i, &fd);
		fd.fd_out = open_file(argv[argc -1], 'o');
		while (i < argc - 1)
			creat_list(argv[i++], &cmds);
		execut_(cmds, envp, fd);
		free_cmd_list(&cmds);
	}
	else
	{
		write(STDOUT_FILENO, "use ./pipex infile cmd1 cmd2 ... outfile\n", 41);
		exit(127);
	}
}
