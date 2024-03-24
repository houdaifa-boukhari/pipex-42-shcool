/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_lists_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:42:39 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/24 00:54:23 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

void	creat_list(char *cmd, t_cmd **head)
{
	t_cmd	*cmds;
	t_cmd	*ptr;

	if (!cmd || !head)
		return ;
	cmds = malloc(sizeof(t_cmd));
	if (!cmds)
		return ;
	cmds->str = smart_split(cmd);
	cmds->next = NULL;
	if (!*head)
	{
		*head = cmds;
		return ;
	}
	ptr = *head;
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = cmds;
}

int	ft_lstsize(t_list *lst)
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

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*ptr;

	ptr = *lst;
	if (!lst || !new)
		return ;
	if (!(*lst))
	{
		*lst = new;
		return ;
	}
	while (ptr->next)
		ptr = ptr->next;
	ptr->next = new;
}

t_list	*ft_lstnew(void *content)
{
	t_list	*new_node;

	new_node = (t_list *)malloc(sizeof(t_list));
	if (new_node == NULL)
		return (NULL);
	new_node -> new_str = content;
	new_node -> next = NULL;
	return (new_node);
}

int	first_found(char *str, char c, int idx)
{
	if (!str || idx < 0 || idx > ft_strlen(str))
		return (0);
	while (str[idx])
	{
		if (str[idx] == '\\' && str[idx + 2])
		{
			idx += 2;
			continue ;
		}
		else if (str[idx] == c)
			return (idx);
		idx++;
	}
	return (0);
}
