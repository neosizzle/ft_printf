#include "ft_printf.h"

//this file has functions that handles the ints

//allocates mem and converts long to str
char	*ft_ltoa(unsigned long num)
{
	char	*res;
	int		i;

	res = (char *)malloc(sizeof(char) * get_num_len(num));
	while (num)
	{
		res[i++] = num % 10;
		num /= 10;
	}
	return (res);
}

//shell
void	ft_handleint(int *print_len, t_format format, va_list argp)
{
	unsigned long	num;
	int				num_len;
	char			*num_str;

	num = va_arg(argp, unsigned long);
	num_len = get_num_len(num);
	if (format.width.exist)
		ft_handle_width(print_len, format.width.value - num_len, 1);
	if (format.percision.exist)
		ft_handle_percision(print_len, num, format.percision);
	num_str = ft_ltoa(num);
	write(1, num_str, num_len);
	free(num_str);
}
