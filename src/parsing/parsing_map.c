# include "parsing.h"

t_list	*isolate_map(t_list *read)
{
	t_list *cpy;
	t_list *map;

	map = NULL;
	cpy = ft_lstlast(read);
	while(cpy && cpy->prev)
	{
		while (empty_line((char *)cpy->content) == TRUE)
			cpy = cpy->prev;
		while (empty_line((char *)cpy->content) == FALSE)
			cpy = cpy->prev;
		if (empty_line((char *)cpy->content) == TRUE)
		{
			map = cpy->next;
			map->prev = NULL;
			cpy->next = NULL;
			break ;
		}
	}
	return (map);
}

int	map_size(t_list *map_lst)
{
	int		size;

	size = 0;
	while (map_lst)
	{
		if (empty_line((char *)map_lst->content) == FALSE)
			size++;
		else
			break ;
		map_lst = map_lst->next;
	}
	return (size);
}

char	**map_fill(char **map, t_list *map_lst, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		map[i] = ft_strdup((char *)map_lst->content);
		if (!map[i])
			return(ft_free(map), NULL);
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
		map_lst = map_lst->next;
	}
	map[size] = NULL;
	return (map);
}

int	ft_table_size(char **table)
{
	int	i;

	i = 0;
	if (!table)
		return (0);
	while (table[i])
		i++;
	return (i);
}


int	check_surroundings(char **map, int i, int j)
{
	int map_len;
	int map_hei;

	map_len = ft_strlen(map[i]);
	map_hei = ft_table_size(map);
	if (i == 0 || j == 0 || i == map_hei || j == map_len)
		return(FAIL);
	if (!map[i - 1] || !map[i - 1][j] || !(ft_strchr("10NSEW", map[i - 1][j])))
		return(FAIL);
	if (!map[i + 1] || !map[i + 1][j] || !(ft_strchr("10NSEW", map[i + 1][j])))
		return(FAIL);
	if (!map[i][j - 1] || !(ft_strchr("10NSEW", map[i][j - 1])))
		return(FAIL);
	if (!map[i][j + 1] || !(ft_strchr("10NSEW", map[i][j + 1])))
		return(FAIL);	
	return (SUCCESS);
}


int	map_verif(char **map)
{
	int	i;
	int	j;

	i = 0;
	while(map[i])
	{
		j = 0;
		while(map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == ' ' )
				j++;
			else if (ft_strchr("0NSWE", map[i][j]))
			{
				if (check_surroundings(map, i, j) == SUCCESS)
					j++;
				else
					return (FAIL);
			}
		}
		i++;
	}
	return(SUCCESS);
}

char	**build_map(t_list *map_lst)
{
	char	**map;
	int		size;
	int		i;

	i = 0;
	size = map_size(map_lst);
	map = malloc(sizeof(char **) * (size + 1));
	if (!map)
		return (NULL);
	map = map_fill(map, map_lst, size);
	if (!map)
		return (NULL);
	if (map_verif(map) == FAIL)
		return (NULL);
	return (map);
}

int	get_player(t_world *world, char **map)
{
	//search for player - count should be 1;
	// when finding player : put it in pos; and dir;
	// when finding a player if count is > than 1 : return error.
}

int	check_map(t_world *world, t_list *read)
{
	t_list	*map_lst;

	(void)world;
	map_lst = isolate_map(read);
	world->map = build_map(map_lst);
	if (!world->map)
		return(ft_clear(map_lst), FAIL);
	if (get_player(world, world->map) = FAIL)
		return(ft_clear(map_lst), FAIL);
	return (ft_clear(map_lst), SUCCESS);
}