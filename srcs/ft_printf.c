#include "ft_printf.h"
//the whole idea is to read through the string, parse the input 
//and process the data if nessacary

//this func will take the format and the argp
//and it will process and print the things 
//by calling specific helper func
void	process_format(t_format format, int *print_len, va_list argp)
{
	char	type;

	type = format.type;
	if (type == STRING)
		ft_handlestr(print_len, format, argp);
	else if (type == CHARACTER)
		ft_handlechar(print_len, format, argp);
	else if (type == POINTER)
		ft_handlepointer(print_len, format, argp);
	else if (type == INTEGER || type == DECIMAL)
		ft_handleint(print_len, format, argp);
	else if (type == UNSIGNED_INTEGER)
		ft_handle_unsigned(print_len, format, argp);
	else if (type == HEX_LOWCASE || type == HEX_UPCASE)
		ft_handlehex(print_len, format, argp);
	else if (type == PERCENT)
		ft_handlepercent(print_len);
}

//this function will populate a format struct according
//to the input. 
//returns 1 if succeed and 0 if it doses not
int	populate_format(t_format *format, char **input, int *index)
{
	char	current;

	current = (*input)[*index];
	if ((*input)[*index] == '-')
		toggle_minus(format, index);
	if ((*input)[*index] == '0')
		toggle_zero(format, index);
	if (ft_isdigit((*input)[*index]) && (*input)[*index] != '0')
		toggle_width(format, input, index);
	if ((*input)[*index] == '.')
	{
		format->percision.exist = YES;
		if (ft_isdigit((*input)[++(*index)]))
			format->percision.value = ft_move_atoi(input, index);
		else
			format->percision.value = 0;
	}
	current = (*input)[*index];
	if (is_in_enum(current))
		format->type = current;
	else
		return (0);
	(*input)++;
	return (1);
}

//this function will set a format struct into default values
void	reset_format(t_format *format)
{
	format->is_minus = NO;
	format->is_space = YES;
	format->width.exist = NO;
	format->percision.exist = NO;
	format->type = TBC;
}

//this function will trverse through the input string 
//in the case of encountering %, it does :
//1. reset the format type
//2. populate the format type
//3. process the format and print accordingly with argp
//if not, just print that character to the screen
int	parse_input(char *input, va_list argp)
{
	int			print_len;
	int			i;
	t_format	format;

	print_len = 0;
	i = 0;
	while (input[i])
	{
		if (input[i] == '%' && input[i + 1])
		{
			i++;
			reset_format(&format);
			if (!populate_format(&format, &input, &i))
				return (-1);
			process_format(format, &print_len, argp);
		}
		else
		{
			ft_putchar_fd(input[i++], 1);
			print_len++;
		}
	}
	return (print_len);
}

int	ft_printf(const char *input, ...)
{
	va_list	argp;
	int		res;

	va_start(argp, input);
	res = parse_input((char *)input, argp);
	return (res);
}

#include <stdio.h>
#include <limits.h>
int	main()
{
	//char *s = "vsdfasdfasdf";
	char *s2 = NULL;	
	//int		d = 2323;
	//unsigned int a = 123;
	//long g = 234;

	int res = ft_printf(" %s", s2);
	printf("\n");
	int res2 = printf(" %s", s2);
	printf("\n");
	printf("%d\n", res);
	printf("%d\n",res2);
	// printf(" %03d ", -11);
	return 0;
}
