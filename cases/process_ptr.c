#include "ft_printf.h"

//this prints 0x0 and adds count 3 to format
static void	print_null_ptr(t_format *flags)
{
	flags->count += 3;
	ft_putstr_fd("0x0", 1);
}

//this evaluates the count and spaces
//needed fri width
static void	count_spc(t_format *flags, int *space, int strlen)
{
	*space = 0;
	if (flags->width > strlen)
	{
		*space = flags->width - strlen;
		flags->count += flags->width;
	}
	else
		flags->count += strlen;
}

//call helper to print null if ptr is null
//in case the ptr is negative (practically wont)
//it will print the largest value possible
//it then evaluates the spaces and count needed
//print values according to minus flag
void	process_ptr(t_format *flags)
{
	long long	num;
	char		*str;
	int			spaces;

	num = (long long)va_arg(flags->args, void *);
	if (!num)
		print_null_ptr(flags);
	else
	{
		if (num < 0)
			str = ft_itoa_base16(18446744073709551615U + num + 1);
		else
			str = ft_itoa_base16(num);
		count_spc(flags, &spaces, ft_strlen(str) + 2);
		if (!flags->minus)
			ft_putnchar_fd(' ', spaces, 1);
		ft_putstr_fd("0x", 1);
		ft_putstr_fd(str, 1);
		if (flags->minus)
			ft_putnchar_fd(' ', spaces, 1);
		free(str);
	}
}
