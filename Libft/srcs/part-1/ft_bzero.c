/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 21:33:20 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/06 21:40:34 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

void	ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = '\0';
}

// #include <stdio.h>
// int	main(void)
// {
// 	char	str[10] = "Hello";
// 	int		i;

// 	i = 0;
// 	ft_bzero(str, 5);
// 	while (i < 5)
// 	{
// 		printf("%c", str[i]);
// 		i++;
// 	}
// 	printf("\n");
// 	return (0);
// }
