/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:28:41 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:28:43 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int i;
	int size;

	i = -1;
	while (*(s + ++i))
		;
	size = i + 1;
	while (--size >= 0)
		if (*(s + size) == c)
			return (char*)(s + size);
	return (NULL);
}
