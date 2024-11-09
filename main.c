/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 04:26:13 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/09 02:02:47 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <stdio.h>
#include <fcntl.h>

void	ft_putstr(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	write(1, s, i);
}

int	main(void)
{
	int		fd1;
	int		fd2;
	int		fd3;
	char	*str;
	int		i;

	i = 1;
	fd1 = open("labible", O_RDONLY);
	fd2 = open("test2", O_RDONLY);
	fd3 = open("test3", O_RDONLY);
	while (i <= 3)
	{
		if (i == 1)
			str = get_next_line(fd1);
		else if (i == 2)
			str = get_next_line(fd2);
		else
			str = get_next_line(1);
		printf("%s", str);
		//if (str)
			//ft_putstr(str);
		free(str);
		if (!str)
			i++ ;
	}
	return (0);
}
