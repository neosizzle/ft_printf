#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//Types and structs
#define YES 1
#define NO 0

//struct to store either width or percision values
typedef struct s_wpvalue
{
	short	exist;
	int		value;
}	t_wpvalue;

//enum to store the format types
typedef enum e_format_type
{
	TBC = -1,
	STRING = 's',
	CHARACTER = 'c',
	INTEGER = 'd',
	UNSIGNED_INTEGER = 'u',
	HEX_LOWCASE = 'x',
	HEX_UPCASE = 'X',
	PERCENT = '%',
}				t_format_type;

//struct to store the current format
typedef struct s_format
{
	t_wpvalue		width;
	t_wpvalue		percision;
	t_format_type	type;
}	t_format;

//the functions
//parsing and populating input
int		ft_printf(const char *input, ...);
int		parse_input(const char *format, va_list argp);
int		populate_format(t_format *format, const char **input, int *index);
void	reset_format(t_format *format);

//processing format
void	process_format(t_format format, int *print_len, va_list argp);

#endif