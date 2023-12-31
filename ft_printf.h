/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:57:43 by truello           #+#    #+#             */
/*   Updated: 2023/11/08 12:05:04 by truello          ###   ########.fr       */
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

int				ft_printf(const char *str, ...);

/* Format */

t_bool			is_specifier(char c);
t_bool			is_flag(char c);
t_bool			is_width(char c);
t_bool			is_precision(char c);
t_bool			ft_is_digit(char c);

t_format		newformat(void);

/* Precision */

int				parse_num(const char *str, va_list *args);
void			print_zeros(int amount);
int				max(int a, int b);
int				min(int a, int b);

/* Put utils */

void			ft_putchar(char c);
void			ft_putstr(const char *str);
int				ft_putstrn(const char *str, int n);
void			ft_putnbrn(long n, int len);

/* Conversion utils */

char			*hex(unsigned long n, int n_len);
void			ft_strup(char *s);

/* Printable Types */

int				print_character(int c);
int				print_string(char *str);
int				print_pointer(void *ptr);
int				print_decimal(int n);
int				print_integer(int n);
int				print_unsigned_decimal(unsigned int n);
int				print_hexa(unsigned int n, t_bool uppercase);
/* Print Flags */

int				print_padding(int width);
int				print_ox(t_format *format);
int				print_sign(t_format *format, int n);
int				print_zero_padding(int n);

/* Util */

unsigned int	get_n_len_base(unsigned long n, unsigned int base);
unsigned int	get_n_len(unsigned long n);
void			add_flag(char flag, t_format *format);
t_bool			has_flag(char flag, t_format *format);
size_t			ft_strlen(const char *s);

int				lop(int len, int precision);
int				get_zeros(int precision, int print_len);
void			right_padding(t_format *format, int *len, int zeros);
void			left_padding(t_format *format, int *len, int zeros);
int				get_hex_len(int n, int n_len);

unsigned int	get_sn_len(int n);
void			zero_padding(t_format *format, int *len, int zeros);
unsigned int	get_digit_len(const char *s);

#endif
