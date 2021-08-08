#include "ft_printf.h"
#include <stdio.h>

//function that evaluates all the flags and generate
//the final count for with and prc
static void	count_spc_prc(t_format *flags, char *numstr)
{
	size_t	abs_len;
	size_t	len;

	len = ft_strlen(numstr);
	abs_len = ft_strlen(numstr);
	if (numstr[0] == '-')
		abs_len--;
	if ((int) abs_len >= flags->prc)
		flags->prc = 0;
	if (flags->prc > (int) abs_len)
		flags->prc -= abs_len;
	if (flags->prc <= 0)
		flags->prc = 0;
	if (flags->width <= 0 || (flags->minus && flags->width <= (int) abs_len))
		flags->width = 0;
	if (flags->width)
		flags->width = flags->width - (int) len - flags->prc;
	if (flags->width <= 0)
		flags->width = 0;
}

//prints the space and the + sign
static void	process_sp_sign(t_format *flags)
{
	if (flags->spc)
		ft_putchar_fd(' ', 1);
	if (flags->sign)
		ft_putchar_fd('+', 1);
}

//change
static void	process_udec(t_format *flags, char *numstr)
{
	process_sp_sign(flags);
	if (flags->zero)
	{
		ft_putnchar_fd('0', flags->width, 1);
		ft_putstr_fd(numstr, 1);
	}
	else
	{
		if (flags->minus)
		{
			ft_putnchar_fd('0', flags->prc, 1);
			ft_putstr_fd(numstr, 1);
			ft_putnchar_fd(' ', flags->width, 1);
		}
		else if (!flags->minus)
		{
			ft_putnchar_fd(' ', flags->width, 1);
			ft_putnchar_fd('0', flags->prc, 1);
			ft_putstr_fd(numstr, 1);
		}
	}
	flags->count += ft_strlen(numstr) + flags->width + flags->prc
		+ flags->sign + flags->spc;
}

//evaluates total prc and width and 
//call seperate helpers according
//to the polarity
void	process_u(t_format *flags)
{
	unsigned int		num;
	char				*numstr;

	num = va_arg(flags->args, unsigned int);
	numstr = ft_itoa_long(num);
	count_spc_prc(flags, numstr);
	process_udec(flags, numstr);
	free(numstr);
}
