#include "ft_printf.h"
#include <stdio.h>

//this file has functions that handles the pointers

//this function returns the length of number
int	get_num_len(unsigned int num)
{
	int	res;

	res = 0;
	while (num)
	{
		num /= 10;
		res++;
	}
	return (res);
}

void	generate_addr_str(unsigned int addr, char *hex, int count, int *print_len)
{
	int	first;

	first = 1;
	if (addr == 0)
	{
		if (!count)
		{
			ft_putchar_fd(hex[addr % 16], 1);
			(*print_len) ++;
		}
		(*print_len) += count+2;
		return ;
	}
	generate_addr_str(addr >> 4, hex, count + 1, print_len);
	ft_putchar_fd(hex[addr % 16], 1);
}

void	ft_handlepointer(int *print_len, t_format format, va_list argp)
{
	unsigned int	addr;
	char			*hex;
	int				offset;

	addr = va_arg(argp, unsigned int);
	hex = "0123456789abcdef";
	//printf("%u\n", addr)
	if (addr > 2147483647)
		offset = 10;
	else
		offset = 11;
	if (format.width.exist)
		ft_handle_width(print_len, format.width.value - offset, 1);
	ft_putstr_fd("0x", 1);
	generate_addr_str(addr, hex, 0, print_len);
}