/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:44:30 by dansam            #+#    #+#             */
/*   Updated: 2024/06/12 19:45:16 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void *ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char *)dst;
	s = (unsigned char *)src;
	while (n--)
		*d++ = *s++;
	return (dst);
}

// int main(void)
// {
// 	char src[] = "Hello, World!";
// 	char dst[14];
// 	size_t len;

// 	len = 14;
// 	printf("Before memcpy: \"%s\"\n", src);
// 	ft_memcpy(dst, src, len);
// 	printf("After memcpy: \"%s\"\n", dst);
// 	return (0);
// }
