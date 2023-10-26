/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: truello <truello@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/19 13:57:43 by truello           #+#    #+#             */
/*   Updated: 2023/10/26 11:42:48 by truello          ###   ########.fr       */
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
int				print_zeros(int amount);
int				max(int a, int b);
int				min(int a, int b);

/* Put utils */

void			ft_putchar(char c);
void			ft_putstr(const char *str);
int				ft_putstrn(const char *str, int n);

/* Conversion utils */

char			*ft_itoa(int n);
int				ft_atoi(const char *str);
char			*hex(size_t n);

/* Printable Types */

int				print_character(t_format *format, int c);
int				print_string(t_format *format, char *str);
int				print_pointer(t_format *format, void *ptr);
int				print_decimal(t_format *format, int n);
int				print_integer(t_format *format, int n);
int				print_unsigned_decimal(t_format *format, unsigned int n);
int				print_hexa_low(t_format *format, unsigned int n);
int				print_hexa_up(t_format *format, unsigned int n);

/* Print Flags */

int				print_padding(t_format *format, int width);
int				print_ox(t_format *format);

/* Util */

unsigned int	get_n_len_base(int n, unsigned int base);
unsigned int	get_n_len(int n);
void			add_flag(char flag, t_format *format);
t_bool			has_flag(char flag, t_format *format);
size_t			ft_strlen(const char *s);

int				lop(int len, int precision);
int				get_zeros(int precision, int print_len);
void			right_padding(t_format *format, int *len, int zeros);
void			left_padding(t_format *format, int *len, int zeros);

#endif
