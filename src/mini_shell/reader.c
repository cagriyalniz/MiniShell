#include "../../include/header.h"

char  *ft_read_line(void)
{
	char *str;
	
	str = readline("->");
	// if(!str)
	// {
	// 	ft_putstr_fd("->exit BEN BURDAYIM\n", 1);
	// 	exit(1);
	// }
		
	return (str);
}