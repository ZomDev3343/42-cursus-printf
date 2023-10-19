/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:57:43 by truello           #+#    #+#             */
/*   Updated: 2023/10/19 16:53:51 by truello          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdarg.h>
# include <stdlib.h>

typedef unsigned char	t_bool;

# define TRUE 1
# define FALSE 0

typedef struct s_format
{
	char		specifier;
	char		flag;
	char		width;
	long int	precision;
	int			p_len;

}	t_format(-1, -1, -1, -1, 0);

int			ft_printf(const char *str, ...);

/* Format */

t_bool		is_specifier(char c);
t_bool		is_flag(char c);
t_bool		is_width(char c);
t_bool		is_precision(char c);
t_bool		ft_is_digit(char c);

/* Precision */

long int	get_precision(const char *str);

#endif
