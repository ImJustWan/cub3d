#include "wonderland.h"
#include "error.h"
#include "parsing.h"

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

int	fill_hat(t_hat *hat, char **split)
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
	ft_add_back_hat(&hat, new);
	return(SUCCESS);
}

int	get_description(t_hat *hat, char *line)
{
	char	**split;

	split = ft_split(line, ' ');	
	if (!split)
		return(FAIL);
	if (fill_hat(hat, split))
		return(FAIL);
	return (SUCCESS);
}


int	check_description(t_world *world, t_list *read)
{
	while(read)
	{
		if (empty_line((char *)read->content))
			read = read->next;
		else
		{
			get_description(world->hat, (char *)read->content);
			read = read->next;
		}
		// if (all_six(world->hat) == TRUE)
		// 	break;
	}
	return(SUCCESS);
}