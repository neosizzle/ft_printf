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

static void	write_width_num(int nl, t_format format, int *p_l, char *num_str)
{
	if (format.width.exist)
		ft_handle_width(p_l, format.width.value - nl, format.is_space);
	ft_putstr_fd(num_str, 1);
}

static void	init_vars(int *numlen, char **num_str, int num, char *hex)
{
	*numlen = get_num_len_base(num, 16);
	*num_str = ft_itoa_base(num, hex, *numlen, 16);
}	

void	ft_handlehex(int *p_l, t_format format, va_list argp)
{
	unsigned int	num;
	int				numlen;
	char			*hex;
	char			*num_str;

	hex = gen_hex(format.type);
	num = va_arg(argp, unsigned int);
	init_vars(&numlen, &num_str, num, hex);
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
		write_width_num(numlen, format, p_l, num_str);
	(*p_l) += numlen;
	free(num_str);
}