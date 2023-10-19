/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 16:04:06 by truello           #+#    #+#             */
/*   Updated: 2023/10/19 16:54:24 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_bool	is_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i'
		|| c == 'u' || c == 'x' || c == 'X' || c == '%');
}

t_bool	is_flag(char c)
{
	return (c == '-' || c == '0' || c == '#' || c == ' ' || c == '+');
}

t_bool	is_width(char c)
{
	return (c == '*' || ft_is_digit(c));
}

t_bool	is_precision(char c)
{
	return (c == '.');
}

t_bool	ft_is_digit(char c)
{
	return (c >= '0' && c <= '9');
}
