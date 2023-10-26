/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:43:12 by truello           #+#    #+#             */
/*   Updated: 2023/10/26 14:57:34 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	get_n_len_base(int n, unsigned int base)
{
	long int		nb;
	unsigned int	res;

	nb = n;
	res = 1;
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

unsigned int	get_n_len(int n)
{
	return (get_n_len_base(n, 10));
}

void	add_flag(char flag, t_format *format)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (format->flags[i] == -1)
		{
			format->flags[i] = flag;
			return ;
		}
		i++;
	}
}

t_bool	has_flag(char flag, t_format *format)
{
	int	i;

	i = 0;
	while (i < 5)
	{
		if (format->flags[i] == flag)
			return (TRUE);
		i++;
	}
	return (FALSE);
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
