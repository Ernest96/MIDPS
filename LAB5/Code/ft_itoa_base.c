/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_base.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: exam <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/13 16:44:33 by exam              #+#    #+#             */
/*   Updated: 2017/03/31 17:09:06 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

int		ft_count(long value, int base)
{
	int n;
	n = 0;
	while(value)
	{
		value = value / base;
		n++;
	}
	if(n == 0)
		return(1);
	return (n);
}

char	*ft_itoa_base(unsigned char value, int base)
{
	long number;
	char *str;
	int n;
	int i;
	i = 0;
	number = value;
	if(number < 0)
	{
		number = -number;
		n = ft_count(number, base);
		if(base == 10)
		{
		str = (char *)malloc(sizeof(char) * (n + 3));
		str[0] = '-';
		str[n+1] = '\0';
		n++;
		i = 1;
		}
		else
		{
		str = (char *)malloc(sizeof(char) * (n+2));
		str[n] = '\0';
		}
	}
	else
	{
		n = ft_count(number, base);
		str = (char *)malloc(sizeof(char) * (n+2));
		str[n] = '\0';
	}
	if(value >= 0 && value < 16)
	{
		++n;
		str[n] = 0;
		str[0] = '0';
	}
	while(--n >= i)
	{
		if((number % base) == 10)
			str[n] = 'a';				
		else if((number % base) == 11)
			str[n] = 'b';
		else if((number % base) == 12)
			str[n] = 'c';
		else if((number % base) == 13)
			str[n] = 'd';
		else if((number % base) == 14)
			str[n] = 'e';
		else if((number % base) == 15)
			str[n] = 'f';
		else 
			str[n] = '0' + (number % base);
		number = number / base;
	}
	return (str);
}
