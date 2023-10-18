#include "parsing.h"

t_list	*isolate_map(t_list *read)
{
	t_list	*cpy;
	t_list	*map;

	map = NULL;
	cpy = ft_lstlast(read);
	while (cpy && cpy->prev)
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

char	**map_fill(char **map, t_list *map_lst, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		map[i] = ft_strdup((char *)map_lst->content);
		if (!map[i])
			return (ft_free(map), NULL);
		if (map[i][ft_strlen(map[i]) - 1] == '\n')
			map[i][ft_strlen(map[i]) - 1] = '\0';
		i++;
		map_lst = map_lst->next;
	}
	map[size] = NULL;
	return (map);
}

char	**build_map(t_world *world, t_list *map_lst)
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
	if (map_verif(world, map, -1, 0) == FAIL)
		return (ft_free(map), NULL);
	return (map);
}

int	parsing_map(t_world *world, t_list *read)
{
	t_list	*map_lst;

	(void)world;
	map_lst = isolate_map(read);
	world->map = build_map(world, map_lst);
	if (!world->map)
		return (ft_clear(map_lst), FAIL);
	if (world->setup->pos.x == 0 || world->setup->pos.y == 0)
		return(ft_clear(map_lst), ft_error_msg(ERR, NULL, IMP, NPL), FAIL); //No player on map !
	return (ft_clear(map_lst), SUCCESS);
}
