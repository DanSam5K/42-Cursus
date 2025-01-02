/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_num_len.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 17:21:12 by dsamuel           #+#    #+#             */
/*   Updated: 2024/07/10 12:27:30 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	ft_num_len(unsigned long long n, int base)
{
	int	len;

	len = 0;
	if (n == 0)
		return (1);
	while (n >= 1)
	{
		len++;
		n /= base;
	}
	return (len);
}

int	ft_ptr_len(unsigned long int n)
{
	return (ft_num_len(n, 16));
}

int	ft_unint_len(unsigned int n)
{
	return (ft_num_len(n, 10));
}

int	ft_hex_len(unsigned int n)
{
	return (ft_num_len(n, 16));
}
