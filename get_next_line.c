/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:42:18 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/08 23:32:27 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

void	stash_free(t_list **stash)
{
	t_list	*tmp;
	t_list	*current;
	char	*new_content;
	char	*newline_pos;
	int		start;

	current = *stash;
	while (current)
	{
		newline_pos = ft_strchr(current->content, '\n');
		if (newline_pos)
		{
			start = newline_pos - current->content + 1;
			new_content = ft_substrlen(current->content, start);
			free(current->content);
			current->content = new_content;
			break ;
		}
		tmp = current->next;
		free(current->content);
		free(current);
		current = tmp;
	}
	*stash = current;
}

int	stash_strlinelen(t_list *stash)
{
	int	len;
	int	i;

	len = 0;
	while (stash)
	{
		i = 0;
		while (stash->content[i])
		{
			len++;
			if (stash->content[i] == '\n')
				break ;
			i++;
		}
		stash = stash->next;
	}
	return (len);
}

void	stash_load(t_list *stash, char **str)
{
	int	i;
	int	j;

	j = 0;
	if (!stash)
		return ;
	*str = malloc((stash_strlinelen(stash) + 1) * sizeof(char));
	if (!*str)
		return ;
	while (stash)
	{
		i = 0;
		while (stash->content != NULL && stash->content[i])
		{
			(*str)[j++] = stash->content[i++];
			if (stash->content[i - 1] == '\n')
				break ;
		}
		if (stash->content[i] == '\n')
			break ;
		stash = stash->next;
	}
	(*str)[j] = '\0';
}

void	stash_save(int fd, t_list **stash, int *i)
{
	char	*buffer;

	while ((!*stash || !ft_strchr(ft_lstlast(*stash)->content, '\n')) && *i > 0)
	{
		buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
		if (!buffer)
			return ;
		*i = read(fd, buffer, BUFFER_SIZE);
		if (*i <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[*i] = '\0';
		ft_lstadd_back(stash, ft_lstnew_str(buffer, *i));
		free(buffer);
	}
}

char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*str;
	int				count;

	count = 1;
	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash_save(fd, &stash, &count);
	if (!stash)
		return (NULL);
	stash_load(stash, &str);
	stash_free(&stash);
	return (str);
}
