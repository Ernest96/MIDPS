/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   inits.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:25:00 by ebitca            #+#    #+#             */
/*   Updated: 2017/03/09 18:26:05 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

void	ft_init_1(void)
{
	g_instr = (char**)malloc(sizeof(char*) * 17);
	g_instr[0] = ft_strdup("");
	g_instr[1] = ft_strdup("live");
	g_instr[2] = ft_strdup("ld");
	g_instr[3] = ft_strdup("st");
	g_instr[4] = ft_strdup("add");
	g_instr[5] = ft_strdup("sub");
	g_instr[6] = ft_strdup("and");
	g_instr[7] = ft_strdup("or");
	g_instr[8] = ft_strdup("xor");
	g_instr[9] = ft_strdup("zjmp");
	g_instr[10] = ft_strdup("ldi");
	g_instr[11] = ft_strdup("sti");
	g_instr[12] = ft_strdup("fork");
	g_instr[13] = ft_strdup("lld");
	g_instr[14] = ft_strdup("lldi");
	g_instr[15] = ft_strdup("lfork");
	g_instr[16] = ft_strdup("aff");
}

void	ft_init_2(void)
{
	g_sabl = (char**)malloc(sizeof(char*) * 17);
	g_sabl[0] = ft_strdup("");
	g_sabl[1] = ft_strdup("010000000");
	g_sabl[2] = ft_strdup("011100000");
	g_sabl[3] = ft_strdup("100101000");
	g_sabl[4] = ft_strdup("100100100");
	g_sabl[5] = ft_strdup("100100100");
	g_sabl[6] = ft_strdup("111111100");
	g_sabl[7] = ft_strdup("111111100");
	g_sabl[8] = ft_strdup("111111100");
	g_sabl[9] = ft_strdup("010000000");
	g_sabl[10] = ft_strdup("111110100");
	g_sabl[11] = ft_strdup("100111110");
	g_sabl[12] = ft_strdup("010000000");
	g_sabl[13] = ft_strdup("011100000");
	g_sabl[14] = ft_strdup("111110100");
	g_sabl[15] = ft_strdup("010000000");
	g_sabl[16] = ft_strdup("100000000");
}

void	ft_init_3(void)
{
	g_name = (char*)malloc(sizeof(char) * 129);
	g_comment = (char*)malloc(sizeof(char) * 2049);
	ft_bzero(g_name, 129);
	ft_bzero(g_comment, 2049);
	g_par[0] = -1;
	g_par[1] = 1;
	g_par[2] = 2;
	g_par[3] = 2;
	g_par[4] = 3;
	g_par[5] = 3;
	g_par[6] = 3;
	g_par[7] = 3;
	g_par[8] = 3;
	g_par[9] = 1;
	g_par[10] = 3;
	g_par[11] = 3;
	g_par[12] = 1;
	g_par[13] = 2;
	g_par[14] = 3;
	g_par[15] = 1;
	g_par[16] = 1;
}

void	obnulim(void)
{
	g_mat[g_size].acb = 0;
	g_mat[g_size].arg1 = NULL;
	g_mat[g_size].arg2 = NULL;
	g_mat[g_size].arg3 = NULL;
}
