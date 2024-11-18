/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:42:18 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/18 15:47:28 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************************************************** */
/*  Function for free all nodes, but i keep the content before \n             */
/* ************************************************************************** */
void	stash_free(t_list **stash)
{
	t_list	*tmp;
	t_list	*current;
	char	*new_content;
	int		newline_i;
	int		start;

	current = *stash;
	while (current)
	{
		newline_i = ft_strichr(current->content, '\n');
		if (newline_i >= 0)
		{
			start = newline_i + 1;
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

/* ************************************************************************** */
/*  Just strlen, but for a chainlist                                          */
/* ************************************************************************** */
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

/* ************************************************************************** */
/*  Function for load all nodes in a chainlist, to put them in str            */
/* ************************************************************************** */
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
		while (stash->content[i])
		{
			(*str)[j++] = stash->content[i++];
			if (stash->content[i - 1] == '\n')
				break ;
		}
		stash = stash->next;
	}
	(*str)[j] = '\0';
}

/* ************************************************************************** */
/*  Function for save all buffer's in a chained list                          */
/* ************************************************************************** */
void	stash_save(int fd, t_list **stash)
{
	char	*buffer;
	int		i;

	i = 1;
	buffer = malloc((BUFFER_SIZE + 1) * sizeof(char));
	if (!buffer)
		return ;
	while (!*stash || ft_strichr(ft_lstlast(*stash)->content, '\n') == -1)
	{
		i = read(fd, buffer, BUFFER_SIZE);
		if (i <= 0)
		{
			free(buffer);
			return ;
		}
		buffer[i] = '\0';
		ft_lstadd_back(stash, ft_lstnew_str(buffer, i));
	}
	free(buffer);
}

/* ************************************************************************** */
/*  Main function of the project                                              */
/* ************************************************************************** */
char	*get_next_line(int fd)
{
	static t_list	*stash = NULL;
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash_save(fd, &stash);
	if (stash == NULL)
		return (NULL);
	stash_load(stash, &str);
	if (!str)
		return (NULL);
	stash_free(&stash);
	if (str[0] == '\0')
	{
		stash = NULL;
		free(str);
		return (NULL);
	}
	return (str);
}

/* ************************************************************************** */
/*  Main for one fd :)                                                        */
/* ************************************************************************** */
//#include <stdio.h>
//#include <fcntl.h>
//
//int	main(void)
//{
//	int		fd1;
//	char	*str;
//
//	fd1 = open("labible", O_RDONLY);
//	while (1)
//	{
//		str = get_next_line(fd1);
//		printf("%s", str);
//		if (!str)
//			break ;
//		free(str);
//	}
//	return (0);
//}

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */
