/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:42:43 by dsamuel           #+#    #+#             */
/*   Updated: 2024/08/09 20:41:09 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h>
# include <limits.h>
# include <stdint.h>
# include <stddef.h>
# include "libft.h"

# define PTRNULL "(nil)"

/* ---------- FLAGS --------------------- */
typedef struct s_flags
{
	int	spec;
	int	width;
	int	left;
	int	zero;
	int	star;
	int	precision;
	int	hash;
	int	space;
	int	plus;
}		t_flags;

t_flags	ft_flags_init(void);
t_flags	ft_flag_left(t_flags flags);
t_flags	ft_flag_digit(char c, t_flags flags);
t_flags	ft_flag_width(va_list args, t_flags flags);
int		ft_flag_precision(const char *str, int pos,
			va_list args, t_flags *flags);

/* ---------- PRINTF -------------------- */
int		ft_printf(const char *format, ...);
int		ft_print_arg(char type, va_list args, t_flags flags);
int		ft_parse_flags(const char *str, int i, va_list args, t_flags *flags);

/* ---------- PRINT SPECIFIERS chars---------- */
int		ft_print_char(char c, t_flags flags);
int		ft_print_c(char c);

/* ---------- FT_PRINTF SPECIFIERS s ----------------- */
int		ft_print_str(const char *str, t_flags flags);
int		ft_print_s(const char *str);
int		ft_print_s_precision(const char *str, int precision);
int		ft_print_sign_precision(int n, t_flags *flags);

/* ---------- FT_PRINT_INT SPECIFIERS d and i--------------- */
int		ft_print_int(int n, t_flags flags);
int		ft_print_integer(char *nbstr, int n, t_flags flags);
int		ft_print_i(char *nbstr, int n, t_flags flags);

/* ---------- FT_PRINT_UNSIGNED SPECIFIERS u---------- */
int		ft_print_unsigned(unsigned n, t_flags flags);
int		ft_print_u(char *nbstr, t_flags flags);
int		ft_print_unint(char *nbstr, t_flags flags);

/* ---------- FT_PRINT_HEX SPECIFIERS x and X---------------- */
int		ft_print_hex(unsigned int n, int is_upper, t_flags flags);
int		ft_print_x(char *nbstr, int n, int is_upper, t_flags flags);
int		ft_print_hexadec(char *nbstr, int n, int is_upper, t_flags flags);

/* ---------- FT_PRINTF SPECIFIERS p----------------- */
int		ft_print_ptr(unsigned long int n, t_flags flags);
int		ft_print_p(unsigned long int n);
void	ft_print_adr(unsigned long int n);

/* ---------- HELPER FUNCTIONS ---------- */
char	*ft_printf_itoa(long nb);
char	*ft_printf_utoa(unsigned int nb);
char	*ft_printf_xtoa(unsigned long num, int is_upper);
int		ft_unint_len(unsigned int n);
int		ft_hex_len(unsigned int n);
int		ft_ptr_len(unsigned long int n);
int		ft_istype(int c);
int		ft_isspec(int c);
int		ft_isflag(int c);

/* ---------- FLAG FUNCTIONS ------------ */
int		ft_pad_width(int total_width, int size, int zero);

#endif
