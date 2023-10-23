/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:29:26 by truello           #+#    #+#             */
/*   Updated: 2023/10/23 16:47:15 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	parse_num(const char *str, va_list	*args)
{
	int	res;
	int	res_cpy;
	int			i;

	i = 1;
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
