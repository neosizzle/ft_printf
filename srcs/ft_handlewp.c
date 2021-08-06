#include "ft_printf.h"
#include <stdio.h>

//this file has functions that handles the width and percison
void	ft_handle_width(int *print_len, int width, int is_space)
{
	char	c;

	if (is_space)
		c = ' ';
	else
		c = '0';
	while (width > 0)
	{
		ft_putchar_fd(c, 1);
		width--;
		(*print_len)++;
	}
}

void	ft_width_n(int *print_len, int width, int is_space, int num)
{
	char	c;

	if (is_space)
		c = ' ';
	else
		c = '0';
	if (num < 0 && !is_space)
	{
		ft_putchar_fd('-', 1);
	}
	while (width > 0)
	{
		ft_putchar_fd(c, 1);
		width--;
		(*print_len)++;
	}
}

char	*generate_percise_str(char *num_str, int percision, long num)
{
	char	*res;
	int		i;
	int		len;

	res = (char *)malloc(sizeof(char) * (percision + 2));
	len = (int)ft_strlen(num_str);
	if (len > percision)
	{
		free(res);
		return (num_str);
	}
	i = 0;
	if (num < 0)
	{
		res[i++] = '-';
		len -= 2;
	}
	while (i < percision - len)
		res[i++] = '0';
	res[i] = 0;
	if (num < 0)
		ft_strlcat(res, num_str + 1, percision + 2);
	else
		ft_strlcat(res, num_str, percision + 1);
	free(num_str);
	return (res);
}