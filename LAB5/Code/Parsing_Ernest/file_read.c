/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   file_read.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:39:17 by ebitca            #+#    #+#             */
/*   Updated: 2017/03/09 18:39:33 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		good_line(int *fd, char **line)
{
	int rez;

    printf("1\n");
	rez = get_next_line(*fd, line);
	ft_diez(*line);
	printf("2\n");
	printf("%s\n",*line);
	return (rez);
}

void	ft_skip_spaces(int *fd)
{
	int8_t	flag;
	char	*line;

	flag = 1;
	while (flag)
	{
		if (good_line(fd, &line) == 0)
			return ;
		if (ft_only_space(line))
			g_offset += ft_strlen(line) + 1;
		else
		{
			flag = 0;
			--g_line;
		}
		free(line);
	}
	lseek(*fd, g_offset, SEEK_SET);
}
