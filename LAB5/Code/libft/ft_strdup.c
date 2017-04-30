/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:24:57 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:24:58 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *src)
{
	unsigned int	i;
	char			*mem;
	unsigned int	j;

	if (src == NULL)
	{
		mem = (char*)malloc(1);
		*mem = 0;
		return (mem);
	}
	i = 0;
	while (*(src + i))
		i++;
	mem = (char*)malloc(i + 1);
	if (!mem)
		return (0);
	j = -1;
	while (++j < i)
		*(mem + j) = *(src + j);
	*(mem + j) = 0;
	return (mem);
}
