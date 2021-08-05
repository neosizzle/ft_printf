#include "ft_printf.h"
//the whole idea is to read through the string, parse the input 
//and process the data if nessacary

//this func will take the format and the argp
//and it will process and print the things 
//by calling specific helper func
void	process_format(t_format format, int *print_len, va_list argp)
{
	if (format.type == STRING)
		ft_handlestr(print_len, format, argp);
	else if (format.type == CHARACTER)
		ft_handlechar(print_len, format, argp);
	else if (format.type == POINTER)
		ft_handlepointer(print_len, format, argp);
}

//this function will populate a format struct according
//to the input. 
//returns 1 if succeed and 0 if it doses not
int	populate_format(t_format *format, char **input, int *index)
{
	char	current;

	current = (*input)[*index];
	if (ft_isdigit(current))
	{
		format->width.exist = YES;
		format->width.value = ft_move_atoi(input, index);
	}
	if ((*input)[*index] == '.')
	{
		current = (*input)[++(*index)];
		format->percision.exist = YES;
		if (ft_isdigit(current))
			format->percision.value = ft_move_atoi(input, index);
		else
			format->percision.value = 0;
	}
	current = (*input)[*index];
	if (current == STRING || current == CHARACTER || current == POINTER || current == INTEGER || current == UNSIGNED_INTEGER || current == HEX_LOWCASE || current == HEX_UPCASE || current == PERCENT)
		format->type = current;
	else
		return (0);
	(*input)++;
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
int	parse_input(char *input, va_list argp)
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
			//va_arg(argp, int);
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

// #include <stdio.h>
// int	main()
// {
// 	//char *s = "vsdfasdfasdf";
// 	//char *s2 = "hjjhjjl";	
// 	//int		d = 2323;
// 	//unsigned int a = 123;
// 	//long g = 234;

// 	int res = ft_printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
// 	printf("\n");
// 	int res2 = printf(" %s %s %s %s %s ", " - ", "", "4", "", "2 ");
// 	printf("\n");
// 	printf("%d\n", res);
// 	printf("%d\n",res2);
// 	//printf("|%8.1d|\n", 1234);
// 	return 0;
// }
