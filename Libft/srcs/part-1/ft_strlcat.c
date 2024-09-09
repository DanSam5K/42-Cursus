/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 21:39:38 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/09 21:49:01 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_index;

	if (dstsize <= ft_strlen(dst))
		return (dstsize + ft_strlen(src));
	dst_len = ft_strlen(dst);
	src_index = 0;
	while (src[src_index] != '\0' && dst_len + 1 < dstsize)
	{
		dst[dst_len] = src[src_index];
		dst_len++;
		src_index++;
	}
	dst[dst_len] = '\0';
	return (ft_strlen(dst) + ft_strlen(&src[src_index]));
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	dst[50] = "Hello";
// 	char	src[50] = "World";
// 	size_t	dstsize;

// 	dstsize = 10;
// 	printf("%lu\n", ft_strlcat(dst, src, dstsize));
// 	return (0);
// }
