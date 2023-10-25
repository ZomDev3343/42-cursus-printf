/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 11:43:12 by truello           #+#    #+#             */
/*   Updated: 2023/10/25 11:20:57 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

unsigned int	get_n_len(int n)
{
	long int		nb;
	unsigned int	res;

	nb = n;
	res = 0;
	if (n == 0)
		return (1);
	if (n < 0)
	{
		res++;
		nb *= -1;
	}
	while (nb > 0)
	{
		nb /= 10;
		res++;
	}
	return (res);
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
