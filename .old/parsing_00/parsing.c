#include "wonderland.h"
#include "error.h"
#include "parsing.h"

int file_name(char **argv)
{
	if (ft_strstr(argv[1], ".cub\0"))
		return (SUCCESS);
	return(ft_error_msg(ERR, NULL, "Invalid file extention", USG), FAIL);
}

int	read_file(char **argv, t_list **read)
{
	int		fd;
	char	*line;
	t_list	*new;

	fd = open(argv[1], O_RDONLY);
	if (fd < 0)
		return (ft_error_msg(ERR, NULL, "Opening file", NULL), FAIL);
	while (fd > 0)
	{
		line = get_next_line(fd);
		if (line == NULL)
			break;
		new = ft_lstnew(line);
		if (!new)
			return(FAIL);
		ft_lstadd_back(read, new);
	}
	close(fd);
	return (SUCCESS);
}

// void	ft_lstdlone(t_list *lst, void (*del)(void*))
// {
// 	printf("check 4\n");
// 	if (!lst || !del)
// 		return ;
// 	else
// 	{
// 		del(lst->content);
// 		free(lst);
// 	}
// }

// void	ft_lstclr(t_list **lst, void (*del)(void*))
// {
// 	t_list	*tmp;

// 	printf("check 2\n");
// 	if (lst && del)
// 	{
// 		while (*lst)
// 		{
// 			tmp = (*lst)->next;
// 			ft_lstdlone(*lst, del);
// 			(*lst) = tmp;
// 		}
// 	}
// }

void    ft_clear(t_list *save)
{
    t_list    *temp;
    t_list    *next;

    temp = save;
    while (temp)
    {
        free(temp->content);
        next = temp->next;
        free(temp);
        temp = next;
    }
}

int	parsing(t_world *world, char **argv)
{
	t_list	*read;
	// t_list	*map;
	// t_list	*cpy;
	int		res;

	read = NULL;
	if (file_name(argv) || read_file(argv, &read) || !read)
		clean_exit(world);
	res = check_content(world, &read);
	if (res)
	{
		// ft_lstclr(&read, free);
		ft_clear(read);
		clean_exit(world);
	}
	// cpy = read;
	// while (cpy != NULL)
	// {
	// 	printf("%s", (char *)cpy->content);
	// 	cpy = cpy->next;
	// }
	// ft_lstclr(&read, free);
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