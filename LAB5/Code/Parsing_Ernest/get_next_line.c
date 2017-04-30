/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcrivenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/04 14:30:26 by vcrivenc          #+#    #+#             */
/*   Updated: 2016/11/13 13:47:36 by vcrivenc         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		get_next_line(const int fd, char **line)
{
	char c;
	int i;
    int flag;

	*line = (char*)malloc(100 * sizeof(char));

	c = -1;
	i = 0;
    ++g_line;
	while (c != '\n')
    {
        flag = read(fd, &c, 1);
          if (!flag)
        break ;
        *(*line + i) = c;
        ++i;

    }

    if (i != 0)
    {
        if (*(*line - 1 + i) == '\n')
            *(*line - 1 + i) = 0;
        return (1);
    }

	if (!i)
    {
        *(*line + i) = 0;
        return(0);
    }

}
