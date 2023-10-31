/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util2.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 11:10:31 by truello           #+#    #+#             */
/*   Updated: 2023/10/31 16:36:53 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/* Choose the len or the precision for printing */
int	lop(int len, int precision)
{
	if (precision == -1)
		return (len);
	return (max(len, precision));
}

int	get_zeros(int precision, int print_len)
{
	if (precision == -1)
		return (0);
	return (max(precision - print_len, 0));
}

void	right_padding(t_format *format, int *len, int zeros)
{
	int	len1;

	len1 = *len;
	if (!has_flag('-', format))
		*len += print_padding(format, format->width - len1 - zeros);
}

void	left_padding(t_format *format, int *len, int zeros)
{
	int	len1;

	len1 = *len;
	if (has_flag('-', format))
		*len += print_padding(format, format->width - len1 - zeros);
}
