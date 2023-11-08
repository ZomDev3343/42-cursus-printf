/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:46:39 by truello           #+#    #+#             */
/*   Updated: 2023/11/02 15:58:50 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_character(t_format *format, int c)
{
	int	print_len;

	print_len = 1;
	right_padding(format, &print_len, 0);
	ft_putchar((char) c);
	left_padding(format, &print_len, 0);
	return (print_len);
}

int	print_string(t_format *format, char *s)
{
	int		print_len;
	size_t	s_len;

	if (!s)
		s = "(null)";
	s_len = ft_strlen(s);
	if (format->precision >= 0)
		s_len = min(s_len, format->precision);
	print_len = s_len;
	right_padding(format, &print_len, 0);
	ft_putstrn(s, s_len);
	left_padding(format, &print_len, 0);
	return (print_len);
}

int	print_pointer(t_format *format, void *ptr)
{
	char	*hex_ptr;
	int		len;
	int		zeros;

	len = 2;
	hex_ptr = hex((unsigned long) ptr, get_n_len_base((unsigned long) ptr, 16));
	if (!hex_ptr)
		return (0);
	len += lop(ft_strlen(hex_ptr), format->precision);
	zeros = get_zeros(format->precision, ft_strlen(hex_ptr));
	right_padding(format, &len, zeros);
	ft_putstr("0x");
	if (format->precision == 0 && !ptr)
	{
		free(hex_ptr);
		return (2);
	}
	print_zeros(zeros);
	ft_putstrn(hex_ptr, lop(ft_strlen(hex_ptr), format->precision));
	free(hex_ptr);
	left_padding(format, &len, zeros);
	return (len);
}

int	print_decimal(t_format *format, int n)
{
	int	len;
	int	zeros;

	len = get_sn_len(n);
	zeros = get_zeros(format->precision, get_sn_len(n));
	if (format->precision == 0 && n == 0)
		return (((format->width > -1) * format->width));
	len += (n < 0) || has_flag('+', format);
	right_padding(format, &len, zeros);
	print_sign(format, n);
	if (n >= 0 && has_flag(' ', format))
	{
		ft_putchar(' ');
		len++;
	}
	zero_padding(format, &len, zeros);
	print_zeros(zeros);
	ft_putnbrn(n, get_sn_len(n));
	left_padding(format, &len, zeros);
	return (len + zeros);
}

int	print_unsigned_decimal(t_format *format, unsigned int n)
{
	int	len;
	int	zeros;

	len = get_n_len((unsigned int)n);
	zeros = get_zeros(format->precision, get_n_len(n));
	right_padding(format, &len, zeros);
	zero_padding(format, &len, zeros);
	if (format->precision == 0 && n == 0)
		return (0);
	print_zeros(zeros);
	ft_putnbrn(n, get_n_len(n));
	left_padding(format, &len, zeros);
	return (len + zeros);
}
