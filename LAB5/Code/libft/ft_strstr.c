/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:29:09 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:29:10 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str, const char *to_find)
{
	const char			*temp;
	unsigned int		i;
	short				flag;

	if (*to_find == 0)
		return (char *)(str);
	temp = str;
	while (*temp && (flag = 1))
	{
		i = 0;
		while (*(to_find + i))
		{
			if (*(to_find + i) != *(temp + i))
			{
				flag = 0;
				break ;
			}
			i++;
		}
		if (flag)
			return (char *)(temp);
		temp++;
	}
	return (NULL);
}
