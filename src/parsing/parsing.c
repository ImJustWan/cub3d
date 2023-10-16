# include "parsing.h"

int	parsing(t_world *world, char **argv)
{
	t_list *read;

	read = NULL;
	if (file_name(argv) || read_file(argv, &read) || !read)
	{
		if(read)
			ft_clear(read);
		clean_exit(world);
	}
	if (check_map(world, read))
		return (ft_clear(read), FAIL);
	ft_clear(read);
	return (SUCCESS);
}
