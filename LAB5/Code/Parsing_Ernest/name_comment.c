/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   name_comment.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:30:39 by ebitca            #+#    #+#             */
/*   Updated: 2017/04/02 18:56:08 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_name_comment(int8_t *f, char *to_in, int8_t *seek, char *s)
{
	(void)to_in;
	*f = 1;
	g_offset += ft_strlen(s) + 1;
	*seek = 0;
}

void	ft_check_name_comment(char **s, int fd)
{
	CH;
	if (flags[2] && (flags[0] || flags[1]))
		ft_comp_error();
	words = ft_split_whitespaces(*s);
	ft_check_words_1(words, 0);
	if (ft_strcmp(words[0], ".name") == 0)
	{
		if (flags[0])
			ft_comp_error();
		ft_init_name_comment(flags, g_name, &seek, *s);
		ft_strcpy(g_name, words[1]);
	}
	else if (ft_strcmp(words[0], ".comment") == 0)
	{
		if (flags[1])
			ft_comp_error();
		ft_init_name_comment(flags + 1, g_comment, &seek, *s);
		ft_strcpy(g_comment, words[1]);
	}
	if (seek)
	{
		flags[2] = 1;
		lseek(fd, g_offset, SEEK_SET);
	}
}

void	ft_first_check(int *fd)
{
	char *line;

	ft_skip_spaces(fd);
	good_line(fd, &line);
	ft_check_name_comment(&line, *fd);
	free(line);
	ft_skip_spaces(fd);
	good_line(fd, &line);
	ft_check_name_comment(&line, *fd);
	free(line);
	ft_skip_spaces(fd);
}
