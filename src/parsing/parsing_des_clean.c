/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_des_clean.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:38:24 by mrony             #+#    #+#             */
/*   Updated: 2023/10/26 10:38:25 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parsing.h"

t_list	*remove_first(t_list **read)
{
	t_list	*tmp;

	tmp = (*read)->next;
	ft_lstdelone((*read), free);
	(*read) = tmp;
	(*read)->prev = NULL;
	return (tmp);
}

void	remove_middle(t_list **read)
{
	t_list	*tmp;

	tmp = (*read)->next;
	(*read)->prev->next = (*read)->next;
	(*read)->next->prev = (*read)->prev;
	ft_lstdelone((*read), free);
	(*read) = tmp;
}

t_list	*remove_empty_lines(t_list *read)
{
	t_list	*head;

	head = read;
	while (read)
	{
		if (empty_line(read->content))
		{
			if (read && !read->prev)
				head = remove_first(&read);
			else if (read && !read->next)
			{
				read->prev->next = NULL;
				ft_lstdelone(read, free);
				read = NULL;
				break ;
			}
			else if (read && read->prev && read->next)
				remove_middle(&read);
		}
		else
			read = read->next;
	}
	return (head);
}

void	remove_newline(t_list *read)
{
	char	*str;

	while (read)
	{
		str = (char *)read->content;
		if (str && str[ft_strlen(str) - 1] == '\n')
			str[ft_strlen(str) - 1] = '\0';
		read = read->next;
	}
}
