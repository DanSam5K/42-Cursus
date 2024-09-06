/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:45:42 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/06 22:21:52 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

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

// #include <stdio.h>
// #include <string.h>
// int main()
// {
// 	char src[] = "GeeksforGeeks";
// 	char dest[100];
// 	ft_memcpy(dest, src, strlen(src)+1);
// 	printf("Copied string is %s", dest);
// 	return 0;
// }
