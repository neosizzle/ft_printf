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
		(*print_len) ++;
		return (res);
	}
	if (num < 0)
	{
		res[0] = '-';
		num *= -1;
		(*print_len) ++;
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
void	ft_handleint(int *print_len, t_format format, va_list argp)
{
	int	num;
	int				num_len;
	char			*num_str;

	num = va_arg(argp, int);
	num_len = get_signed_num_len(num);
	num_str = ft_itoa(num);
	if (format.percision.exist)
	{
		num_str = generate_percise_str(num_str, format.percision.value, num);
		num_len = ft_strlen(num_str);
	}
	if (format.is_minus)
	{
		write(1, num_str, num_len);
		if (format.width.exist)
			ft_handle_width(print_len, format.width.value - num_len, format.is_space);
	}
	else
	{
		if (format.width.exist)
			ft_handle_width_num(print_len, format.width.value - num_len, format.is_space, num);
		if (num < 0 && !format.is_space)
			write_negative(num_str, num_len);
		else
			write(1, num_str, num_len);
	}
	(*print_len) += num_len;
	free(num_str);
}
