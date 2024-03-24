/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:50:06 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/24 01:00:41 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	managing_heredoc(char *delim)
{
	char	*line;
	int		tmp_fd;

	delim = ft_strjoin(delim, "\n");
	if (access("/tmp/herdoc", F_OK) == 0)
		unlink("/tmp/herdoc");
	tmp_fd = open_file("/tmp/herdoc", 'o');
	while (1)
	{
		write(STDOUT_FILENO, "pipe heredoc> ", 15);
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, delim, ft_strlen(line)) == 0)
			break ;
		write(tmp_fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(tmp_fd);
	tmp_fd = open_file("/tmp/herdoc", 'h');
	if (dup2(tmp_fd, STDIN_FILENO) == -1)
		perror("dup2 failed");
	close(tmp_fd);
	free(delim);
}

int	ft_lstsize1(t_cmd *lst)
{
	int	count;

	count = 0;
	if (!lst)
		return (count);
	while (lst)
	{
		count++;
		lst = lst->next;
	}
	return (count);
}

