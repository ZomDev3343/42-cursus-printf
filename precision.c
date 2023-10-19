/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:29:26 by truello           #+#    #+#             */
/*   Updated: 2023/10/19 16:53:23 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

long int	get_precision(const char *str, va_list	*args, int *len_buf)
{
	long int	res;
	int			i;

	i = 0;
	res = 0;
	if (*(str + 1) == '*')
		return (va_arg(args, long int));
	while (ft_is_digit(str[i]))
	{
		res = res * 10 + str[i] - '0';
		i++;
	}
	*len_buf = i + 1;
	return (res);
}
