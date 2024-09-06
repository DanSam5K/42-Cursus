/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 20:46:18 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/06 22:09:23 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	str1[10] = "Hello";
// 	char	str2[10] = "Hello";
// 	int		ret;

// 	ret = ft_memcmp(str1, str2, 5);
// 	if (ret == 0)
// 		printf("Strings are equal\n");
// 	else
// 		printf("Strings are not equal\n");
// 	return (0);
// }
