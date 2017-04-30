/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:12:17 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:12:21 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	const unsigned char		*p;
	unsigned char			k;

	k = (unsigned char)c;
	if (n != 0)
	{
		p = s;
		while (n-- != 0)
		{
			if (*p++ == k)
				return ((void *)(p - 1));
		}
	}
	return (NULL);
}
