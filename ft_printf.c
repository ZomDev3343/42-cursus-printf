/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:00:37 by truello           #+#    #+#             */
/*   Updated: 2023/10/26 15:06:56 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	print_format(t_format *format, va_list *args)
{
	if (format->specifier == 'c')
		return (print_character(format, va_arg(*args, int)));
	else if (format->specifier == 's')
		return (print_string(format, va_arg(*args, char *)));
	else if (format->specifier == 'p')
		return (print_pointer(format, va_arg(*args, void *)));
	else if (format->specifier == 'd' || format->specifier == 'i')
		return (print_decimal(format, va_arg(*args, int)));
	else if (format->specifier == 'u')
		return (print_unsigned_decimal(format, va_arg(*args, unsigned int)));
	/*else if (format->specifier == 'x')
		return (print_hexa_low(format, va_arg(*args, unsigned int)));
	else
		return (print_hexa_up(format, va_arg(*args, unsigned int)));
	*/
	return (0);
}

static int	parse_character(const char *s, t_format *format, va_list *args)
{
	if (is_flag(*s))
	{
		add_flag(*s, format);
		return (1);
	}
	else if (is_width(*s))
	{
		format->width = parse_num(s, args);
		if (*s == '*')
			return (1);
		return (get_n_len(format->width) - 1);
	}
	else if (is_precision(*s))
	{
		format->precision = parse_num(s + 1, args);
		if (*s == '*')
			return (1);
		return (1 + get_n_len(format->precision) - 1);
	}
	else
		return (0);
}

static int	parse_format(const char *str, va_list *args, int *total)
{
	unsigned char	i;
	t_format		format;
	int				parse_res;

	i = 0;
	format = newformat();
	while (str[i] && !is_specifier(str[i]))
	{
		if (is_flag(str[i]) && (format.width != -1
				|| format.precision != -1)
			|| is_width(str[i]) && format.precision != -1)
			return (0);
		parse_res = parse_character(str + i, &format, args);
		if (parse_res == 0)
			return (0);
		i += parse_res;
	}
	if (is_specifier(str[i]))
		format.specifier = str[i];
	if (format.specifier == -1)
		return (0);
	*total += print_format(&format, args);
	return (i + 1);
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
			format_len = parse_format(str + 1, &args, &total);
			if (format_len == 0)
				break ;
			str += format_len + 1;
		}
		else
		{
			ft_putchar(*str);
			str += 1 + (*(str) == '%');
			total++;
		}
	}
	va_end(args);
	return (total);
}
