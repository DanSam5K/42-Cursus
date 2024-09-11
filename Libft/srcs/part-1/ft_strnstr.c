/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dansam <dansam@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/13 21:28:53 by dsamuel           #+#    #+#             */
/*   Updated: 2024/09/11 11:56:49 by dansam           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t max_len)
{
	size_t	h_index;
	size_t	n_index;

	h_index = 0;
	if (needle[0] == '\0')
		return ((char *)haystack);
	while (haystack[h_index] != '\0' && h_index < max_len)
	{
		n_index = 0;
		while (haystack[h_index + n_index] == needle[n_index]
			&& (h_index + n_index) < max_len)
		{
			if (needle[n_index + 1] == '\0')
				return ((char *)&haystack[h_index]);
			n_index++;
		}
		h_index++;
	}
	return (0);
}

// int main(void)
// {
// 	char	haystack[50] = "Hello World";
// 	char	needle[50] = "World";
// 	size_t	max_len;

// 	max_len = 10;
// 	printf("%s\n", ft_strnstr(haystack, needle, max_len));
// 	return (0);
// }
