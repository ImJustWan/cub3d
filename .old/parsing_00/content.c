#include "wonderland.h"
#include "error.h"
#include "parsing.h"


char	**split_n_check(t_list *read)
{
	char	**split;

	split = ft_split((char *)read->content, ' ');
	if (!split)
		return (NULL);
	if (!ft_strcmp(split[0], "NO\0") || !ft_strcmp(split[0], "SO\0")
		|| !ft_strcmp(split[0], "WE\0") || !ft_strcmp(split[0], "EA\0")
		|| !ft_strcmp(split[0], "C\0") || !ft_strcmp(split[0], "F\0"))
		{
			if (split[1])
				return(split);
		}
	else if (split[0][0] == '\n')
		return(split);
	return(NULL);
}

int	file_access(char *path)
{
	int	fd;
	int	i;

	i = ft_strlen(path);
	if (path[i - 1] == '\n')
		path[i - 1] = '\0';
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_error_msg(ERR, NULL, path, NULL), FAIL);
	return(SUCCESS);
}

int *color_check(char *colors)
{
	int *rgb;
	int tmp;
	int i;

	i = 0;
	rgb = ft_calloc(3, sizeof(int));
	if (!rgb)
		return(NULL);
	while(i < 3)
	{
		tmp = ft_atoi(colors);
		rgb[i] = tmp;
		while(*colors && *colors != ',')
			colors++;
		colors++;
		i++;
	}
	return(rgb);
}

int	fill_hat(t_world *world, char **split)
{
	t_hat	*new;
	int		*rgb;

	rgb = NULL;
	if (!ft_strcmp(split[0], "NO\0") || !ft_strcmp(split[0], "SO\0")
		|| !ft_strcmp(split[0], "WE\0") || !ft_strcmp(split[0], "EA\0"))
	{
		if (file_access(split[1]))
			return(free(split), FAIL);
	}
	else if (!ft_strcmp(split[0], "C\0") || !ft_strcmp(split[0], "F\0"))
	{
		rgb = color_check(split[1]);
		if (!rgb)
			return(free(split), FAIL);
		free(split[1]);
		split[1] = NULL;
	}	
	new = ft_hatnew(split[0], split[1], rgb);
	if (!new)
		return(free(split), FAIL);
	ft_add_back_hat(&world->hat, new);
	return(SUCCESS);
}

int	check_content(t_world *world, t_list **read)
{

	// t_hat	*cpy;
	// cpy = world->hat;
	// while(cpy)
	// {
	// 	if (cpy->index)
	// 		printf("index = [%s]", cpy->index);
	// 	if (cpy->path)
	// 		printf("path = [%s]\n", cpy->path);
	// 	if (cpy->rgb)
	// 		printf("rgb = [%d],[%d],[%d]\n", cpy->rgb[0], cpy->rgb[1], cpy->rgb[2]);
	// 	cpy = cpy->next;
	// }
	return (SUCCESS);
}



/*

	split each line at ' '
	if first one is NO, SO, WE, EA, C or F
		save first one in index 
	if not C or F : try to open file 
		if error
			return error message -> end prog
		else
			save path
	if color (C of F)
		atoi 
		+= 0 or < 256
	finally : check if we have all 6 required items.
	build list;
	check map (other function);
*/