#include "ft_printf.h"
//the whole idea is to read through the string, parse the input 
//and process the data if nessacary

//this func will take the format and the argp
//and it will process and print the things 
//by calling specific helper func
static void	handle_specifier(t_format *format, char *input, int idx)
{
	if (input[idx] == 'c')
		process_char(format);
	if (input[idx] == 's')
		process_str(format);
	if (input[idx] == 'i' || input[idx] == 'd')
		process_dec(format);
	if (input[idx] == 'u')
		process_u(format);
	if (input[idx] == 'x' || input[idx] == 'X')
		process_x(format);
	if (input[idx] == 'p')
		process_ptr(format);
	if (input[idx] == '%')
		format->count += write(1, &input[idx], 1);
}

//this function will set a format struct into default values
static t_format	*reset_format(t_format *flags)
{
	flags->sign = 0;
	flags->prc = 0;
	flags->dot = 0;
	flags->minus = 0;
	flags->count = 0;
	flags->width = 0;
	flags->spc = 0;
	flags->zero = 0;
	flags->cap_x = 0;
	flags->hash = 0;
	return (flags);
}

static int	is_specifier(char c)
{
	char	*specs;

	specs = "csupdiuxX%";
	if (ft_strchr(specs, c))
		return (1);
	return (0);
}

//this function will trverse through the input string 
//in the case of encountering %, it does :
//1. reset the format type
//2. populate the format type
//3. process the format and print accordingly with argp
//if not, just print that character to the screen
static int	handle_flags(t_format *flags, char *input, int idx)
{
	while (!is_specifier(input[idx]))
	{
		if (input[idx] == '-')
			flags->minus = 1;
		if (input[idx] == ' ')
			flags->spc = 1;
		if (ft_isdigit(input[idx]) && !flags->prc && input[idx - 1] != '.')
			flags->width = (flags->width * 10) + (input[idx] - '0');
		else if (ft_isdigit(input[idx]) && flags->dot)
			flags->prc = (flags->prc * 10) + (input[idx] - '0');
		if (input[idx] == '0' && !flags->minus && !flags->prc && !flags->width)
			flags->zero = 1;
		if (input[idx] == '+')
			flags->sign = 1;
		if (input[idx] == '.')
			flags->dot = 1;
		if (input[idx] == '#')
			flags->hash = 2;
		idx++;
	}
	if (input[idx] == 'X')
		flags->cap_x = 1;
	handle_specifier(flags, input, idx);
	return (idx);
}

int	ft_printf(const char *input, ...)
{
	t_format	*flags;
	int			res;
	int			i;

	res = 0;
	flags = (t_format *)malloc(sizeof(t_format));
	i = -1;
	va_start(flags->args, input);
	while (input[++i])
	{
		flags = reset_format(flags);
		if (input[i] == '%')
			i = handle_flags(flags, (char *)input, i + 1);
		else
			res += write(1, &input[i], 1);
		res += flags->count;
	}
	va_end(flags->args);
	free(flags);
	return (res);
}
// #include <stdio.h>
// #include <limits.h>
// int	main()
// {
// 	//char *s = "vsdfasdfasdf";
// 	char *s2 = NULL;	
// 	//int		d = 2323;
// 	//unsigned int a = 123;
// 	//long g = 234;

// 	int res = ft_printf("|%12s|", s2);
// 	printf("\n");
// 	int res2 = printf("|%12s|", s2);
// 	printf("\n");
// 	printf("%d\n", res);
// 	printf("%d\n",res2);
// 	// printf(" %03d ", -11);
// 	return 0;
// }
