/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:46:39 by truello           #+#    #+#             */
/*   Updated: 2023/10/25 11:23:11 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_character(t_format *format, int c)
{
	int	print_len;

	print_len = 1;
	if (!has_flag('-', format))
		print_len += print_padding(format, format->width - 1);
	ft_putchar(c);
	if (has_flag('-', format))
		print_len += print_padding(format, format->width - 1);
	return (print_len);
}
