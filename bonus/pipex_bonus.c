/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 22:28:50 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/13 11:59:35 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	change_fd_ouput(int fd, int cfd)
{
	if (dup2(fd, STDOUT_FILENO) < 0)
		perror("dup2 failed");
	close(cfd);
}

int	main(int argc, char **argv)
{
	int		fd_in;
	int		fd_out;
	int		i;
	t_cmd	*cmds;

	cmds = NULL;
	i = 2;
	if (argc >= 5)
	{
		fd_in = open(argv[1], O_RDWR);
		if (fd_in < 0)
			perror(argv[1]);
		fd_out = open(argv[argc -1], O_RDWR);
		if (fd_out < 0)
			perror(argv[4]);
		while (i < argc - 1)
		{
			creat_list(argv[i], &cmds);
			i++;
		}
		execut_(&cmds, fd_in, fd_out);
	}
}
