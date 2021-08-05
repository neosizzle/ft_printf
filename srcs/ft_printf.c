#include "ft_printf.h"
//the whole idea is to read through the string, parse the input 
//and process the data if nessacary

//this func will take the format and the argp
//and it will process and print the things 
//by calling specific helper func
void	process_format(t_format format, int *print_len, va_list argp)
{
	if (format.type == STRING)
	{
		(*print_len)++;
		ft_putstr_fd(va_arg(argp, char *), 1);
	}
}

//this function will populate a format struct according
//to the input. 
//returns 1 if succeed and 0 if it doses not
int	populate_format(t_format *format, const char **input, int *index)
{
	char	current;

	current = (*input)[*index];
	if (ft_isdigit(current))
	{
		ft_putstr_fd("witdth found!\n", 1);
		format->width.exist = YES;
		//process for moving pointer to the dot 
	}
	if ((*input)[*index] == '.')
	{
		current = (*input)[++(*index)];
		format->percision.exist = YES;
		if (ft_isdigit(current))
			ft_putstr_fd("percision found!\n", 1);
		else
			format->percision.value = 0;
	}
	if (current == STRING || current == CHARACTER || current == INTEGER || current == UNSIGNED_INTEGER || current == HEX_LOWCASE || current == HEX_UPCASE || current == PERCENT)
		format->type = current;
	else
		return (0);
	return (1);
}

//this function will set a format struct into default values
void	reset_format(t_format *format)
{
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
int	parse_input(const char *input, va_list argp)
{
	int	print_len;
	int	i;
	t_format format;

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
	res = parse_input(input, argp);
	va_end(argp);
	return (res);
}
#include <stdio.h>
int	main()
{
	//ft_printf("hello%s");
	//printf("|%8.1d|\n", 1234);
	return 0;
}
