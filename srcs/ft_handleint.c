#include "ft_printf.h"

//this file has functions that handles the ints

static int	get_signed_num_len(int num)
{
	int	res;

	res = 0;
	if (num <= 0)
	{
		num *= -1;
		res++;
	}
	while (num)
	{
		num /= 10;
		res++;
	}
	return (res);
}

//allocates mem and converts long to str
char	*ft_itoa_len(int num, int *print_len)
{
	char	*res;
	int		i;

	i = get_signed_num_len(num);
	res = (char *)malloc(sizeof(char) * get_signed_num_len(num) + 1);
	res[i--] = 0;
	if (num == 0)
	{
		res[0] = '0';
		(*print_len)++;
		return (res);
	}
	if (num < 0)
	{
		res[0] = '-';
		num *= -1;
		(*print_len)++;
	}
	while (num > 0)
	{
		res[i--] = (num % 10 ) + '0';
		num /= 10;
	}
	return (res);
}

static void	write_negative(char *num_str, int num_len)
{
	int	i;

	i = 1;
	while (i < num_len)
		ft_putchar_fd(num_str[i++], 1);
}

//shell
void	ft_handleint(int *p_l, t_format format, va_list argp)
{
	int				n;
	int				nlen;
	char			*n_str;

	n = va_arg(argp, int);
	nlen = get_signed_num_len(n);
	n_str = ft_itoa(n);
	if (format.percision.exist)
	{
		n_str = generate_percise_str(n_str, format.percision.value, n);
		nlen = ft_strlen(n_str);
	}
	if (format.is_minus)
		wri_wid_num(format, n_str, nlen, p_l);
	else
	{
		if (format.width.exist && !format.is_space)
			ft_width_n(p_l, format.width.value - nlen, format.is_space, n);
		if (n < 0 && !format.is_space)
			write_negative(n_str, nlen);
		else
			write(1, n_str, nlen);
	}
	(*p_l) += nlen;
	free(n_str);
}
