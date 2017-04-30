/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:27:21 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:27:24 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned int	i;
	unsigned int	j;

	i = 0;
	j = 0;
	while (i == 0 && (*(s1 + j) != 0 || *(s2 + j) != 0) && j < n)
	{
		i = *(unsigned char *)(s1 + j) - *(unsigned char *)(s2 + j);
		j++;
	}
	return (i);
}
