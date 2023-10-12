#include "wonderland.h"
#include "error.h"
#include "parsing.h"

int file_name(char **argv)
{
	if (ft_strstr(argv[1], ".cub\0"))
		return (0);
	return(ft_error_msg(ERR, NULL, "Invalid file extention", USG), 1);
}

int	read_file(char **argv, t_list **read)
{
	int		fd;
	char	*line;
	t_list	*new;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error_msg(ERR, NULL, "Opening file", NULL), 1);
	while (fd > 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		new = ft_lstnew(line);
		if (!new)
			return(ft_lstclear(read, free), 1);
		ft_lstadd_back(read, new);
	}
	close(fd);
	return (0);
}

int	check_content(t_world *world, t_list **read)
{
	(void)world;	
	(void)read;	
	return (0);
}

int	parsing(t_world *world, char **argv)
{
	t_list	*read;

	read = NULL;
	if (file_name(argv) || read_file(argv, &read))
		clean_exit(world);
	if (check_content(world, &read))
	{
		ft_lstclear(&read, free);
		clean_exit(world);
	}	
	return (0);
}

	// t_list	*cpy;
	// cpy = read;
	// while (cpy != NULL)
	// {
	// 	printf("%s", (char *)cpy->content);
	// 	cpy = cpy->next;
	// }


/*
	1. check file extension vv
	2. file can be opened -> access rights vv 
	3. file is not empty 
	4. gnl -> read each line of the file and send it to correct location
	5. arrived at map in file : strchr(line, ' ') == NULL 
*/