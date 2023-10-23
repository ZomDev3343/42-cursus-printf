/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:30:40 by truello           #+#    #+#             */
/*   Updated: 2023/10/23 17:08:29 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	newformat(void)
{
	t_format	format;
	int			i;

	format.specifier = -1;
	i = -1;
	while (++i < 5)
		format.flags[i] = -1;
	format.width = -1;
	format.precision = -1;
	return (format);
}
