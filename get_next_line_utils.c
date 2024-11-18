/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:42:27 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/18 15:59:55 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

/* ************************************************************************** */
/*	Just substr without strlen                                            */
/* ************************************************************************** */
char	*ft_substrlen(const char *s, unsigned int start)
{
	char			*dest;
	unsigned int	i;
	unsigned int	len;

	i = 0;
	len = 0;
	while (s[start + len])
		len++;
	dest = malloc((len + 1) * sizeof(char));
	if (!dest)
		return (NULL);
	while (s[start + i])
	{
		dest[i] = s[start + i];
		i++;
	}
	dest[i] = '\0';
	return (dest);
}

/* ************************************************************************** */
/*	Locate char inside str                                                */
/* ************************************************************************** */
int	ft_strichr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
			break ;
		i++;
	}
	if (s[i] == (char) c)
		return (i);
	return (-1);
}

/* ************************************************************************** */
/*	Return last node of a chainlist                                       */
/* ************************************************************************** */
t_list	*ft_lstlast(t_list *lst)
{
	while (lst)
	{
		if (!lst->next)
			break ;
		lst = lst->next;
	}
	return (lst);
}

/* ************************************************************************** */
/*	Create node with allocated str inside                                 */
/* ************************************************************************** */
t_list	*ft_lstnew_str(char *str, int count)
{
	t_list	*dst;
	int		i;

	dst = malloc(sizeof(t_list));
	if (!dst)
		return (NULL);
	dst -> content = malloc((count + 1) * sizeof(char));
	if (!(dst -> content))
		return (NULL);
	dst -> next = NULL;
	i = 0;
	while (str[i] && count > i)
	{
		dst -> content[i] = str[i];
		i++;
	}
	dst -> content[i] = '\0';
	return (dst);
}

/* ************************************************************************** */
/*	Add node after last node of chainlist                                 */
/* ************************************************************************** */
void	ft_lstadd_back(t_list **lst, t_list *lnew)
{
	t_list	*to_end;

	if (!*lst)
	{
		*lst = lnew;
		return ;
	}
	to_end = ft_lstlast(*lst);
	to_end->next = lnew;
}

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */
