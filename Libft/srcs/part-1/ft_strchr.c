/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 10:50:22 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/08 13:37:41 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strchr(const char *s, int c)
{
	unsigned char	uc;

	uc = (unsigned char)c;
	while (*s != '\0')
	{
		if (*s == uc)
			return ((char *)s);
		s++;
	}
	if (uc == '\0')
		return ((char *)s);
	return (0);
}

#include <stdio.h>
int	main(void)
{
	char	str[10] = "Hello";
	char	*ptr;

	ptr = ft_strchr(str, 'a');
	if (ptr)
		printf("Character found: %c\n", *ptr);
	else
		printf("Character not found\n");
	return (0);
}
