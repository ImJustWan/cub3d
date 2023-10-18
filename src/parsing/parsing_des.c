#include "parsing.h"

int	dispatch_info(t_world *world, char **split)
{
	int	split_size = ft_table_size(split);
	if (split_size < 2)
		return (ft_error_msg(ERR, NULL, IFL, MFP), FAIL);
	if (split_size > 2)
		return (ft_error_msg(ERR, NULL, IFL, MIF), FAIL);
	if (ft_strlen(split[0]) == 2)
	{
		if (texture_save(world, split))
			return(FAIL);
		return (free_split(split), SUCCESS);
	}
	else if (ft_strlen(split[0]) == 1)
	{
		if (color_save(world, split))
			return (FAIL);
		ft_free(split);
	}
	else
		return (ft_error_msg(ERR, NULL, IFL, IID), FAIL);
	return (SUCCESS);
}

int	save_info(t_world *world, char *str)
{
	char **split;

	split = ft_split(str, 32);
	if (!split)
		return (ft_error_msg(ERR, NULL, PAR, MAL), FAIL);
	if (dispatch_info(world, split))
		return(ft_free(split), FAIL);
	return (SUCCESS);
}

int		parsing_description(t_world *world, t_list *read)
{
	t_list	*cpy;

	(void)world;
	read = remove_empty_lines(read);
	remove_newline(read);
	cpy = read;
	while(cpy)
	{
		if (save_info(world, (char *)cpy->content))
			return(ft_clear(read), FAIL);
		cpy = cpy->next;
	}
	ft_clear(read);
	// if (check_textures(world)));
	// 	return (FAIL);
	return(SUCCESS);
}

	// t_list *cpy;
	// cpy = read;
	// while(cpy)
	// {
	// 	printf("After [%s]\n", (char *)cpy->content);
	// 	cpy = cpy->next;
	// }