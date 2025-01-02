/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printchar.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:48:26 by dsamuel           #+#    #+#             */
/*   Updated: 2024/07/12 15:52:10 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// print character to stdout
int	ft_print_c(char c)
{
	write(1, &c, 1);
	return (1);
}

int	ft_pad_width(int total_width, int content_size, int pad_zero)
{
	int	printed_chars;

	printed_chars = 0;
	while (total_width - content_size > 0)
	{
		if (pad_zero)
			printed_chars += ft_print_c('0');
		else
			printed_chars += ft_print_c(' ');
		total_width--;
	}
	return (printed_chars);
}

int	ft_print_char(char c, t_flags flags)
{
	int	printed_chars;

	printed_chars = 0;
	if (flags.left == 1)
		printed_chars += ft_print_c(c);
	if (c != '%')
		printed_chars += ft_pad_width(flags.width, 1, flags.zero);
	if (c == '%' && flags.width > 1 && flags.zero == 0 && flags.precision == -1
		&& flags.spec != '%')
		printed_chars += ft_pad_width(flags.width - 1, 0, flags.zero);
	if (flags.left == 0)
		printed_chars += ft_print_c(c);
	return (printed_chars);
}
