/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 14:00:37 by truello           #+#    #+#             */
/*   Updated: 2023/10/19 16:54:34 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	parse_format(const char *str, va_list *args)
{
	unsigned char	i;
	t_format		format;
	int				total;

	i = 0;
	while (str[i] && !is_specifier(str[i]))
	{
		if (is_flag(str[i]))
			format.flag = str[i];
		else if (is_width(str[i]))
			format.width = str[i];
		else if (is_precision(str[i]))
			format.precision = get_precision(str + i, args, &(format.p_len));
		i++;
	}
}

int	ft_printf(const char *str, ...)
{
	int		total;
	va_list	args;

	total = 0;
	va_start(args, str);
	while (*str)
	{
		if (*str == '%')
			total += parse_format(str + 1, &args);
		total++;
		str++;
	}
	va_end(args);
	return (total);
}
