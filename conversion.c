/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:25:41 by truello           #+#    #+#             */
/*   Updated: 2023/10/30 11:42:40 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	fill_complementary(char *res, long int *n)
{
	int	i;

	i = -1;
	*n *= -1;
	while (++i < 8)
		res[i] = 'f';
}

char	*hex(long int n, int n_len)
{
	const char	*hex_table = "0123456789abcdef";
	char		*res;
	int			i;

	n_len = get_hex_len(n, n_len);
	res = (char *) malloc(n_len + 1);
	if (!res)
		return (NULL);
	if (n == 0)
		res[0] = '0';
	if (n < 0)
		fill_complementary(res, &n);
	i = 0;
	while (n != 0)
	{
		if (res[i] != 'f' || n % 16 == 0)
			res[n_len - 1 - i] = hex_table[n % 16];
		else
			res[n_len - 1 - i] = hex_table[16 - (n % 16)];
		n /= 16;
		i++;
	}
	return (res);
}

void	ft_strup(char *s)
{
	while (*s)
	{
		if (*s >= 'a' && *s <= 'z')
			*s -= 32;
		s++;
	}
}
