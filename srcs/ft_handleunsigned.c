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
static char	*ft_itoa_uns(unsigned int num)
{
	char	*res;
	int		i;

	i = get_unsigned_num_len(num);
	res = (char *)malloc(sizeof(char) * i + 1);
	res[i--] = 0;
	if (num == 0)
	{
		res[0] = '0';
		return (res);
	}
	while (num > 0)
	{
		res[i--] = (num % 10 ) + '0';
		num /= 10;
	}
	return (res);
}

static void	print_width_write(int * p_l, t_format format, char *nstr, int n)
{
	if (format.width.exist)
			ft_handle_width(p_l, format.width.value - n, format.is_space);
	write(1, nstr, n);
}

//shell
void	ft_handle_unsigned(int *p_l, t_format format, va_list argp)
{
	unsigned int	num;
	int				num_len;
	char			*num_str;

	num = va_arg(argp, unsigned int);
	num_len = get_unsigned_num_len(num);
	num_str = ft_itoa_uns(num);
	if (format.percision.exist)
	{
		num_str = generate_percise_str(num_str, format.percision.value, num);
		num_len = ft_strlen(num_str);
	}
	if (format.is_minus)
	{
		write(1, num_str, num_len);
		if (format.width.exist)
			ft_handle_width(p_l, format.width.value - num_len, format.is_space);
	}
	else
		print_width_write(p_l, format, num_str, num_len);
	(*p_l) += num_len;
	free(num_str);
}
