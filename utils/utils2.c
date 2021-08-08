#include "ft_printf.h"

static long long	get_len(long long n)
{
	long long	res;

	res = 0;
	if (!n)
		return (1);
	while (n)
	{
		n /= 10;
		res++;
	}
	return (res);
}

static long long	conv_to_uns(long long n)
{
	if (n < 0)
		return ((unsigned int)(n *= -1));
	return ((unsigned int) n);
}

static char	last_digit_to_char(long long n)
{
	if (!n)
		return ('0');
	return ((char)(n % 10) + '0');
}

char	*ft_itoa_long(long long n)
{
	char	*res;
	int		len;

	len = get_len(n);
	if (n < 0)
		++len;
	res = (char *)malloc(sizeof(char) * (len + 1));
	if (!res)
		return (0);
	res[len] = 0;
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		res[0] = '-';
	n = conv_to_uns(n);
	while (n > 0)
	{
		res[--len] = last_digit_to_char(n);
		n /= 10;
	}
	return (res);
}

// #include <stdio.h>
// int main(int argc, char const *argv[])
// {
// 	char *res = ft_itoa_long(4294967295);
// 	printf("%s\n", res);
// 	free(res);
// 	return 0;
// }
