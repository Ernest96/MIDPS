/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:36:38 by ebitca            #+#    #+#             */
/*   Updated: 2017/04/02 19:13:45 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		ft_check_dir(char **words, int8_t flag)
{
	int flag2;

	flag2 = 0;
	if (words[0] != NULL && !flag)
	{
		if (words[0][0] == '.')
		{
			if (!(!ft_strcmp(words[0], ".name") ||
						!ft_strcmp(words[0], ".comment")))
				ft_comp_error();
			else
				flag2 = 1;
		}
	}
	if (!flag && words[0] != NULL)
		++words;
	while (*words != NULL)
	{
		if (**words == '.')
			ft_comp_error();
		++words;
	}
	return (flag2);
}

void	ft_check_ext(char *s)
{
	int last;

	last = ft_strlen(s);
	if (!(s[last - 1] == 's' && s[last - 2] == '.'))
	{
		ft_putstr("Fatal: ");
		ft_putstr("Invalid extension\n");
		exit(0);
	}
	ft_strcpy(g_name, "X");
	ft_strcpy(g_name, "");
}
