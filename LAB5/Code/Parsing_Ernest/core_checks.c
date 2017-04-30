/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   core_checks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:02:16 by ebitca            #+#    #+#             */
/*   Updated: 2017/04/03 16:04:16 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int		check_args(char **words, int8_t rez, int j)
{
	CH_ARGS;
	while (++i < rez)
	{
		if (check_is_reg(words[i]))
		{
			if (can_accept(i, 0, j))
				set_args(i, words[i], 1);
			ELSE_RET0;
		}
		else if (check_direct(words[i]))
		{
			if (can_accept(i, 1, j))
				set_args(i, words[i], 2);
			ELSE_RET0;
		}
		else if (check_indirect(words[i]))
		{
			if (can_accept(i, 2, j))
				set_args(i, words[i], 3);
			ELSE_RET0;
		}
		ELSE_RET0;
	}
	return (1);
}

void	ft_check_words_1(char **words, int8_t flag)
{
	int8_t	rez;
	int		labe;
	int		i;

	if (ft_check_dir(words, flag))
		return ;
	labe = ft_check_labe(words[0]);
	if (labe && !words[1])
	{
		just_label();
		++g_size;
		return ;
	}
	if (!labe)
		g_mat[g_size].laba = NULL;
	rez = ft_check_instr(words[0 + labe], &i);
	if (rez != ft_num_words(words + 1 + labe) || rez == 0)
		ft_comp_error();
	g_mat[g_size].instr = ft_strdup(g_instr[i]);
	if (!check_args(words + 1 + labe, rez, i))
		ft_comp_error();
	++g_size;
}

void	ft_check_stack(void)
{
	int		top;
	int		i;
	int8_t	flag;

	top = g_top;
	while (--top != -1)
	{
		i = -1;
		flag = 0;
		while (++i < g_size)
		{
			if (g_mat[i].laba == NULL)
				continue ;
			if (!ft_strcmp(g_stack[top], g_mat[i].laba))
				++flag;
		}
		if (flag != 1)
			ft_labe_error("Invalid label adresation");
	}
}

int8_t	can_accept(int8_t order, int par, int inst)
{
	if (g_sabl[inst][3 * order + par] == '1')
		return (1);
	return (0);
}

int8_t	ft_check_labe(char *labe)
{
	int i;

	i = ft_strlen(labe) - 1;
	if (labe[i] != ':')
		return (0);
	labe[i] = 0;
	g_mat[g_size].laba = ft_strdup(labe);
	return (1);
}
