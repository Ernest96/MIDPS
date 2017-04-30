/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:23:44 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:23:45 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	int i;
	int size;

	i = -1;
	while (*(s + ++i))
		;
	size = i;
	i = -1;
	while (++i <= size)
		if (*(s + i) == c)
			return (char*)(s + i);
	return (NULL);
}
