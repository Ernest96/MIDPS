/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memalloc.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:11:55 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:11:56 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memalloc(size_t size)
{
	size_t	i;
	char	*memorie;

	if ((memorie = (char *)malloc(size)) != 0)
	{
		i = 0;
		while (i < size)
		{
			memorie[i] = 0;
			i++;
		}
		return (memorie);
	}
	return (NULL);
}
