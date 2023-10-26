/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mrony <mrony@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 10:39:55 by mrony             #+#    #+#             */
/*   Updated: 2023/10/26 10:39:56 by mrony            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "wonderland.h"

void	ft_free(char **split)
{
	int	i;

	i = 0;
	while (split[i])
	{
		free(split[i]);
		split[i] = NULL;
		i++;
	}
	free(split);
}

void	ft_clear(t_list *save)
{
	t_list	*temp;
	t_list	*next;

	temp = save;
	while (temp)
	{
		free(temp->content);
		next = temp->next;
		free(temp);
		temp = next;
	}
}
