#include "parsing.h"

int	check_surroundings(char **map, int i, int j)
{
	if (i == 0 || j == 0 || i == ft_table_size(map)
		|| j == (int)ft_strlen(map[i]))
		return (FAIL);
	if (!map[i - 1] || !map[i - 1][j] || !(ft_strchr("10NSEW", map[i - 1][j])))
		return (FAIL);
	if (!map[i + 1] || !map[i + 1][j] || !(ft_strchr("10NSEW", map[i + 1][j])))
		return (FAIL);
	if (!map[i][j - 1] || !(ft_strchr("10NSEW", map[i][j - 1])))
		return (FAIL);
	if (!map[i][j + 1] || !(ft_strchr("10NSEW", map[i][j + 1])))
		return (FAIL);
	return (SUCCESS);
}

int	player_info(t_world *world, char **map, int i, int j)
{
	if (world->setup->pos.x != 0 || world->setup->pos.y != 0)
		return (FAIL);
	world->setup->pos.x = i;
	world->setup->pos.y = j;
	if (map[i][j] == 'N')
		world->setup->dir.y = 1;
	else if (map[i][j] == 'S')
		world->setup->dir.y = -1;
	else if (map[i][j] == 'E')
		world->setup->dir.x = 1;
	else if (map[i][j] == 'W')
		world->setup->dir.x = -1;
	return (SUCCESS);
}

int	map_verif(t_world *world, char **map)
{
	int	i;
	int	j;

	i = -1;
	while (map[++i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == '1' || map[i][j] == ' ' )
				j++;
			else if (ft_strchr("0NSWE", map[i][j]))
			{
				if (map[i][j] != '0' && player_info(world, map, i, j)) 
					return (FAIL); // Too many players on map;
				if (!check_surroundings(map, i, j))
					j++;
				else
					return (FAIL); // The map is not enclosed in walls
			}
			else
				return(FAIL); // Unkmown identifyer in map
		}
	}
	return (SUCCESS);
}