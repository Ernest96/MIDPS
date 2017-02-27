/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue+stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 17:47:17 by ebitca            #+#    #+#             */
/*   Updated: 2016/08/21 19:34:38 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

void	ft_enqueue(char *temp)
{
	if (g_head == -1)
		g_head++;
	ft_strcpy(g_queue[++g_back], temp);
}

void	ft_dequeue(void)
{
	if (g_head == g_back)
	{
		g_head = -1;
		g_back = -1;
	}
	else
		g_head++;
}

void	ft_pop(void)
{
	g_top--;
}

short	ft_grade(char *temp)
{
	if (temp[0] == '-' || temp[0] == '+')
		return (1);
	else if (temp[0] == '*' || temp[0] == '/' || temp[0] == '%')
		return (2);
	return (0);
}

void	ft_push(char *temp)
{
	if (g_top == -1)
		ft_strcpy(g_stack[++g_top], temp);
	else if (temp[0] == '(')
		ft_strcpy(g_stack[++g_top], temp);
	else if (ft_grade(temp) > ft_grade(g_stack[g_top]))
		ft_strcpy(g_stack[++g_top], temp);
	else
	{
		while (ft_grade(g_stack[g_top]) >= ft_grade(temp) && g_top != -1)
		{
			ft_enqueue(g_stack[g_top]);
			ft_pop();
		}
		ft_push(temp);
	}
}
