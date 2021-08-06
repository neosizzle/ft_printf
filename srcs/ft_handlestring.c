#include "ft_printf.h"

//this file has functions that handles the strings

//handle str (main func)
void	ft_handlestr(int *print_len, t_format format, va_list argp)
{
	char	*string;
	size_t	len;

	string = va_arg(argp, char *);
	if (!string)
		ft_putstr_fd("(null)", 1);
	len = ft_strlen(string);
	if (format.percision.exist)
		len = ft_min(ft_strlen(string), format.percision.value);
	if (format.is_minus)
	{
		write(1, string, len);
		if (format.width.exist)
			ft_handle_width(print_len, format.width.value - (int)len, 1);
	}
	else
	{
		if (format.width.exist)
			ft_handle_width(print_len, format.width.value - (int)len, 1);
		write(1, string, len);
	}
	*print_len += (int)len;
}
