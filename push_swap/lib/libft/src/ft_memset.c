/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:56:46 by dsamuel           #+#    #+#             */
/*   Updated: 2024/06/11 21:12:16 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *str, int c, size_t n)
{
	size_t	str_ptr;

	str_ptr = 0;
	while (str_ptr < n)
	{
		((unsigned char *)str)[str_ptr] = c;
		str_ptr++;
	}
	return (str);
}
