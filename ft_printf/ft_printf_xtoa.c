/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_xtoa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 20:16:06 by dsamuel           #+#    #+#             */
/*   Updated: 2024/07/10 13:50:47 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

// Func to calc the length of the string rep in hexadec num
static size_t	ft_xtoa_len(unsigned long num)
{
	size_t	len;

	len = 0;
	if (num == 0)
		return (1);
	while (num > 0)
	{
		len++;
		num /= 16;
	}
	return (len);
}

// Func to convert an unsigned long int to a string rep in hexadec
static char	*ft_hex_to_str(unsigned long num, size_t len, int is_upper)
{
	char	*str;
	char	base_char;

	str = (char *)ft_calloc(len + 1, sizeof(char));
	if (str == NULL)
		return (NULL);
	if (is_upper)
		base_char = 'A' - 10;
	else
		base_char = 'a' - 10;
	while (len > 0)
	{
		len--;
		if ((num % 16) < 10)
			str[len] = (num % 16) + '0';
		else
			str[len] = (num % 16) + base_char;
		num /= 16;
	}
	return (str);
}

// Func to convert an unsigned long integer to a hexadec string rep
char	*ft_printf_xtoa(unsigned long num, int is_upper)
{
	size_t	len;

	len = ft_xtoa_len(num);
	return (ft_hex_to_str(num, len, is_upper));
}
