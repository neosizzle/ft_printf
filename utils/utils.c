#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>

void	ft_putnbr_fd_long(unsigned int num, int fd)
{
	char	c;

	if (num < 10)
	{
		c = num + '0';
		write(fd, &c, 1);
		return ;
	}
	c = num % 10 + '0';
	ft_putnbr_fd_long(num / 10, fd);
	write(fd, &c, 1);
}

char	*ft_rev(char *str)
{
	int		len;
	char	*res;
	int		i;

	len = ft_strlen(str) - 1;
	i = 0;
	res = (char *)malloc(sizeof(char) * (len + 2));
	if (!res)
		return (0);
	while (len >= 0)
	{
		res[i] = str[len];
		i++;
		len--;
	}
	res[i] = 0;
	return (res);
}

char	*ft_itoa_base16(unsigned long long num)
{
	char	res[1024];
	int		i;

	i = 0;
	while (num)
	{
		res[i] = (num % 16) + '0';
		if (res[i] > '9')
			res[i] = (num % 16) + ('a' - 10);
		num /= 16;
		i++;
	}
	res[i] = 0;
	return (ft_rev(res));
}

void	ft_putnchar_fd(char c, int n, int fd)
{
	while (n--)
		ft_putchar_fd(c, fd);
}

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
//     ft_putnchar_fd('d', 3, 1);
// }
