/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dota <marvin@42.fr>                        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/16 19:41:16 by dota              #+#    #+#             */
/*   Updated: 2017/03/02 17:54:54 by ebitca           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#define CH		char buff[BUFF_SIZE], *temp;
#define HEAD	static t_list *head = NULL;
#define INIT	CH int nr; t_list *final; static int fd2 = -1; HEAD
#define INIT_2	t_list *list_temp; char *temp;

void	ft_list_push_back(t_list **begin_list, void **tmp, size_t c_size)
{
	t_list	*temp;
	void	*content;

	*((char*)*tmp + c_size - 1) = 0;
	content = *tmp;
	if (*begin_list == 0)
	{
		*begin_list = (t_list*)malloc(sizeof(t_list));
		(*begin_list)->content = (void*)malloc(c_size);
		(*begin_list)->content_size = c_size;
		ft_memcpy((*begin_list)->content, content, c_size);
		(*begin_list)->next = NULL;
		free(*tmp);
		return ;
	}
	temp = *begin_list;
	while (temp->next != 0)
		temp = temp->next;
	temp->next = (t_list*)malloc(sizeof(t_list));
	temp = temp->next;
	temp->content = (void*)malloc(c_size);
	temp->content_size = c_size;
	ft_memcpy(temp->content, content, c_size);
	temp->next = NULL;
	free(*tmp);
}

t_list	*check_new_line(t_list **head, int flag, const int *fd, int *fd2)
{
	t_list	*node;

	if (flag)
	{
		node = *head;
		while (node != NULL)
		{
			if (ft_strchr((char*)node->content, '\n') != NULL)
				return (node);
			node = node->next;
		}
		return (NULL);
	}
	else
	{
		*fd2 = *fd;
		while (*head != NULL)
		{
			node = *head;
			*head = (*head)->next;
			free(node->content);
			free(node);
		}
	}
	return (NULL);
}

void	restruct_string(t_list **head, char **line)
{
	int		i;
	char	*temp0;
	char	*temp1;

	i = -1;
	temp0 = (char*)(*head)->content;
	while (temp0[++i] != '\n')
		;
	temp0[i] = '\0';
	temp1 = ft_strdup(temp0 + i + 1);
	(*head)->content = (void*)temp1;
	temp1 = *line;
	*line = ft_strjoin(temp1, temp0);
	free(temp1);
	free(temp0);
}

short	get_line(t_list **head, t_list *final, char **line)
{
	INIT_2;
	while (*head != final)
	{
		list_temp = *head;
		temp = *line;
		*line = ft_strjoin(*line, (char*)list_temp->content);
		free(temp);
		*head = (*head)->next;
		free(list_temp->content);
		free(list_temp);
	}
	if (*head != NULL)
	{
		restruct_string(head, line);
		if (*((char*)(*head)->content) == 0)
		{
			list_temp = *head;
			*head = (*head)->next;
			free(list_temp->content);
			free(list_temp);
		}
	}
	return (1);
}

int		get_next_line(int const fd, char **line)
{
	INIT;
	if (fd < 0 || BUFF_SIZE <= 0 || line == NULL)
		return (-1);
	*line = ft_strdup("\0");
	if (fd != fd2)
		check_new_line(&head, 0, &fd, &fd2);
	while (1)
	{
		nr = read(fd, buff, BUFF_SIZE);
		if (nr > 0)
		{
			temp = (char*)malloc(sizeof(char) * (nr + 1));
			ft_memcpy(temp, buff, nr);
			ft_list_push_back(&head, (void**)&temp, nr + 1);
		}
		else if (nr == -1)
			return (-1);
		final = check_new_line(&head, 1, NULL, NULL);
		if (final != NULL)
			return (get_line(&head, final, line));
		else if (head == NULL)
			return (0);
		else if (final == NULL && nr == 0)
			return (get_line(&head, final, line));
	}
}
