/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools_string2_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hel-bouk <hel-bouk@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 17:32:32 by hel-bouk          #+#    #+#             */
/*   Updated: 2024/03/24 00:59:37 by hel-bouk         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex_bonus.h"

char	**built2d_array(t_list *cmd)
{
	char	**new_str;
	int		i;
	int		count_word;

	i = 0;
	if (!cmd)
		return (NULL);
	count_word = ft_lstsize(cmd);
	new_str = (char **)malloc(sizeof(char *) * (count_word + 1));
	if (!new_str)
		return (NULL);
	while (i < count_word)
	{
		if (cmd->new_str[0] == '\'')
			new_str[i++] = ft_strtrim(cmd->new_str, "'");
		else
			new_str[i++] = ft_strdup(cmd->new_str);
		cmd = cmd->next;
	}
	new_str[i] = NULL;
	return (new_str);
}

int	check(char c, char *delim)
{
	while (*delim)
	{
		if (*delim == c)
			return (1);
		delim++;
	}
	return (0);
}

char	*ft_strtrim(char *s1, char *set)
{
	int		start;
	int		end;
	char	*new_str;

	start = 0;
	if (!s1 || !set)
		return (NULL);
	end = ft_strlen(s1);
	if (s1[start] && check(s1[start], (char *)set))
		start++;
	if (check(s1[end - 1], (char *)set) && end > start)
		end--;
	new_str = ft_substr(s1, start, end - start);
	if (!new_str)
		return (NULL);
	return (new_str);
}

char	**smart_split(char *str)
{
	int		i;
	int		st;
	char	**new_str;
	t_list	*h;

	i = 0;
	h = NULL;
	while (str[i])
	{
		if (str[i] == '\'')
		{
			st = i;
			i = first_found(str, '\'', ++i);
			ft_lstadd_back(&h, ft_lstnew(ft_substr(str, st, i++ - st + 1)));
		}
		else if (str[i] && !is_space(str[i]))
		{
			st = i;
			while (str[i] && !is_space(str[i]))
				i++;
			ft_lstadd_back(&h, ft_lstnew(ft_substr(str, st, i - st)));
		}
		i = skip_space(str, i);
	}
	return (new_str = built2d_array(h), free_list(&h), new_str);
}
