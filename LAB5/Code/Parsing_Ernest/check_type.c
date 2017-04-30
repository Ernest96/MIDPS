/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_type.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:32:56 by ebitca            #+#    #+#             */
/*   Updated: 2017/04/03 16:05:04 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int8_t	check_is_reg(char *s)
{
	if (ft_strlen(s) == 2)
	{
		if (s[0] != 'r')
			return (0);
		if (s[1] < '1' || s[1] > '9')
			return (0);
		return (1);
	}
	else if (ft_strlen(s) == 3)
	{
		if (s[0] != 'r')
			return (0);
		if (s[1] != '1')
			return (0);
		if (s[2] < '0' || s[2] > '6')
			return (0);
		return (1);
	}
	else
		return (0);
}

int8_t	check_direct(char *s)
{
	if (s[0] != '%')
		return (0);
	if (s[1] == ':')
	{
		if (!s[2] || (s[2] >= '0' && s[2] <= '9'))
			return (0);
		g_stack[g_top] = ft_strdup(s + 2);
		++g_top;
		return (1);
	}
	else if (str_is_num(s + 1))
		return (1);
	return (0);
}

int8_t	check_indirect(char *s)
{
	if (str_is_num(s))
		return (1);
	if (s[0] == ':')
	{
		if (!s[1] || (s[1] >= '0' && s[1] <= '9'))
			return (0);
		g_stack[g_top] = ft_strdup(s + 1);
		++g_top;
		return (1);
	}
	return (0);
}
