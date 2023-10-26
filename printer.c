/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:46:39 by truello           #+#    #+#             */
/*   Updated: 2023/10/26 14:58:51 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_character(t_format *format, int c)
{
	int	print_len;

	print_len = 1;
	if (!has_flag('-', format))
		print_len += print_padding(format, format->width - 1);
	ft_putchar((char) c);
	if (has_flag('-', format))
		print_len += print_padding(format, format->width - 1);
	return (print_len);
}

int	print_string(t_format *format, char *s)
{
	int		print_len;
	size_t	s_len;

	s_len = ft_strlen(s);
	if (format->precision > 0)
		s_len = min(s_len, format->precision);
	print_len = s_len;
	if (!has_flag('-', format))
		print_len += print_padding(format, format->width - s_len);
	ft_putstrn(s, s_len);
	if (has_flag('-', format))
		print_len += print_padding(format, format->width - s_len);
	return (print_len);
}

int	print_pointer(t_format *format, void *ptr)
{
	char	*hex_ptr;
	int		len;
	int		zeros;

	len = 2;
	hex_ptr = hex((size_t) ptr);
	len += lop(ft_strlen(hex_ptr), format->precision);
	zeros = get_zeros(format->precision, ft_strlen(hex_ptr));
	right_padding(format, &len, zeros);
	ft_putstr("0x");
	if (format->precision == 0 && !ptr)
		return (2);
	print_zeros(zeros);
	ft_putstrn(hex_ptr, lop(ft_strlen(hex_ptr), format->precision));
	free(hex_ptr);
	left_padding(format, &len, zeros);
	return (len + zeros);
}

int	print_decimal(t_format *format, int n)
{
	int	len;
	int	zeros;

	len = lop(get_n_len(n) - 1, format->precision);
	zeros = get_zeros(format->precision, get_n_len(n) - 1);
	right_padding(format, &len, zeros);
	if (format->precision == 0 && n == 0)
		return (0);
	len += print_sign(format, n);
	print_zeros(zeros);
	ft_putnbrn(n, lop(get_n_len(n) - 1, format->precision));
	left_padding(format, &len, zeros);
	return (len + zeros + (n == 0));
}
