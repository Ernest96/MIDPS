/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   functions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:38:16 by ebitca            #+#    #+#             */
/*   Updated: 2017/04/02 19:44:42 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		ft_num_words(char **words)
{
	int i;

	i = -1;
	while (words[++i] != NULL)
		;
	return (i);
}

void	just_label(void)
{
	g_mat[g_size].instr = NULL;
	g_mat[g_size].acb = 0;
	g_mat[g_size].arg1 = NULL;
	g_mat[g_size].arg2 = NULL;
	g_mat[g_size].arg2 = NULL;
}

void	free_words(char **words)
{
	int i;

	i = -1;
	while (*(words + ++i) != NULL)
	{
		free(*(words + i));
		*(words + i) = NULL;
	}
}

void	ft_find_label(void)
{
	ft_check_letters();
	ft_check_stack();
}

int		is_return(int i)
{
	int j;

	j = 0;
	while (j < p_test)
	{
		if (test[j] == i)
			return (1);
		++j;
	}
	return (0);
}
