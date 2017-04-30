/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:29:38 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:29:39 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int	begin;
	int	end;

	if (s == NULL)
		return (0);
	begin = 0;
	end = ft_strlen(s);
	while (s[begin] && (s[begin] == ' ' || s[begin] == '\t'
				|| s[begin] == '\n'))
		begin++;
	if (begin == (end - 1))
		return (NULL);
	end--;
	while ((end > begin) && (s[end] == ' ' || s[end] == '\t' || s[end] == '\n'))
		end--;
	return (ft_strsub(s, begin, end - begin + 1));
}
