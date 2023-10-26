/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_util.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 10:52:23 by truello           #+#    #+#             */
/*   Updated: 2023/10/26 11:42:26 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static t_bool	ft_is_printable(char c)
{
	return (c >= 32 && c < 127);
}

void	ft_putchar(char c)
{
	if (ft_is_printable(c))
		write(1, &c, 1);
}

void	ft_putstr(const char *str)
{
	while (*str)
		write(1, str++, 1);
}

int	ft_putstrn(const char *str, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		ft_putchar(str[i]);
	return (i);
}
