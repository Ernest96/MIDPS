/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_all.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 18:28:24 by ebitca            #+#    #+#             */
/*   Updated: 2016/08/21 19:35:19 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_ALL_H
# define FT_ALL_H

# include <stdlib.h>

int	g_top;
int	g_back;
int	g_head;
char g_queue[100][12];
char g_stack[100][12];
void	ft_enqueue(char *temp);
void	ft_dequeue();
void	ft_pop();
short	ft_grade(char *temp);
void	ft_push(char *temp);
char	*ft_get_new(char *s);
short	ft_init(void);
short	ft_is_number(char *s, int *i);
char	*ft_get_number(char *s, int *i);
short	ft_is_operator(char *s, int *i);
char	*ft_get_operator(char *s, int *i);
char	*ft_get_bracket();
void	ft_rpn(char *s);
int		ft_atoi(char *str);
void	ft_operate(int n1, char sign, int n2, int *int_stack);
int		ft_calculate(int *int_stack);
float		eval_expr(char *str);
void	ft_putchar(char c);
void	ft_putnbr(int nb);
char	*ft_strcpy(char *dest, char *src);
#endif
