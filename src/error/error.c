#include "error.h"

void	ft_error_msg(char *err, int *ptr, char *arg, char *str)
{
	if (err)
		ft_putstr_fd(err, 2);
	if (arg)
		ft_putstr_fd(arg, 2);
	if (ptr)
	{
		ft_putstr_fd("(", 2);
		ft_putnbr_fd(*ptr, 2);
		ft_putstr_fd(")", 2);
	}
	if (arg)
		ft_putstr_fd(": ", 2);
	if (str)
	{
		ft_putstr_fd(str, 2);
		ft_putstr_fd("\n", 2);
	}
	else
		perror(NULL);
}
