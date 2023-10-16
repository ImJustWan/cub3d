#include "wonderland.h"
#include "error.h"
#include "parsing.h"

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
	if (get_map(world, read));
		return(ft_clear(read), FAIL);
	// if (check_description(world, read))
	// 	return(ft_clear(read), FAIL);
	// check all 6 elements of the description file;
	// check map validity;
	ft_clear(read);
	return (SUCCESS);
}
/*
	1. check file extension vv
	2. file can be opened -> access rights vv 
	3. file is not empty 
	4. gnl -> read each line of the file and send it to correct location
	5. arrived at map in file : strchr(line, ' ') == NULL 




*/
	// t_list *cpy;
	// cpy = read;
	// while(cpy)
	// {
	// 	printf("read = %s", (char *)cpy->content);
	// 	cpy = cpy->next;
	// }