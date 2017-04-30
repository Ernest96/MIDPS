/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:12:07 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:12:09 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned int i;

	i = 0;
	while (i < n)
	{
		*((char*)dest + i) = *((char*)src + i);
		if (*((char*)dest + i) == c)
			return ((void*)((char*)dest + i + 1));
		i++;
	}
	return (NULL);
}
