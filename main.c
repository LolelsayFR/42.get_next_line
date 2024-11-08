/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: emaillet <emaillet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/08 04:26:13 by emaillet          #+#    #+#             */
/*   Updated: 2024/11/08 06:57:57 by emaillet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <fcntl.h>
#include <stdio.h>

int	main(void)
{
	int		fd;
	char	*str;

	fd = open("test", O_RDONLY);
	while (1)
	{
		str = get_next_line(fd);
		printf("%s", str);
		free(str);
		if (!str)
			break ;
	}
	return (0);
}
