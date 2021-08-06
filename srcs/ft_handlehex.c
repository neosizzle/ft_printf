#include "ft_printf.h"
//this file has functions that handles the hex

int	get_num_len_base(unsigned int num, int base)
{
	int	res;

	res = 0;
	if (num == 0)
		return (++res);
	while (num > 0)
	{
		res++;
		num /= base;
	}
	return (res);
}

char	*ft_itoa_base(unsigned int num, char *enc, int len, unsigned int base)
{
	char	*res;

	res = (char *)malloc(sizeof(char) * (len + 1));
	res[len--] = 0;
	while (len >= 0)
	{
		res[len] = enc[num % base];
		num /= base;
		len--;
	}
	return (res);
}

static void	gen_hex(char c, char **hex)
{
	if (format.type == HEX_LOWCASE)
		return("0123456789abcdef");
	else
		return("0123456789ABCDEF");
}

static void	init_vars(int *numlen, int *num_str, char **hex, unsigned int *num , va_list argp)
{
	*numlen = get_num_len_base(num, 16);
	*num_str = ft_itoa_base(num, hex, numlen, 16);
	*hex = gen_hex(format.type);
	*num = va_arg(argp, unsigned int);
}	

void	ft_handlehex(int *p_l, t_format format, va_list argp)
{
	unsigned int	num;
	int				numlen;
	char			*hex;
	char			*num_str;

	init_vars(&numlen, &num_str, &hex, &num);
	if (format.percision.exist)
	{
		num_str = generate_percise_str(num_str, format.percision.value, num);
		numlen = ft_strlen(num_str);
	}
	if (format.is_minus)
	{
		ft_putstr_fd(num_str, 1);
		if (format.width.exist)
			ft_handle_width(p_l, format.width.value - numlen, format.is_space);
	}
	else
	{
		if (format.width.exist)
			ft_handle_width(p_l, format.width.value - numlen, format.is_space);
		ft_putstr_fd(num_str, 1);
	}
	(*p_l) += numlen;
	free(num_str);
}