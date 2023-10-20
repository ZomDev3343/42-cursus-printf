/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:52:23 by truello           #+#    #+#             */
/*   Updated: 2023/10/20 17:54:27 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_putchar(char c)
{
	char	ch;

	ch = '\0' + (char) c;
	write(1, &ch, 1);
}

void	ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}
