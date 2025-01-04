/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:20:06 by dsamuel           #+#    #+#             */
/*   Updated: 2024/07/12 16:06:52 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Func to print a number string with flags
int	ft_print_i(char *nbstr, int n, t_flags flags)
{
	int	printed_chars;

	printed_chars = 0;
	if (n < 0)
	{
		if (flags.zero == 0 || flags.precision >= 0)
			printed_chars += ft_print_c('-');
	}
	else if (flags.plus == 1 && flags.zero == 0)
		printed_chars += ft_print_c('+');
	else if (flags.space == 1 && flags.zero == 0)
		printed_chars += ft_print_c(' ');
	if (flags.precision >= 0)
		printed_chars += ft_pad_width(flags.precision - 1,
				ft_strlen(nbstr) - 1, 1);
	printed_chars += ft_print_s(nbstr);
	return (printed_chars);
}

// Func to print the sign of the number based on flags
int	ft_print_sign_precision(int n, t_flags *flags)
{
	int	printed_chars;

	printed_chars = 0;
	if (n < 0 && flags->precision == -1)
	{
		printed_chars += ft_print_c('-');
		flags->width--;
	}
	else if (flags->plus == 1)
		printed_chars += ft_print_c('+');
	else if (flags->space == 1)
	{
		printed_chars += ft_print_c(' ');
		flags->width--;
	}
	return (printed_chars);
}

// Func to print an integer with flags and width adjustments
int	ft_print_integer(char *nbstr, int n, t_flags flags)
{
	int	printed_chars;
	int	pad_width;

	printed_chars = 0;
	if (flags.zero == 1)
		printed_chars += ft_print_sign_precision(n, &flags);
	if (flags.left == 1)
		printed_chars += ft_print_i(nbstr, n, flags);
	if (flags.precision >= 0 && (size_t)flags.precision < ft_strlen(nbstr))
		flags.precision = ft_strlen(nbstr);
	if (flags.precision >= 0)
	{
		flags.width -= flags.precision;
		if (n < 0 && flags.left == 0)
			flags.width -= 1;
		printed_chars += ft_pad_width(flags.width, 0, 0);
	}
	else
	{
		pad_width = flags.width - flags.plus - flags.space;
		printed_chars += ft_pad_width(pad_width, ft_strlen(nbstr), flags.zero);
	}
	if (flags.left == 0)
		printed_chars += ft_print_i(nbstr, n, flags);
	return (printed_chars);
}

// New function to process the number and adjust flags
void	ft_process_number_and_flags(long *nb, t_flags *flags)
{
	if (*nb < 0)
	{
		*nb *= -1;
		if (flags->zero == 0)
			flags->width--;
		if (flags->left == 0 && flags->zero == 0)
			flags->width++;
		if (flags->precision < 0 && flags->left == 0 && flags->zero == 0)
			flags->width--;
	}
}

// Function to print an integer
int	ft_print_int(int n, t_flags flags)
{
	char	*nbstr;
	long	nb;
	int		printed_chars;

	nb = n;
	printed_chars = 0;
	ft_process_number_and_flags(&nb, &flags);
	if (flags.precision == 0 && n == 0)
	{
		printed_chars += ft_pad_width(flags.width, 0, 0);
		return (printed_chars);
	}
	nbstr = ft_printf_itoa(nb);
	if (!nbstr)
		return (0);
	printed_chars += ft_print_integer(nbstr, n, flags);
	free(nbstr);
	return (printed_chars);
}
