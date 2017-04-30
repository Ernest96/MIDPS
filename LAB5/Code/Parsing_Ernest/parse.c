/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/02 17:06:44 by ebitca            #+#    #+#             */
/*   Updated: 2017/04/03 16:00:38 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	dump(char *file)
{
	int				fd1;
	unsigned int	magic;

	magic = 0xf383ea00;
	fd1 = open(file, O_RDWR | O_TRUNC | O_CREAT);
	if (fd1 == -1)
	{
		perror("File cannot be opened\n");
		return ;
	}
	write(fd1, &magic, 4);
	write(fd1, g_name, 128);
	write(fd1, g_comment, 2048);
	write(fd1, g_a, g_i);
}

void	ft_init(void)
{
	ft_init_1();
	ft_init_2();
	ft_init_3();
}

int		main(int argc, char **argv)
{
	VAR;
	ft_init();

	if (argc != 2)
		ft_usage();
	g_mat = (t_mat*)malloc(sizeof(t_mat) * 1000);
	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		ft_invalid_input();
	ft_check_ext(argv[1]);
	ft_first_check(&fd);

	while (good_line(&fd, &line))
    {
		words = ft_split_whitespaces(line);
		g_offset += ft_strlen(line) + 1;
		ft_check_words_1(words, 1);
		ft_skip_spaces(&fd);
		free(words);
		free(line);
        printf("ok\n");
	}

	ft_find_label();
	codify();
	insert_labels();
	line = ft_strdup(argv[1]);
	line[ft_strlen(line) - 1] = 0;

	dump(ft_strjoin(line, "cor"));
}
