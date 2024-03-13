/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:26:55 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/13 11:33:27 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	management_fd(int fd_in, int fd_out)
{
	if (dup2(fd_in, STDIN_FILENO) < 0)
		perror("dup2 failed");
	if (dup2(fd_out, STDOUT_FILENO) < 0)
		perror("dup2 failed");
}

int	main(int argc, char **argv)
{
	int		fd_in;
	int		fd_out;
	t_cmd	*cmd;

	if (argc == 5)
	{
		fd_in = open(argv[1], O_RDWR);
		if (fd_in < 0)
			perror(argv[1]);
		fd_out = open(argv[4], O_RDWR);
		if (fd_out < 0)
			perror(argv[4]);
		// execut_(ft_split(argv[2]), ft_split(argv[3]), fd_in, fd_out);
	}
}
