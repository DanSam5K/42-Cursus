/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/12 19:29:39 by dansam            #+#    #+#             */
/*   Updated: 2024/07/02 11:59:14 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "libft.h"
#include <stdio.h>

void ft_bzero(void *s, size_t n)
{
	while (n--)
		*(unsigned char *)s++ = '\0';
}

// int main(void)
// {
// 	char str[] = "Hello, World!";
// 	size_t len = 6;

// 	printf("Before bzero: \"%s\"\n", str);
// 	ft_bzero(str, len);
// 	printf("After bzero: \"%s\"\n", str);
// 	return (0);
// }