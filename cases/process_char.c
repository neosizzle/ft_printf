#include "ft_printf.h"

void	process_char(t_format *flags)
{
	if (!flags->width && !flags->minus)
		print_char(flags);
	else if (flags->width && !flags->minus)
		print_char_wdt(flags);
	else if (flags->width && flags->minus)
		print_char_wdt_minus(flags);
}

void	print_char(t_format *flags)
{
	ft_putchar_fd(va_arg(flags->args, int), 1);
	flags->count += 1;
}

void	print_char_wdt(t_format *flags)
{
	int		width;
	char	c;

	width = flags->width;
	while (width-- > 1)
	{
		ft_putchar_fd(' ', 1);
		flags->count += 1;
	}
	c = va_arg(flags->args, int);
	flags->count += 1;
	ft_putchar_fd(c, 1);
}

void	print_char_wdt_minus(t_format *flags)
{
	int		width;
	char	c;

	width = flags->width;
	c = va_arg(flags->args, int);
	flags->count += 1;
	ft_putchar_fd(c, 1);
	while (width-- > 1)
	{
		ft_putchar_fd(' ', 1);
		flags->count += 1;
	}
}
