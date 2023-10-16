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