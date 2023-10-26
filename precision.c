/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:29:26 by truello           #+#    #+#             */
/*   Updated: 2023/10/25 15:17:40 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_num(const char *str, va_list	*args)
{
	int			res;
	int			i;

	i = 0;
	res = 0;
	if (str[i] == '*')
		return (va_arg(*args, int));
	while (ft_is_digit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	return (res);
}

int	print_zeros(int amount)
{
	int	i;

	i = -1;
	while (++i < amount)
		ft_putchar('0');
}

int	max(int a, int b)
{
	if (a >= b)
		return (a);
	else
		return (b);
}

int	min(int a, int b)
{
	if (a <= b)
		return (a);
	else
		return (b);
}
