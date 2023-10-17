#include "parsing.h"

char	*skip_blank_space(char *str)
{
	if (!str)
		return (NULL);
	while (*str)
	{
		if ((*str >= 7 && *str <= 13) || *str == 32)
			str++;
		else
			break ;
	}
	return (str);
}
void	save_it(t_world *world, char **split)
{
	if (split[0][0] == 'C' || split[0][0] == 'F')
		return (save_color(world, split));
	if (split[1] && split[1][ft_strlen(split[1]) - 1] == '\n')
		split[1][ft_strlen(split[1]) - 1] = '\0';
	if (!(strstr(split[1], ".xpm\0")))
		return (FAIL); // Wrong file format
	if (!strcmp("NO", split[0]) && !world->setup->no)
		world->setup->no = split[1];
	else if (!strcmp("SO", split[0]) && !world->setup->so)
		world->setup->so = split[1];
	else if (!strcmp("EA", split[0]) && !world->setup->ea)
		world->setup->ea = split[1];
	else if (!strcmp("WE", split[0]) && !world->setup->we)
		world->setup->we = split[1];
	
}

int		parsing_description(t_world *world, t_list *read)
{
	char	**split;

	while(read)
	{
		
		split = ft_split((char *)read->content, ' ');
		if (!split)
			return(FAIL);//malloc failled
		if (split && is_empy(split[0]))

		if (strcmp("NO", split[0]) || strcmp("SO", split[0]) 
			|| strcmp("EA", split[0]) || strcmp("WE", split[0])
			|| strcmp("C", split[0]) || strcmp("F", split[0]))
			return (ft_free(split), FAIL) // wrong identifier
		else if
			save_it(world, split);
		free(split[0]);
		free(split);
		read = read->next
	}
}
