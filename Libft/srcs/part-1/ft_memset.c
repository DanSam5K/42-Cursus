/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/11 20:56:46 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/07 20:37:03 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"
void	*ft_memset(void *str, int c, size_t n)
{
	size_t	str_ptr;

	str_ptr = 0;
	while (str_ptr < n)
	{
		((unsigned char *)str)[str_ptr] = c;
		str_ptr++;
	}
	return (str);
}

// int main()
// {
// 	char str[50] = "GeeksForGeeks is for programming geeks.";
// 	printf("\nBefore memset(): %s\n", str);
// 	ft_memset(str + 13, '.', 8);
// 	printf("After memset():  %s\n", str);
// 	return 0;
// }