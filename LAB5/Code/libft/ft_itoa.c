/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:08:59 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:09:03 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	void	ft_my_strrev(char *str)
{
	char	temp;
	int		begin;
	int		end;

	begin = 0;
	end = ft_strlen(str) - 1;
	while (begin < end)
	{
		temp = str[begin];
		str[begin++] = str[end];
		str[end--] = temp;
	}
}

char			*ft_itoa(int n)
{
	long long	nb;
	char		*str;
	int			i;

	i = 0;
	nb = n;
	str = (char *)malloc(sizeof(char) * 21);
	if (!str)
		return (NULL);
	if (n == 0)
		str[i++] = '0';
	if (n < 0)
		nb = -nb;
	while (nb)
	{
		str[i++] = nb % 10 + '0';
		nb = nb / 10;
	}
	if (n < 0)
		str[i++] = '-';
	str[i] = '\0';
	ft_my_strrev(str);
	return (str);
}
