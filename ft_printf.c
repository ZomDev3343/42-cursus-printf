/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:00:37 by truello           #+#    #+#             */
/*   Updated: 2023/10/20 11:54:03 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(t_format *format, va_list *args)
{
	char	specifier;

	specifier = format->specifier;
	if (specifier == 'c')
		return (print_character(format, va_arg(*args, signed int)));
	else if (specifier == 's')
		return (print_string(format, va_arg(*args, char *)));
	else if (specifier == 'p')
		return (print_pointer(format, va_arg(*args, void *)));
	else if (specifier == 'd')
		return (print_decimal(format, va_arg(*args, signed int)));
	else if (specifier == 'i')
		return (print_integer(format, va_arg(*args, signed int)));
	else if (specifier == 'u')
		return (print_unsigned_decimal(format, va_arg(*args, unsigned int)));
	else if (specifier == 'x')
		return (print_hexa_low(format, va_arg(*args, unsigned int)));
	else
		return (print_hexa_up(format, va_arg(*args, unsigned int)));
}

static int	parse_format(const char *str, va_list *args)
{
	unsigned char	i;
	t_format		format;
	int				total;

	i = 0;
	format = newformat();
	while (str[i] && !is_specifier(str[i]))
	{
		if (is_flag(str[i]))
			format.flag = str[i];
		else if (is_width(str[i]))
			format.width = str[i];
		else if (is_precision(str[i]))
		{
			format.precision = get_precision(str + i, args, &(format.p_len));
			i += format.p_len;
		}
		i++;
	}
	if (is_specifier(str[i]))
		format.specifier = str[i];
	if (format.specifier == -1)
		return (0);
	total = print_format(&format, args);
	return (total);
}

int	ft_printf(const char *str, ...)
{
	int		total;
	va_list	args;
	int		format_len;

	total = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%' && *(str + 1) != '%')
		{
			format_len = parse_format(str + 1, &args);
			total += format_len + 1;
			str += format_len + 1;
		}
		else
		{
			ft_putchar(*str);
			str += 1 + (*(str + 1) == '%');
			total += 1 + (*(str + 1) == '%');
		}
	}
	va_end(args);
	return (total);
}
