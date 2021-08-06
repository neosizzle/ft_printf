#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//Types and structs
# define YES 1
# define NO 0

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
	POINTER = 'p',
	INTEGER = 'i',
	DECIMAL = 'd',
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
int		parse_input(char *format, va_list argp);
int		populate_format(t_format *format, char **input, int *index);
void	reset_format(t_format *format);

//processing format
void	process_format(t_format format, int *print_len, va_list argp);
void	ft_handle_width(int	*print_len, int width, int is_space);
void	ft_handle_percision(int *print_len, long num, int percision);
void	ft_handlestr(int *print_len, t_format format, va_list argp);
void	ft_handlechar(int *print_len, t_format format, va_list argp);
void	ft_handlepointer(int *print_len, t_format format, va_list argp);
void	ft_handleint(int *print_len, t_format format, va_list argp);
void	ft_handle_unsigned(int *print_len, t_format format, va_list argp);
void	ft_handlehex(int *print_len, t_format format, va_list argp);

//utils
int		ft_move_atoi(char **input, int *i);
int		ft_min(int a, int b);
int		get_num_len(unsigned long num);
int		get_num_len_base(unsigned int num, int base);
void	generate_addr_str(unsigned long addr, char *hex, int count, int *print_len);
char	*ft_itoa_len(int num, int *print_len);
char	*ft_itoa_base(unsigned int num, char *encode, int len, int base);

#endif