#include "ft_printf.h"
//i keep my utils here

//this func convert a to i and incerments the pointer i 
//by how many digits the conversersion needed
int	ft_move_atoi(char **input, int *i)
{
	int	res;

	res = 0;
	while (ft_isdigit((*input)[*i]))
	{
		res *= 10;
		res += (*input)[*i] - '0';
		(*i)++;
	}
	return (res);
}

//this fun returns the min value of two numbers
int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}

//checks if a char is inside enum
int	is_in_enum(char c)
{
	if (current == STRING
	|| current == CHARACTER
	|| current == POINTER
	|| current == INTEGER
	|| current == DECIMAL
	|| current == UNSIGNED_INTEGER
	|| current == HEX_LOWCASE
	|| current == HEX_UPCASE
	|| current == PERCENT)
		return (1);
	return (0);
}