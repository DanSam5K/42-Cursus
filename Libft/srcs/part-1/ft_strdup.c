/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/14 11:43:51 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/08 15:06:56 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

static size_t	ft_str_len(char const *str)
{
	size_t	i;

	i = 0;
	while (*(str + i))
		i++;
	return (i);
}

char	*ft_strdup(const char *src)
{
	size_t	len;
	char	*dst;
	size_t	i;

	len = ft_str_len(src);
	dst = (char *)malloc((len + 1) * sizeof(char));
	if (dst == NULL)
		return (NULL);
	i = 0;
	while (i < len)
	{
		dst[i] = src[i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	*src;
// 	char	*dst;

// 	src = "Hello";
// 	dst = ft_strdup(src);
// 	printf("%s\n", dst);
// 	free(dst);
// 	return (0);
// }
