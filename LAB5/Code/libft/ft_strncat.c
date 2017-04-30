/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:27:11 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:27:12 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *dest, const char *src, size_t nb)
{
	int		i;
	size_t	j;

	i = -1;
	while (*(dest + ++i))
		;
	j = -1;
	while (*(src + ++j) && j < nb)
		*(dest + i++) = *(src + j);
	*(dest + i) = 0;
	return (dest);
}
