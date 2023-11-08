/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:43:12 by truello           #+#    #+#             */
/*   Updated: 2023/11/08 12:11:27 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	get_n_len_base(unsigned long n, unsigned int base)
{
	unsigned long	nb;
	unsigned int	res;

	nb = n;
	res = 0;
	if (base == 0)
		return (0);
	if (n == 0)
		return (1);
	if (n < 0)
		nb *= -1;
	while (nb > 0)
	{
		nb /= base;
		res++;
	}
	return (res);
}

unsigned int	get_n_len(unsigned long n)
{
	return (get_n_len_base(n, 10));
}

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i])
		i++;
	return (i);
}
