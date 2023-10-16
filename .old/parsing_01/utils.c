#include "wonderland.h"
#include "error.h"
#include "parsing.h"

int	empty_line(char *str)
{
	int	i;

	i = 0;
	while(str[i])
	{
		if ((str[i] >= 7 && str[i] <= 13) || str[i] == 32)
			i++;
		else
			return (FALSE);
	}
	return (TRUE);
}

int	file_access(char *path)
{
	int	fd;
	int	i;

	i = ft_strlen(path);
	if (path[i - 1] == '\n')
		path[i - 1] = '\0';
	fd = open(path, O_RDONLY);
	if (fd < 0)
		return (ft_error_msg(ERR, NULL, path, NULL), FAIL);
	return(SUCCESS);
}