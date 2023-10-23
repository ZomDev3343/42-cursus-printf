/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/20 18:25:41 by truello           #+#    #+#             */
/*   Updated: 2023/10/20 18:37:49 by truello          ###   ########.fr       */
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
