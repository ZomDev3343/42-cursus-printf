/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   format_2.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 17:30:40 by truello           #+#    #+#             */
/*   Updated: 2023/10/19 17:32:59 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

t_format	newformat(void)
{
	t_format	format;
	
	format.specifier = -1;
	format.flag = -1;
	format.width = -1;
	format.precision = 0;
	format.p_len = 0;
	return (format);
}
