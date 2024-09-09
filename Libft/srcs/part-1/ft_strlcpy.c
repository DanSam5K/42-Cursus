/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 11:41:15 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/09 22:26:16 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

size_t	ft_strlcpy(char *dst, const char *src, size_t n)
{
	size_t	i;

	i = 0;
	while (*(src + i))
		i++;
	if (!n)
		return (i);
	while (--n && *src)
		*dst++ = *src++;
	*dst = '\0';
	return (i);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	dst[50] = "Hello";
// 	char	src[50] = "World";
// 	size_t	n;

// 	n = 10;
// 	printf("%lu\n", ft_strlcpy(dst, src, n));
// 	return (0);
// }
