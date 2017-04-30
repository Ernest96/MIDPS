/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   acb_work.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:00:09 by ebitca            #+#    #+#             */
/*   Updated: 2017/03/09 18:01:45 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

unsigned char	get_acb(int8_t offset, int8_t type)
{
	unsigned char temp;

	temp = type << 2 * offset;
	return (temp);
}

void			set_args(int8_t ord, char *str, int8_t type)
{
	if (ord == 0)
	{
		g_mat[g_size].arg1 = ft_strdup(str);
		g_mat[g_size].acb += get_acb(3, type);
	}
	if (ord == 1)
	{
		g_mat[g_size].arg2 = ft_strdup(str);
		g_mat[g_size].acb += get_acb(2, type);
	}
	if (ord == 2)
	{
		g_mat[g_size].arg3 = ft_strdup(str);
		g_mat[g_size].acb += get_acb(1, type);
	}
}

unsigned char	set_acb(unsigned char acb)
{
	g_a[g_i] = acb;
	g_i++;
	return (acb);
}
