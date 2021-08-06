#include "ft_printf.h"

//this file has functions that handles the percent sign
void	ft_handlepercent(int *print_len)
{
	ft_putchar_fd('%', 1);
	(*print_len)++;
}
