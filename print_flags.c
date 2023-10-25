/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_flags.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/24 13:50:04 by truello           #+#    #+#             */
/*   Updated: 2023/10/25 11:35:45 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_padding(t_format *format, int width)
{
	int	i;

	i = -1;
	while (++i < width)
	{
		if (has_flag('0', format))
			ft_putchar('0');
		else
			ft_putchar(' ');
	}
	return (i);
}

int	print_ox(t_format *format)
{
	if (has_flag('x', format))
	{
		ft_putstr("0x");
		return (2);
	}
	else if (has_flag('X', format))
	{
		ft_putstr("0X");
		return (2);
	}
	else
		return (0);
}
