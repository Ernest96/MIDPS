/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   f_package.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/08/21 17:48:25 by ebitca            #+#    #+#             */
/*   Updated: 2016/08/21 19:27:12 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_all.h"


char	*ft_strcpy(char *dest, char *src)
{
	unsigned int i;

	i = 0;
	while (*(src + i))
	{
		*(dest + i) = *(src + i);
		i++;
	}
	while (*(dest + i))
		*(dest + i++) = 0;
	return (dest);
}

int		ft_atoi(char *str)
{
	int i;
	int nr;
	int n;

	i = 0;
	nr = 0;
	n = 0;
	while ((str[i] == '\t') || (str[i] == '\n') || (str[i] == ' ') ||
			(str[i] == '\f') || (str[i] == '\v') || (str[i] == '\r'))
		i++;
	if (str[i] == '-')
		n = 1;
	if ((str[i] == '+') || (str[i] == '-'))
		i++;
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
	{
		nr *= 10;
		nr += (int)str[i] - '0';
		i++;
	}
	if (n == 1)
		return (-nr);
	else
		return (nr);
}
