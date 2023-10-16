# include "parsing.h"

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