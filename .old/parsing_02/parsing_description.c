#include "parsing.h"

void	del_read_node(t_list **read, int flag, char **str)
{
	t_list	*tmp;

	tmp = NULL;
	if ((*read) && (*read)->next)
		tmp = (*read)->next;
	if (flag == 1)
		free((*read)->content);
	free((*read));
	(*read) = tmp;
	(*str) = NULL;
}



int	is_bs(char c)
{
	if ((c >= 7 && c <= 13) || c == 32)
		return (TRUE);
	return (FALSE);
}

char *save_address(t_list *read, char *str)
{
	str = &str[2];
	str = skip_blank_space(str);
	if (!str)
		return (NULL);
	str[ft_strlen(str)] = '\0';
	ft_memmove(read->content, str, ft_strlen(str));
	return(read->content);
}

// int save_color(t_world *world, t_list *read, char *str, int o)
// {
// 	int r;
// 	int g;
// 	int b;


// }

int	dispatch(t_world *world, t_list *read, char *str)
{
	if (str && !ft_strncmp(str, "NO", 2) && is_bs(str[2]) && !world->setup->no)
	{
		world->setup->no = save_address(read, str);
		return(SUCCESS);
	}
	else if (str && !ft_strncmp(str, "SO", 2) && is_bs(str[2]) && !world->setup->so)
	{
		world->setup->so = save_address(read, str);
		return(SUCCESS);
	}
	else if (str && !ft_strncmp(str, "EA", 2) && is_bs(str[2]) && !world->setup->ea)
	{
		world->setup->ea = save_address(read, str);
		return (SUCCESS);
	}
	else if (str && !ft_strncmp(str, "WE", 2) && is_bs(str[2]) && !world->setup->we)
	{
		world->setup->we = save_address(read, str);
		return (SUCCESS);
	}
	// else if (str && !ft_strncmp(str, "C", 2) && is_bs(str[1]))
	// 	return (save_color(world, read, str));
	// else if (str && !ft_strncmp(str, "F", 2) && is_bs(str[1]))
	// 	return (save_color(world, read, str));
	return (FAIL);
}

int	parsing_description(t_world *world, t_list *read)
{
	char *str;
	int res;

	res = 0;
	while(read && read->next && res == 0)
	{
		str = skip_blank_space((char *)read->content);
		if (ft_strlen(str) == 0)
			del_read_node (&read, 1, &str);
		if (str && str[ft_strlen(str) - 1] == '\n')
			str[ft_strlen(str) - 1] = '\0';
		res = dispatch(world, read, str);
		del_read_node (&read, 0, &str);
	}
	if (res == 1)
		return (FAIL);
	return(SUCCESS);
}
