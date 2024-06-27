/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:32:27 by dansam            #+#    #+#             */
/*   Updated: 2024/06/12 19:35:18 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memmove(void *dst, const void *src, size_t len)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	if (d < s)
		while (len--)
			*d++ = *s++;
	else
	{
		d += len;
		s += len;
		while (len--)
			*--d = *--s;
	}
	return (dst);
}

// int main(void)
// {
// 	char src[] = "Hello, World!";
// 	char dst[14];
// 	size_t len;

// 	len = 14;
// 	printf("Before memmove: \"%s\"\n", src);
// 	ft_memmove(dst, src, len);
// 	printf("After memmove: \"%s\"\n", dst);
// 	return (0);
// }