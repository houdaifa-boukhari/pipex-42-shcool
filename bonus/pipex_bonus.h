/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 00:49:39 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/19 00:49:42 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_BONUS_H
# define PIPEX_BONUS_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <stdlib.h>
# include "../get_next_line/get_next_line.h"

typedef struct s_cmd
{
	char			**str;
	struct s_cmd	*next;
}					t_cmd;

typedef struct s_list
{
	char			*new_str;
	struct s_list	*next;
}					t_list;

typedef struct s_fd
{
	int	fd_in;
	int	fd_out;
	int	fd_p[2];
	int	pid;
}		t_fd;

char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *s);
int		open_file(char *name, char c);
char	*get_environ(char *cmd, char **envp);
char	**split_(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*free_arrays(char **str);
char	*get_path(char **dir, char *cmd);
void	execut_(t_cmd *cmds, char **envp, t_fd fd);
void	creat_list(char *cmd, t_cmd **head);
void	change_fd_ouput(int fd, int cfd);
char	*ft_strtrim(char *s1, char *set);
char	**smart_split(char *str);
int		ft_lstsize(t_list *lst);
char	**built2d_array(t_list *cmd);
int		first_found(char *str, char c, int idx);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
void	*free_list(t_list **head);
void	free_cmd_list(t_cmd **cmds);
int		skip_space(char *str, int i);
int		is_space(char c);
void	managing_heredoc(char *delim);
int		ft_lstsize1(t_cmd *lst);

#endif