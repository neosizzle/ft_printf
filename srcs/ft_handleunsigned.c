#include "ft_printf.h"

//this file has functions that handles the unsigneds

static int	get_unsigned_num_len(unsigned int num)
{
	int	res;

	res = 0;
	if (num == 0)
	{
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
static char	*ft_itoa_uns(unsigned int num, int *print_len)
{
	char	*res;
	int		i;

	i = get_unsigned_num_len(num);
	res = (char *)malloc(sizeof(char) * i + 1);
	res[i--] = 0;
	if (num == 0)
	{
		res[0] = '0';
		(*print_len) ++;
		return (res);
	}
	while (num > 0)
	{
		res[i--] = (num % 10 ) + '0';
		num /= 10;
	}
	return (res);
}

//shell
void	ft_handle_unsigned(int *print_len, t_format format, va_list argp)
{
	unsigned int	num;
	int				num_len;
	char			*num_str;

	num = va_arg(argp, unsigned int);
	num_len = get_unsigned_num_len(num);
	if (format.width.exist)
		ft_handle_width(print_len, format.width.value - num_len, 1);
	if (format.percision.exist)
		ft_handle_percision(print_len, num, format.percision.value);
	num_str = ft_itoa_uns(num, print_len);
	write(1, num_str, num_len);
	(*print_len) += num_len;
	free(num_str);
}
