/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vcrivenc <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/03 15:52:20 by vcrivenc          #+#    #+#             */
/*   Updated: 2017/04/03 16:05:31 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	set_label(char *label, int o)
{
	if (!label)
		return ;
	g_search[g_si].str = ft_strdup(label);
	g_search[g_si].loc = g_i;
	g_search[g_si].off = o;
	g_search[g_si].start = g_ip;
	g_si++;
}

void	check_label(char *arg)
{
	if (!arg)
		return ;
	g_found[g_fi].str = ft_strdup(arg);
	g_found[g_fi].loc = g_ip;
	g_fi++;
}

void	codify(void)
{
	char	temp;
	int		q;

	q = -1;
	while (++q < g_size)
	{
		check_label(g_mat[q].laba);
		if (g_mat[q].instr == NULL)
			continue ;
		set_instr(g_mat[q].instr);
		temp = set_acb(g_mat[q].acb);
		set_arg(g_mat[q].arg1, temp >> 6 & 0x3);
		set_arg(g_mat[q].arg2, temp >> 4 & 0x3);
		set_arg(g_mat[q].arg3, temp >> 2 & 0x3);
		g_ip = g_i;
		test[p_test] = g_i;
		p_test++;
	}
}

void	insert_labels(void)
{
	IL;
	while (++temp < g_si)
	{
		j = -1;
		while (++j < g_fi)
		{
			if (!(ft_strcmp(g_search[temp].str, g_found[j].str)))
			{
				if (g_search[temp].off == 2)
				{
					OF23;
				}
				else
				{
					OF34;
					g_a[g_search[temp].loc + 2] = (g_found[j].loc -
							g_search[temp].start) >> 8 & 0xff;
					g_a[g_search[temp].loc + 3] = (g_found[j].loc -
							g_search[temp].start) & 0xff;
				}
				break ;
			}
		}
	}
}
