/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dsamuel <dsamuel@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 20:36:16 by dsamuel           #+#    #+#             */
/*   Updated: 2024/06/12 21:35:49 by dsamuel          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char	*dst_s;
	unsigned char	*src_s;

	dst_s = (unsigned char *)dst;
	src_s = (unsigned char *)src;
	if (!dst && !src)
		return (dst);
	if (dst_s < src_s)
		while (len--)
			*dst_s++ = *src_s++;
	else
	{
		dst_s += len;
		src_s += len;
		while (len--)
			*--dst_s = *--src_s;
	}
	return (dst);
}
