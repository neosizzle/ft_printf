#include "ft_printf.h"

//this file has functions that handles the strings

static void	width_write(t_format format, char *string, int len, int *p_l)
{
	if (format.width.exist)
			ft_handle_width(p_l, format.width.value - (int)len, 1);
	write(1, string, len);
}

static void	write_width(t_format format, char *string, int len, int *p_l)
{
	write(1, string, len);
	if (format.width.exist)
			ft_handle_width(p_l, format.width.value - (int)len, 1);
}

//handle str (main func)
//ft_putstr_fd("(null)", 1);
void	ft_handlestr(int *print_len, t_format format, va_list argp)
{
	char	*string;
	size_t	len;

	string = va_arg(argp, char *);
	if (string == NULL)
	{
		ft_putstr_fd("(null)", 1);
		*print_len += 6;
		return ;
	}
	len = ft_strlen(string);
	if (format.percision.exist)
		len = ft_min(ft_strlen(string), format.percision.value);
	if (format.is_minus)
		write_width(format, string, len, p_l);
	else
		width_write(format, string, len, p_l);
	*print_len += (int)len;
}
