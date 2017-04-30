/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:12:32 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:12:33 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	int				j;

	i = 0;
	j = 0;
	while (i < n)
	{
		j = *((unsigned char*)s1 + i) - *((unsigned char*)s2 + i);
		if (j != 0)
			return (j);
		i++;
	}
	return (0);
}
