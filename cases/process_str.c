#include "ft_printf.h"

//this function will evaluate the final spaces
//and percision of a format
static void	count_spc_prc(t_format *flags, int *space, char *str)
{
	int	len;

	len = ft_strlen(str);
	*space = 0;
	if (!flags->prc && flags->dot)
		flags->prc = 0;
	else if (!flags->prc || flags->prc > len)
		flags->prc = len;
	if (flags->width > flags->prc)
		*space = flags->width - flags->prc;
}

//this function will process the conversion for string
//it first checks for null bytes
//then it calls for helper to evaluate
//the spaces for with and perc
//prints width first then content
//and vice versa if minus
//adds num of printed chars to format->count
void	process_str(t_format *flags)
{
	char	*str;
	int		space;

	str = va_arg(flags->args, char *);
	if (!str)
		str = "(null)";
	count_spc_prc(flags, &space, str);
	if (flags->minus)
	{
		write(1, str, flags->prc);
		ft_putnchar_fd(' ', space, 1);
	}
	else
	{
		ft_putnchar_fd(' ', space, 1);
		write(1, str, flags->prc);
	}
	flags->count = flags->prc + space;
}
