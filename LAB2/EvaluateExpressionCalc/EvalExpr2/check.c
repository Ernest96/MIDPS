/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 17:55:48 by ebitca            #+#    #+#             */
/*   Updated: 2016/08/21 19:21:50 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

short	ft_init(void)
{
	g_top = -1;
	g_back = -1;
	g_head = -1;
	return (-1);
}

short	ft_is_number(char *s, int *i)
{
	if (s[*i] >= '0' && s[*i] <= '9')
		return (1);
	else if ((s[*i] == '-' || s[*i] == '+') && (s[*i + 1] >= '0' &&
				s[*i + 1] <= '9') && *i == 0)
		return (1);
	else if ((s[*i] == '-' || s[*i] == '+') && (s[*i + 1] >= '0' &&
				s[*i + 1] <= '9') && s[*i - 1] == '(')
		return (1);
	else
		return (0);
}

short	ft_is_operator(char *s, int *i)
{
	if (s[*i] == '-' || s[*i] == '+' || s[*i] == '*' || s[*i] == '/'
			|| s[*i] == '%')
	{
		if (s[*i + 1] >= '0' && s[*i + 1] <= '9')
			return (1);
		else if (s[*i + 1] == '(')
			return (1);
	}
	return (0);
}
