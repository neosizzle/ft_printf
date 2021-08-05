#include "ft_printf.h"

//this file has functions that handles the ints

static int	get_signed_num_len(long num)
{
	int	res;

	res = 0;
	while (num)
	{
		num /= 10;
		res++;
	}
	return (res);
}

//allocates mem and converts long to str
char	*ft_ltoa(long num)
{
	char	*res;
	int		i;
	int		negative;

	negative = 0;
	i = get_signed_num_len(num);
	res = (char *)malloc(sizeof(char) * get_signed_num_len(num) + 1);
	if (num < 0)
	{
		res[0] = '-';
		negative = 1;
	}
	while (num)
	{
		res[i--] = '0' + (num % 10);
		num /= 10;
	}
	if (!negative)
		++res;
	return (res);
}

//shell
void	ft_handleint(int *print_len, t_format format, va_list argp)
{
	long	num;
	int				num_len;
	char			*num_str;

	num = va_arg(argp, long);
	num_len = get_signed_num_len(num);
	if (format.width.exist)
		ft_handle_width(print_len, format.width.value - num_len, 1);
	if (format.percision.exist)
		ft_handle_percision(print_len, num, format.percision.value);
	num_str = ft_ltoa(num);
	write(1, num_str, num_len);
	(*print_len) += num_len;
	//free(num_str);
}
