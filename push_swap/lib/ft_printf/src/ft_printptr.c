/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printptr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:34:27 by dsamuel           #+#    #+#             */
/*   Updated: 2024/07/10 16:08:35 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Func to print hexadecimal address recursively
void	ft_print_adr(unsigned long int n)
{
	if (n >= 16)
	{
		ft_print_adr(n / 16);
		ft_print_adr(n % 16);
	}
	else
	{
		if (n < 10)
			ft_print_c(n + '0');
		else
			ft_print_c((n - 10) + 'a');
	}
}

// Func to print a pointer address
int	ft_print_p(unsigned long int n)
{
	int	printed_chars;

	printed_chars = 0;
	if (n == 0)
	{
		printed_chars += ft_print_s(PTRNULL);
		return (printed_chars);
	}
	printed_chars += ft_print_s("0x");
	ft_print_adr(n);
	printed_chars += ft_ptr_len(n);
	return (printed_chars);
}

// Func to print a pointer with flags and width adjustments
int	ft_print_ptr(unsigned long int n, t_flags flags)
{
	int	printed_chars;

	printed_chars = 0;
	if (n == 0)
		flags.width -= ft_strlen(PTRNULL) - 1;
	else
		flags.width -= 2;
	if (flags.left == 1)
		printed_chars += ft_print_p(n);
	printed_chars += ft_pad_width(flags.width, ft_ptr_len(n), 0);
	if (flags.left == 0)
		printed_chars += ft_print_p(n);
	return (printed_chars);
}
