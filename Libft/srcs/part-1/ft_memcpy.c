/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:45:42 by dsamuel           #+#    #+#             */
/*   Updated: 2024/06/12 20:21:53 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*dest_s;
	unsigned char	*src_s;

	if (!dest && !src)
		return (dest);
	dest_s = (unsigned char *)dest;
	src_s = (unsigned char *)src;
	while (n--)
		*dest_s++ = *src_s++;
	return (dest);
}
