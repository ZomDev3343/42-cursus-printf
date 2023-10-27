/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:46:52 by truello           #+#    #+#             */
/*   Updated: 2023/10/27 11:35:46 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"
#include <stdio.h>

int	print_hexa(t_format *format, int n, t_bool uppercase)
{
	char	*hex_n;
	int		len;
	int		zeros;

	hex_n = hex(n, get_n_len_base(n, 16) - 1);
	if (!hex_n)
		return (0);
	if (uppercase)
		ft_strup(hex_n);
	len = ft_strlen(hex_n);
	zeros = get_zeros(format->precision, ft_strlen(hex_n));
	right_padding(format, &len, zeros);
	if (format->precision == 0 && n == 0)
	{
		free(hex_n);
		return (0);
	}
	len += print_ox(format);
	print_zeros(zeros);
	ft_putstrn(hex_n, ft_strlen(hex_n));
	free(hex_n);
	left_padding(format, &len, zeros);
	return (len + zeros);
}
