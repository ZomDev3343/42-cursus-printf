/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:29:26 by truello           #+#    #+#             */
/*   Updated: 2023/10/19 17:23:33 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	get_precision(const char *str, va_list	*args, int *len_buf)
{
	long int	res;
	long int	res_cpy;
	int			i;

	i = 1;
	res = 0;
	if (str[i] == '*')
	{
		res = va_arg(*args, long int);
		res_cpy = res;
		while (res_cpy > 0)
		{
			res_cpy /= 10;
			i++;
		}
		*len_buf = i;
		return (res);
	}
	while (ft_is_digit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	*len_buf = i;
	return (res);
}
