#include "../includes/ft_minirt.h"

void	error_quit(char *str)
{
	ft_putstr_fd(str, 1);
	exit(-1);
}