/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:28:29 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:28:30 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t hlen)
{
	size_t	nlen;
	int		lastresult;

	if (*needle == '\0')
		return ((char*)haystack);
	if (*haystack == '\0')
		return (NULL);
	nlen = ft_strlen(needle);
	lastresult = 1;
	while (nlen <= hlen && *haystack != '\0'
		&& (lastresult = ft_strncmp(haystack, needle, nlen)))
	{
		hlen--;
		haystack++;
	}
	if (lastresult != 0)
		return (NULL);
	else
		return ((char *)haystack);
}
