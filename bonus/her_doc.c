/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   her_doc.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/14 12:45:00 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/16 13:26:12 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	managing_heredoc(char *delim)
{
	char	*line;
	int		tmp_fd;

	delim = ft_strjoin(delim, "\n");
	tmp_fd = open("/tmp/herdoc", O_CREAT | O_RDWR, 0777);
	if (tmp_fd < 0)
	{
		perror("open");
		exit(EXIT_FAILURE);
	}
	while (1)
	{
		write(STDOUT_FILENO, "heredoc> ", 10);
		line = get_next_line(STDIN_FILENO);
		if (ft_strncmp(line, delim, ft_strlen(line)) == 0)
			break ;
		write(tmp_fd, line, ft_strlen(line));
		free(line);
	}
	free(line);
	close(tmp_fd);
	tmp_fd = open("/tmp/herdoc", O_CREAT | O_RDWR, 0777);
	dup2(tmp_fd, STDIN_FILENO);
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
