/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:02:30 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/06 22:06:13 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)((const char *)s + i));
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	str[10] = "Hello";
// 	char	*ptr;

// 	ptr = ft_memchr(str, 'a', 5);
// 	if (ptr)
// 		printf("Character found: %c\n", *ptr);
// 	else
// 		printf("Character not found\n");
// 	return (0);
// }
