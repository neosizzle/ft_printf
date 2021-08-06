#include "ft_printf.h"

void	toggle_width(t_format *format, char **input, int *index)
{
	format->width.exist = YES;
	format->width.value = ft_move_atoi(input, index);
}

void	toggle_zero(t_format *format, int *index)
{
	if (!format->is_minus)
		format->is_space = NO;
	++(*index);
}

void	toggle_minus(t_format *format, int *index)
{
	format->is_minus = YES;
	++(*index);
}

void	wri_wid_num(t_format format, char *n_str, int n_len, int *p_l)
{
	write(1, n_str, n_len);
	if (format.width.exist)
		ft_handle_width(p_l, format.width.value - n_len, format.is_space);
}