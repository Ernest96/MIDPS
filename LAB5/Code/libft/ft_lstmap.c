/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebitca <marvin@42.fr>                      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/10/22 13:11:25 by ebitca            #+#    #+#             */
/*   Updated: 2016/10/22 13:11:27 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list *head;
	t_list *p;

	if (lst == NULL)
		return (NULL);
	head = f(lst);
	p = head;
	while (lst->next)
	{
		p->next = f(lst->next);
		p = p->next;
		lst = lst->next;
	}
	return (head);
}
