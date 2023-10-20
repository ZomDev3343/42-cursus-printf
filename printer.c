/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printer.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 14:46:39 by truello           #+#    #+#             */
/*   Updated: 2023/10/20 17:55:32 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	print_character(t_format *format, signed int c)
{
	char	ch;

	ch = (char) c;
	ft_putchar(ch);
	return (1);
}
