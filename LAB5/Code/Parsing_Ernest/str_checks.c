/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_checks.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/09 18:33:36 by ebitca            #+#    #+#             */
/*   Updated: 2017/03/09 18:33:40 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../corewar.h"

int8_t	str_is_num(char *s)
{
	int i;

	i = 0;
	if (s[i] == '-')
		++i;
	while (s[i])
	{
		if (!ft_isdigit(s[i]))
			return (0);
		++i;
	}
	return (1);
}

void	ft_diez(char *str)
{
	int size;

	size = -1;
	while (str[++size])
	{
		if (str[size] == '#')
		{
			g_offset += ft_strlen(str) - size;
			str[size] = 0;
			break ;
		}
	}
}

int8_t	ft_only_space(char *line)
{
	if (*line == 0)
		return (1);
	while (*line)
	{
		if (*line != ' ' && *line != '\t')
			return (0);
		++line;
	}
	return (1);
}

void	ft_check_letters(void)
{
	int			top;
	int			j;
	const char	*ch = "abcdefghijklmnopqrstuvwxyz_0123456789";

	top = g_top;
	while (--top != -1)
	{
		j = -1;
		while (g_stack[top][++j])
			if (!ft_strchr(ch, g_stack[top][j]))
				ft_labe_error("Invalid symbol for label");
	}
}

int8_t	ft_check_instr(char *instr, int *i)
{
	*i = 0;
	while (*i < 17)
	{
		*i = *i + 1;
		if (!ft_strcmp(instr, g_instr[*i]))
			return (g_par[*i]);
	}
	return (0);
}
