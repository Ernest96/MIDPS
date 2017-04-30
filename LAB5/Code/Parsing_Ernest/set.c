/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 17:57:58 by ebitca            #+#    #+#             */
/*   Updated: 2017/04/02 19:38:45 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	set_instr(char *arg)
{
	unsigned char	q;

	q = 0;
	while (q <= 16)
	{
		if (ft_strcmp(arg, g_instr[q]) == 0)
		{
			g_a[g_i] = q;
			g_i++;
			break ;
		}
		q++;
	}
}

void	set_indir(char *arg)
{
	int indir;

	if (arg[0] == ':')
	{
		set_label(arg + 1, 2);
		g_a[g_i] = 0;
		g_a[g_i + 1] = 0;
		g_i += 2;
		return ;
	}
	indir = ft_atoi(arg);
	g_a[g_i] = indir >> 8 & 0xff;
	g_a[g_i + 1] = indir & 0xff;
	g_i += 2;
}

void	set_dir(char *arg)
{
	int dir;

	if (arg[1] == ':')
	{
		set_label(arg + 2, 4);
		g_a[g_i] = 0;
		g_a[g_i + 1] = 0;
		g_a[g_i + 2] = 0;
		g_a[g_i + 3] = 0;
		g_i += 4;
		return ;
	}
	dir = ft_atoi(arg + 1);
	g_a[g_i] = dir >> 24 & 0xff;
	g_a[g_i + 1] = dir >> 16 & 0xff;
	g_a[g_i + 2] = dir >> 8 & 0xff;
	g_a[g_i + 3] = dir & 0xff;
	g_i += 4;
}

void	set_reg(char *arg)
{
	int reg;

	reg = ft_atoi(arg + 1);
	g_a[g_i] = reg;
	g_i++;
}

void	set_arg(char *arg, int acb)
{
	if (acb == 0 || arg == NULL)
		return ;
	if (acb == 1)
		set_reg(arg);
	else if (acb == 3)
		set_indir(arg);
	else
		set_dir(arg);
}
