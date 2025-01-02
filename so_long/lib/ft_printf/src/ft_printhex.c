/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printhex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:56:09 by dsamuel           #+#    #+#             */
/*   Updated: 2024/07/10 14:57:06 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Func to print hexadec prefix based on case (upper/lower)
int	ft_print_x_prefix(int is_upper)
{
	if (is_upper == 1)
		ft_print_s("0X");
	else
		ft_print_s("0x");
	return (2);
}

// Funct to print hexadec number with flags
int	ft_print_x(char *nbstr, int n, int is_upper, t_flags flags)
{
	int	printed_chars;

	printed_chars = 0;
	if (flags.zero == 0 && flags.hash == 1 && n != 0)
		printed_chars += ft_print_x_prefix(is_upper);
	if (flags.precision >= 0)
		printed_chars += ft_pad_width(flags.precision - 1,
				ft_strlen(nbstr) - 1, 1);
	printed_chars += ft_print_s(nbstr);
	return (printed_chars);
}

// Func to handle width padding and flag adjustments for hexadec printing
int	ft_print_hexadec(char *nbstr, int n, int is_upper, t_flags flags)
{
	int	printed_chars;

	printed_chars = 0;
	if (flags.zero == 1 && flags.hash == 1 && n != 0)
		printed_chars += ft_print_x_prefix(is_upper);
	if (flags.left == 1)
		printed_chars += ft_print_x(nbstr, n, is_upper, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nbstr))
		flags.precision = ft_strlen(nbstr);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		printed_chars += ft_pad_width(flags.width, 0, 0);
	}
	else
		printed_chars += ft_pad_width(flags.width,
				ft_strlen(nbstr) + (flags.hash * 2), flags.zero);
	if (flags.left == 0)
		printed_chars += ft_print_x(nbstr, n, is_upper, flags);
	return (printed_chars);
}

// // Func to print an unsigned integer in hexadecimal format
int	ft_print_hex(unsigned int n, int is_upper, t_flags flags)
{
	char	*nbstr;
	int		printed_chars;

	printed_chars = 0;
	if (flags.precision == 0 && n == 0)
	{
		printed_chars += ft_pad_width(flags.width, 0, 0);
		return (printed_chars);
	}
	nbstr = ft_printf_xtoa(n, is_upper);
	if (!nbstr)
		return (0);
	printed_chars += ft_print_hexadec(nbstr, n, is_upper, flags);
	free(nbstr);
	return (printed_chars);
}
