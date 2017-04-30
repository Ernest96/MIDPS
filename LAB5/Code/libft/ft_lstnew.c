/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:11:44 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:11:45 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstnew(void const *content, size_t content_size)
{
	t_list	*node;

	node = (t_list *)malloc(sizeof(t_list));
	if (node != NULL)
	{
		if (content)
		{
			node->content_size = content_size;
			node->content = (void*)malloc(sizeof(content_size));
			node->content = ft_memcpy(node->content, content, content_size);
		}
		else
		{
			node->content = NULL;
			node->content_size = 0;
		}
		return (node);
	}
	else
		return (NULL);
}
