/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:42:18 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/18 17:49:48 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

/* ************************************************************************** */
/*  Function for free all nodes, but i keep the content before \n             */
/* ************************************************************************** */
void	stash_free(t_strlist **stash)
{
	t_strlist	*tmp;
	t_strlist	*current;
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
int	stash_strlinelen(t_strlist *stash)
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
void	stash_load(t_strlist *stash, char **str)
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
void	stash_save(int fd, t_strlist **stash)
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
			if (i == -1)
				stash_free(stash);
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
	static t_strlist	*stash[1024] = {NULL};
	char			*str;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	stash_save(fd, &stash[fd]);
	if (stash[fd] == NULL)
		return (NULL);
	stash_load(stash[fd], &str);
	if (!str)
		return (NULL);
	stash_free(&stash[fd]);
	if (str[0] == '\0')
	{
		stash[fd] = NULL;
		free(str);
		return (NULL);
	}
	return (str);
}

/* ************************************************************************** */
/*  Main for multiple fd :)                                                   */
/* ************************************************************************** */
// #include <stdio.h>
// #include <fcntl.h>

// int	main(void)
// {
// 	int		fd1;
// 	int		fd2;
// 	int		fd3;
// 	char	*str;
// 	int		i;

// 	i = 1;
// 	fd1 = open("test", O_RDONLY);
// 	fd2 = open("test2", O_RDONLY);
// 	fd3 = open("test3", O_RDONLY);
// 	while (i != 50)
// 	{
// 		str = get_next_line(fd1);
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd2);
// 		printf("%s", str);
// 		free(str);
// 		str = get_next_line(fd3);
// 		printf("%s", str);
// 		free(str);
// 		i++;
// 	}
// 	return (0);
// }

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */
