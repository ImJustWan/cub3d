#include "wonderland.h"
#include "error.h"
#include "parsing.h"

t_hat	*ft_hatlast(t_hat *node)
{
	if (node == NULL)
		return (NULL);
	if (node->next)
		while (node && node->next)
			node = node->next;
	return (node);
}

int	ft_hat_size(t_hat *node)
{
	t_hat	*tmp;
	int		nb_elements;

	tmp = node;
	nb_elements = 0;
	while (tmp)
	{
		tmp = tmp->next;
		nb_elements++;
	}
	return (nb_elements);
}

void	ft_add_back_hat(t_hat **hat, t_hat *new)
{
	t_hat	*last;

	last = ft_hatlast(*hat);
	if (!last)
		*hat = new;
	else
	{
		last->next = new;
		new->prev = last;
	}
}

t_hat	*ft_hatnew(char *index, char *path, int *rgb)
{
	t_hat	*new;

	new = ft_calloc(1, sizeof(t_hat));
	if (new)
	{
		new->index = ft_strdup(index);
		if (path)
		{
			new->path = ft_strdup(path);
			new->rgb = NULL;
		}
		else if (rgb)
		{
			new->rgb = rgb;
			new->path = NULL;
		}
		new->next = NULL;
	}
	return (new);
}
