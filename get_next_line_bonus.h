/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 16:42:23 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/27 22:52:41 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H
# include <unistd.h>
# include <stdint.h>
# include <stdlib.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 1
# endif

typedef struct s_strlist
{
	char				*content;
	struct s_strlist	*next;
}	t_strlist;

void		stash_free(t_strlist **stash);
int			stash_strlinelen(t_strlist *stash);
void		stash_load(t_strlist *stash, char **str);
void		stash_save(int fd, t_strlist **stash);
char		*get_next_line(int fd);
int			ft_strichr(const char *s, int c);
t_strlist	*ft_lststrlast(t_strlist *lst);
void		ft_lstadd_back(t_strlist **lst, t_strlist *lnew);
t_strlist	*ft_lstnew_str(char *str, int count);
char		*ft_substrlen(const char *s, unsigned int start);

#endif

/* ************************************************************************** */
/*  End of file                                                               */
/* ************************************************************************** */
