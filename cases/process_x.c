#include "ft_printf.h"

//function that evaluates all the flags and generate
//the final count for with and prc
static void	count_spc_prc(t_format *flags, char *numstr)
{
	int	abs_len;
	int	len;

	len = (int) ft_strlen(numstr);
	abs_len = (int) ft_strlen(numstr);
	if (numstr[0] == '-')
		abs_len--;
	if (abs_len >= flags->prc)
		flags->prc = 0;
	if (flags->prc > abs_len)
		flags->prc -= abs_len;
	if (flags->prc <= 0)
		flags->prc = 0;
	if (flags->width <= 0 || (flags->minus && flags->width <= abs_len))
		flags->width = 0;
	if (flags->width)
		flags->width = flags->width - len - flags->prc;
	if (flags->width <= 0)
		flags->width = 0;
}

//this function will print out the hex str
//progressively according to the flags
static void	print_x(t_format *flags, char *numstr, char *prefix)
{
	if (flags->zero)
	{
		ft_putnchar_fd('0', flags->width, 1);
		ft_putstr_fd(numstr, 1);
		return ;
	}
	if (flags->minus)
	{
		if (flags->hash)
			ft_putstr_fd(prefix, 1);
		ft_putnchar_fd('0', flags->prc, 1);
		ft_putstr_fd(numstr, 1);
		ft_putnchar_fd(' ', flags->width, 1);
	}
	else if (!flags->minus)
	{
		ft_putnchar_fd(' ', flags->width, 1);
		if (flags->hash)
			ft_putstr_fd(prefix, 1);
		ft_putnchar_fd('0', flags->prc, 1);
		ft_putstr_fd(numstr, 1);
	}
}

//basically itoa_base16 but 
//takes the big x into account
static char	*to_hex(long long num, t_format *flags)
{
	char	res[1024];
	int		i;
	int		offset;

	if (num == 0)
		return (ft_rev("0"));
	if (!flags->cap_x)
		offset = 87;
	else
		offset = 55;
	i = 0;
	while (num > 0)
	{
		res[i] = (num % 16) + '0';
		if (res[i] > '9')
			res[i] = (num % 16) + offset;
		num /= 16;
		i++;
	}
	res[i] = 0;
	return (ft_rev(res));
}

void	process_x(t_format *flags)
{
	long long	num;
	char		*hex;
	char		*prefix;

	prefix = "0x";
	num = va_arg(flags->args, int);
	if (num < 0)
		num = 4294967295 + num + 1;
	hex = to_hex(num, flags);
	count_spc_prc(flags, hex);
	if (hex[0] == '0' && flags->hash && ft_strlen(hex) == 1)
	{
		ft_putchar_fd('0', 1);
		flags->count += 1;
	}
	else
	{
		if (flags->cap_x)
			prefix = "0X";
		print_x(flags, hex, prefix);
		flags->count += ft_strlen(hex) + flags->width
			+ flags->prc + flags->sign + flags->spc
			+ flags->hash;
	}
	free(hex);
}
