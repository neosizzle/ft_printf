//#include "ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
int	ft_strlen(const char *s)
{
	int	res;

	res = 0;
	while (s[res])
		res++;
	return (res);
}

void	ft_putnbr_fd_long(unsigned int num, int fd)
{
    char    c;

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

char    *ft_rev(char    *str)
{
    int     len;
    char    *res;
    int     i;

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

#include <stdio.h>
int main(int argc, char const *argv[])
{
    char    *str = "Dracecar";
    printf("%s\n", ft_rev(str));
}
