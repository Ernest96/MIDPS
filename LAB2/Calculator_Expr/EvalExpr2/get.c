/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 17:57:56 by ebitca            #+#    #+#             */
/*   Updated: 2016/08/21 19:30:36 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"

char	*ft_get_new(char *s)
{
	char	*nou;
	int		i;
	int		j;
	int		size;

	i = -1;
	size = 0;
	while (s[++i] != 0)
		if (s[i] != ' ')
			size++;
	nou = (char*)malloc(sizeof(char) * (size + 1));
	i = -1;
	j = -1;
	while (s[++i] != 0)
		if (s[i] != ' ')
			nou[++j] = s[i];
	nou[size] = 0;
	return (nou);
}

char	*ft_get_number(char *s, int *i)
{
	char	*temp;
	int		j;

	j = -1;
	temp = (char*)(malloc(sizeof(char) * 12));
	temp[++j] = s[*i];
	*i = *i + 1;
	while (s[*i] != '-' && s[*i] != '+' && s[*i] != '*' && s[*i] != '/'
			&& s[*i] != '%' && s[*i] != '(' && s[*i] != ')' && s[*i] != 0)
	{
		temp[++j] = s[*i];
		*i = *i + 1;
	}
	*i = *i - 1;
	temp[++j] = 0;
	return (temp);
}

char	*ft_get_operator(char *s, int *i)
{
	char	*temp;

	temp = (char*)(malloc(sizeof(char) * 2));
	temp[0] = s[*i];
	temp[1] = 0;
	return (temp);
}

char	*ft_get_bracket(void)
{
	char *temp;

	temp = (char*)malloc(sizeof(char) * 2);
	temp[0] = '(';
	temp[1] = 0;
	return (temp);
}
