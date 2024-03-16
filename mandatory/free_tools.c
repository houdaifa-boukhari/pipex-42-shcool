/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_tools.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/13 20:06:27 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/13 20:19:56 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	*free_list(t_list **head)
{
	t_list	*ptr;

	ptr = *head;
	if (!head)
		return (NULL);
	while (*head)
	{
		ptr = (*head)->next;
		free((*head)->new_str);
		(*head)->new_str = NULL;
		free(*head);
		*head = ptr;
	}
	*head = NULL;
	return (NULL);
}

void	free_cmd_list(t_cmd **cmds)
{
	t_cmd	*tmp;

	while (*cmds)
	{
		tmp = (*cmds)->next;
		free_arrays((*cmds)->str);
		free(*cmds);
		*cmds = tmp;
	}
}

int	is_space(char c)
{
	if (c == ' ' || c == '\t')
		return (1);
	return (0);
}

int	skip_space(char *str, int i)
{
	while (str[i] && is_space(str[i]))
		i++;
	return (i);
}
