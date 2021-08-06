#include "ft_printf.h"

void	wri_wid_num(t_format format, char *n_str, int n_len, int *p_l)
{
	write(1, n_str, nlen);
	if (format.width.exist)
		ft_handle_width(p_l, format.width.value - n_len, format.is_space);
}