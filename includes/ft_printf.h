#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>

//Types and structs
# define YES 1
# define NO 0

//struct to store format types
typedef struct s_format
{
	va_list	args;
	int		sign;
	int		prc;
	int		dot;
	int		minus;
	int		count;
	int		width;
	int		spc;
	int		zero;
	int		cap_x;
	int		hash;
}	t_format;

//the functions
//parsing and populating input
int		ft_printf(const char *input, ...);

//processing format
void	process_char(t_format *flags);
void	process_str(t_format *flags);
void	process_ptr(t_format *flags);
void	process_dec(t_format *flags);
void	process_u(t_format *flags);
void	process_x(t_format *flags);

//printint format
void	print_char(t_format *flags);
void	print_char_wdt(t_format *flags);
void	print_char_wdt_minus(t_format *flags);
void	print_ptr(t_format *flags);
void	print_dec(t_format *flags);

//utils
void	ft_putnbr_fd_long(unsigned int num, int fd);
char	*ft_rev(char *str);
int		is_in_enum(char c);
char	*ft_itoa_base16(unsigned long long num);
void	ft_putnchar_fd(char c, int n, int fd);
char	*ft_itoa_long(long long num);

#endif