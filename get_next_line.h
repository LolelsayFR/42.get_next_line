/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:42:23 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/18 17:39:04 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 5
# endif

typedef struct s_strlist
{
	char			*content;
	struct s_strlist	*next;
}	t_strlist;

void	stash_free(t_list **stash);
int		stash_strlinelen(t_list *stash);
void	stash_load(t_list *stash, char **str);
void	stash_save(int fd, t_list **stash);
char	*get_next_line(int fd);
int		ft_strichr(const char *s, int c);
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *lnew);
t_list	*ft_lstnew_str(char *str, int count);
char	*ft_substrlen(const char *s, unsigned int start);

#endif

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */
