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

void	ft_handle_width_num(int *print_len, int width, int is_space, char **num_str, int num)
{
	char	c;

	if (is_space)
		c = ' ';
	else
		c = '0';
	if (num < 0 && !is_space)
	{
		ft_putchar_fd('-',1);
		(*num_str)++;
		(*print_len)++;
	}
	while (width > 0)
	{
		ft_putchar_fd(c,1);
		width--;
		(*print_len)++;
	}
	
}