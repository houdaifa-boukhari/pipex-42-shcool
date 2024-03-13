/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 11:35:18 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/13 15:26:37 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/wait.h>
# include <sys/types.h>
# include <stdlib.h>
# include <string.h>
# include <errno.h>

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

extern char		**environ;
char	*ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_strncmp(const char *s1, const char *s2, size_t n);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int		ft_strlen(const char *s);
char	*get_environ(char *cmd);
char	**split_(char const *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
void	*free_arrays(char **str);
char	*get_path(char **dir, char *cmd);
void	execut_(t_cmd **cmds, int fd_in, int fd_out);
void	management_fd(int fd_in, int fd_out);
void	creat_list(char *cmd, t_cmd **head);
void	change_fd_ouput(int fd, int cfd);
char	*ft_strtrim(char *s1, char *set);
t_list	*smart_split(char *str);
int		ft_lstsize(t_list *lst);
char	**built2d_array(char *str, t_list *cmd);
int		first_found(char *str, char c, int idx);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstnew(void *content);
void	*free_list(t_list **head);
void free_cmd_list(t_cmd **cmds);

#endif