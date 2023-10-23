/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:57:43 by truello           #+#    #+#             */
/*   Updated: 2023/10/23 16:57:43 by truello          ###   ########.fr       */
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
	char		flags[5];
	int			width;
	int			precision;
}	t_format;

int			ft_printf(const char *str, ...);

/* Format */

t_bool		is_specifier(char c);
t_bool		is_flag(char c);
t_bool		is_width(char c);
t_bool		is_precision(char c);
t_bool		ft_is_digit(char c);

t_format	newformat(void);

/* Precision */

int	parse_num(const char *str, va_list *args);

/* Put utils */

void		ft_putchar(char c);
void		ft_putstr(const char *str);

/* Conversion utils */

char	*ft_itoa(int n);
int		ft_atoi(const char *str);

/* Printable Types */

int			print_character(t_format *format, signed int c);
int			print_string(t_format *format, char *str);
int			print_pointer(t_format *format, void *ptr);
int			print_decimal(t_format *format, signed int n);
int			print_integer(t_format *format, signed int n);
int			print_unsigned_decimal(t_format *format, unsigned int n);
int			print_hexa_low(t_format *format, unsigned int n);
int			print_hexa_up(t_format *format, unsigned int n);

/* Util */

unsigned int	get_n_len(int n);
void			add_flag(char flag, t_format *format);
t_bool			has_flag(char flag, t_format *format);

#endif
