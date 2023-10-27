/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:25:41 by truello           #+#    #+#             */
/*   Updated: 2023/10/27 21:59:47 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_atoi(const char *str)
{
	size_t			i;
	long int		r;
	unsigned char	minus_count;

	i = 0;
	r = 0;
	minus_count = 0;
	while (str[i] == ' ' || (str[i] >= '\t' && str[i] <= '\r'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			minus_count = 1;
		i++;
	}
	while (ft_is_digit(str[i]))
	{
		r = r * 10 + (str[i] - '0');
		i++;
	}
	if (minus_count == 1)
		r *= -1;
	return ((int) r);
}

static char	*init_str(int n, unsigned char *minus, size_t *n_len)
{
	char	*r;
	int		len;

	*n_len = 0;
	*minus = 0;
	if (n < 0)
		*minus = 1;
	while (n != 0)
	{
		(*n_len)++;
		n /= 10;
	}
	len = *n_len + *minus + (*n_len == 0);
	r = (char *) malloc(len + 1);
	if (!r)
		return (0);
	r[len] = '\0';
	if (*minus)
		r[0] = '-';
	return (r);
}

char	*ft_itoa(int n)
{
	long int		nbr;
	size_t			i;
	size_t			n_len;
	char			*r;
	unsigned char	minus;

	nbr = n;
	i = 0;
	r = init_str(n, &minus, &n_len);
	if (!r)
		return (0);
	if (minus == 1)
		nbr *= -1;
	if (n_len == 0)
		r[0] = '0';
	while (i < n_len)
	{
		r[minus + n_len - i - 1] = '0' + nbr % 10;
		nbr /= 10;
		i++;
	}
	return (r);
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
	{
		i = -1;
		n *= -1;
		while (++i < 8)
			res[i] = 'f';
	}
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
