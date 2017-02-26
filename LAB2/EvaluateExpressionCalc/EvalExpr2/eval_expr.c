/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eval_expr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 16:51:07 by ebitca            #+#    #+#             */
/*   Updated: 2016/08/21 19:41:57 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

void	ft_rpn(char *s)
{
	int i;

	i = ft_init();
	while (s[++i] != 0)
	{
		if (ft_is_number(s, &i))
			ft_enqueue(ft_get_number(s, &i));
		else if (ft_is_operator(s, &i))
			ft_push(ft_get_operator(s, &i));
		else if (s[i] == '(')
			ft_push(ft_get_bracket());
		else if (s[i] == ')')
		{
			while (g_stack[g_top][0] != '(')
			{
				ft_enqueue(g_stack[g_top]);
				ft_pop();
			}
			ft_pop();
		}
	}
	while (g_top != -1)
		ft_enqueue(g_stack[g_top--]);
}

void	ft_operate(float n1, char sign, float n2, float *int_stack)
{
	if (sign == '+')
		int_stack[g_top - 1] = n2 + n1;
	else if (sign == '-')
		int_stack[g_top - 1] = n2 - n1;
	else if (sign == '*')
		int_stack[g_top - 1] = n2 * n1;
	else if (sign == '/')
		int_stack[g_top - 1] = n2 / n1;
}

float		ft_calculate(float *int_stack)
{
	while (g_head != -1 && g_back != -1)
	{
		if ((g_queue[g_head][0] == '-' || g_queue[g_head][0] == '+') &&
				g_queue[g_head][1] != 0)
		{
			int_stack[++g_top] = atof(g_queue[g_head]);
			ft_dequeue();
		}
		else if (g_queue[g_head][0] != '-' && g_queue[g_head][0] != '+' &&
				g_queue[g_head][0] != '*' && g_queue[g_head][0] != '/' &&
				g_queue[g_head][0] != '%')
		{
			int_stack[++g_top] = atof(g_queue[g_head]);
			ft_dequeue();
		}
		else
		{
			ft_operate(int_stack[g_top], g_queue[g_head][0],
					(int_stack[g_top - 1]), int_stack);
			ft_dequeue();
			ft_pop();
		}
	}
	return (int_stack[0]);
}

float	eval_expr(char *str)
{
	char	*s;
	float	result;
	float	int_stack[100];

	s = ft_get_new(str);
	ft_rpn(s);
	result = ft_calculate(int_stack);
	return (result);
}
