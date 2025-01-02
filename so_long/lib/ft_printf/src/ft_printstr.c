/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printstr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 14:56:40 by dsamuel           #+#    #+#             */
/*   Updated: 2024/07/10 17:20:39 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Func to print a string with precision and width adjustments
static int	ft_print_string(const char *str, t_flags flags)
{
	int	printed_chars;

	printed_chars = 0;
	if (flags.precision >= 0)
	{
		printed_chars += ft_pad_width(flags.precision, ft_strlen(str), 0);
		printed_chars += ft_print_s_precision(str, flags.precision);
	}
	else
		printed_chars += ft_print_s_precision(str, ft_strlen(str));
	return (printed_chars);
}

// Func to print a string with flags and width adjustments
int	ft_print_str(const char *str, t_flags flags)
{
	int	printed_chars;

	printed_chars = 0;
	if (str == NULL && flags.precision >= 0 && flags.precision < 6)
	{
		printed_chars += ft_pad_width(flags.width, 0, 0);
		return (printed_chars);
	}
	if (str == NULL)
		str = "(null)";
	if (flags.precision >= 0 && (size_t)flags.precision > ft_strlen(str))
		flags.precision = ft_strlen(str);
	if (flags.left == 1)
		printed_chars += ft_print_string(str, flags);
	if (flags.precision >= 0)
		printed_chars += ft_pad_width(flags.width, flags.precision, 0);
	else
		printed_chars += ft_pad_width(flags.width, ft_strlen(str), 0);
	if (flags.left == 0)
		printed_chars += ft_print_string(str, flags);
	return (printed_chars);
}

// Func to print a string with specified precision
int	ft_print_s_precision(const char *str, int precision)
{
	int	printed_chars;

	printed_chars = 0;
	while (str[printed_chars] && printed_chars < precision)
		write(1, &str[printed_chars++], 1);
	return (printed_chars);
}

// Function to print a string
int	ft_print_s(const char *str)
{
	int	len;

	if (str == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = 0;
	while (str[len])
		len++;
	write(1, str, len);
	return (len);
}
