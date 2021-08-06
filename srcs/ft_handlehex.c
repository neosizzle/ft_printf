#include "ft_printf.h"
//this file has functions that handles the hex

int get_num_len_base(unsigned int num, int base)
{
	int	res;

	res = 0;
	if (num == 0)
		return(++res);
	while (num > 0)
	{
		res++;
		num /= base;
	}
	return (res);
}

char	*ft_itoa_base(unsigned int num, char *encode, int len, unsigned int base)
{
	char *res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	res[len--] = 0;
	while (len >= 0)
	{
		res[len] = encode[num % base];
		num /= base;
		len--;
	}
	return (res);
}

void	ft_handlehex(int *print_len, t_format format, va_list argp)
{
	unsigned int	num;
	int				numlen;
	char			*hex;
	char			*num_str;

	if (format.type == HEX_LOWCASE)
		hex = "0123456789abcdef";
	else
		hex = "0123456789ABCDEF";
	num = va_arg(argp, unsigned int);
	numlen = get_num_len_base(num, 16);
	num_str = ft_itoa_base(num, hex, numlen, 16);
	if (format.is_minus)
	{
		ft_putstr_fd(num_str, 1);
		if (format.width.exist)
			ft_handle_width(print_len, format.width.value - numlen, 1);
	}
	else
	{
		if (format.width.exist)
			ft_handle_width(print_len, format.width.value - numlen, 1);
		ft_putstr_fd(num_str, 1);
	}
	(*print_len) += numlen;
	free(num_str);
}