/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 13:43:27 by dsamuel           #+#    #+#             */
/*   Updated: 2024/07/11 22:02:03 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(char type, va_list args, t_flags flags)
{
	int	printed_chars;

	printed_chars = 0;
	if (type == '%')
		printed_chars += ft_print_char('%', flags);
	else if (type == 'c')
		printed_chars += ft_print_char(va_arg(args, int), flags);
	else if (type == 's')
		printed_chars += ft_print_str(va_arg(args, const char *), flags);
	else if (type == 'd' || type == 'i')
		printed_chars += ft_print_int(va_arg(args, int), flags);
	else if (type == 'x')
		printed_chars += ft_print_hex(va_arg(args, unsigned int), 0, flags);
	else if (type == 'X')
		printed_chars += ft_print_hex(va_arg(args, unsigned int), 1, flags);
	else if (type == 'u')
		printed_chars += ft_print_unsigned(va_arg(args, unsigned int), flags);
	else if (type == 'p')
		printed_chars += ft_print_ptr((unsigned long int)va_arg(args, void *),
				flags);
	return (printed_chars);
}

int	ft_parse_flags(const char *str, int i, va_list args, t_flags *flags)
{
	while (str[++i] && ft_isflag(str[i]))
	{
		if (str[i] == '-')
			*flags = ft_flag_left(*flags);
		if (str[i] == '#')
			flags->hash = 1;
		if (str[i] == ' ')
			flags->space = 1;
		if (str[i] == '+')
			flags->plus = 1;
		if (str[i] == '0' && flags->left == 0 && flags->width == 0)
			flags->zero = 1;
		if (str[i] == '.')
			i = ft_flag_precision(str, i, args, flags);
		if (str[i] == '*')
			*flags = ft_flag_width(args, *flags);
		if (ft_isdigit(str[i]))
			*flags = ft_flag_digit(str[i], *flags);
		if (ft_istype(str[i]))
		{
			flags->spec = str[i];
			break ;
		}
	}
	return (i);
}

int	ft_parse(char *str, va_list args)
{
	int		i;
	int		x;
	int		printed_chars;
	t_flags	flags;

	i = -1;
	printed_chars = 0;
	while (str[++i])
	{
		flags = ft_flags_init();
		if (str[i] == '%' && str[i + 1] != '\0')
		{
			x = ft_parse_flags(str, i, args, &flags);
			if (flags.spec > 0)
				i = x;
			if (str[i] != '\0' && flags.spec > 0 && ft_istype(str[i]))
				printed_chars += ft_print_arg(str[i], args, flags);
			else if (str[i] != '\0')
				printed_chars += ft_print_c(str[i]);
		}
		else
			printed_chars += ft_print_c(str[i]);
	}
	return (printed_chars);
}

int	ft_printf(const char *format, ...)
{
	va_list		args;
	int			printed_chars;
	char		*str;

	if (!format || *format == '\0')
		return (0);
	str = ft_strdup(format);
	if (!str || *str == '\0')
		return (0);
	printed_chars = 0;
	va_start(args, format);
	printed_chars = ft_parse(str, args);
	va_end(args);
	free(str);
	return (printed_chars);
}
