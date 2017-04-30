/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:23:28 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:23:31 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *dest, const char *src)
{
	unsigned int	i;
	unsigned int	j;

	i = -1;
	while (*(dest + ++i))
		;
	j = -1;
	while (*(src + ++j))
		*(dest + i++) = *(src + j);
	*(dest + i) = 0;
	return (dest);
}
