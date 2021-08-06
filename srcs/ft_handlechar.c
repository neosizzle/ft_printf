#include "ft_printf.h"

//this file has functions that handles the characters
//null char undefined behaviour?
void	ft_handlechar(int *print_len, t_format format, va_list argp)
{
	int	c;

	c = va_arg(argp, int);
	if (format.is_minus)
	{
		ft_putchar_fd(c, 1);
		if (format.width.exist)
			ft_handle_width(print_len, format.width.value - 1, 1);
	}
	else
	{
		if (format.width.exist)
			ft_handle_width(print_len, format.width.value - 1, 1);
		ft_putchar_fd(c, 1);
	}
	(*print_len)++;
}