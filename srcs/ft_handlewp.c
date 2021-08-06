#include "ft_printf.h"

//this file has functions that handles the width and percison
void	ft_handle_width(int *print_len, int width, int is_space)
{
	char	c;

	if (is_space)
		c = ' ';
	else
		c = '0';
	while (width > 0)
	{
		ft_putchar_fd(c,1);
		width--;
		(*print_len)++;
	}
	
}

// void	ft_handle_percision(int num_len, long *num, int percision);
// {

// }